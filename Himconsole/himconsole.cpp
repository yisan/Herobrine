// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// HIM控制端: 命令行用户接口
// 程序入口

// Windows
// 	cmd::clear()

#include "pch.h"

namespace console
{

ushort hist_size	= 10;	// 命令历史记录上限
deque<string>		hist;		// 历史记录
vector<string>	arg;		// 参数

// 释放资源, 结束程序
void exit()
{
	::exit(0);
}

// 清空屏幕
void clear()
{
	system("cls");
}

// 命令帮助
void help()
{
	if(arg.size() > 2)
	{
		print::err("参数过多");
		return;
	}

	if(arg.size() == 1)
		puts(
			"    命令          描述\n"
			"    ----          ----\n"
			"    clear         清空命令行内容\n"
			"    cls           清空命令行内容\n"
			"    db            操作数据库\n"
			"    exit          退出命令行\n"
			"    help          显示帮助信息\n"
			"    quit          退出命令行\n"
			"    ls            列出Slave\n"
			"    use           打开指定Slave会话"
		);
	else if(arg[1] == "db")
		puts(
			"  db connect <host> <dbname> <username> <password>\n"
			"  db init\n"
			"  db status"
		);
	else
		print::err("暂无该命令的帮助信息");
}

// 命令历史
void history()
{
	ushort i;

	for(i=0; i<hist.size(); i++)
		printf("%-2d %s\n", i, hist[i].c_str());
}

// 数据库
void db()
{
	// 初始化数据库
	if(arg[0] == "init")
	{
	}
}

// 横幅
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
		__DATE__, __TIME__
	);
}


// 命令行
void console()
{
	short i, j;
	short pList, pHist;
	const char* list[] = {	// 命令匹配列表
		"bind",
		"cls",
		"clear",
		"exit",
		"help",
		"history",
		"ls",
		"quit",
		"use"
	};
	ushort list_size = sizeof(list)/sizeof(char*);
	string cmd;					// 命令

	while(true)
	{
		// 输出命令提示符
		_putch('\n');
		attr::underscore();
		printf("him");
		attr::rest();
		printf("> ");

		attr::fore::white();
		attr::fore::light();

		if(hist.size() >= hist_size)	// 历史记录数量达到上限
			hist.pop_back();						// 将最早的记录出队

		cmd.clear();

		pList	= -1;
		pHist	= -1;

		while(true)
		{
			// 读入命令
			cmd += _getch();

			if(cmd.back() == -32 || cmd.back() == 0)	// 功能键
			{
				cmd.pop_back();
				short code = _getch();				// 功能键ASCII代码

				// 上下键 历史命令切换
				if(code == 72)								// 上键 前移历史纪录指针
				{
					if(pHist == hist.size()-1)	// 已经是历史记录尾部
						continue;
					pHist++;
				}

				if(code == 80)								// 下键 后移历史纪录指针
				{
					if(pHist == 0)							// 已经是历史记录头部
						continue;
					pHist--;
				}

				if(code == 72 || code == 80)	// 显示历史记录
				{
					for(i=0; i<cmd.size(); i++)	// 清除已输入的内容
						printf("\b \b");
					printf("%s", hist[pHist].c_str());
					cmd		= hist[pHist];
					continue;
				}

				// 左右键 光标移动
				if(code == 75)	// 左
				;

				if(code == 77)	// 右
				;

				continue;
			}

			// 过滤非法字符
			// TODO: 增加可读性
			if((cmd.back() < 32 && cmd.back() != '\r'
					&& cmd.back() != '\t' && cmd.back() != '\b'
					&& cmd.back() != 27
				) || cmd.back() > 127)
			{
				cmd.pop_back();
				continue;
			}

			// Tab键 补全命令
			if(cmd.back() == '\t')
			{
				cmd.pop_back();
				if(pList == -1)	// 没有匹配项
					continue;
				printf("%s", &list[pList][cmd.size()]);
				cmd += &list[pList][cmd.size()];
				continue;
			}

			// ESC键 清空全部输入
			// 若输入过长导致换行则无能为力
			if(cmd.back() == 27)
			{
				cmd.pop_back();
				for(i=0; i<cmd.size(); i++)
					printf("\b \b");
				continue;
			}

			// Enter键 结束命令读入
			if(cmd.back() == '\r')
			{
				cmd.pop_back();
				_putch('\n');
				break;
			}

			// Backspace键 退格
			if(cmd.back() == '\b')
			{
				cmd.pop_back();
				if(cmd.size() > 0)
				{
					printf("\b \b");
					cmd.pop_back();
				}
			} else {
				_putch(cmd.back());
			}

			// 更新可能的匹配项, 显示标识
			for(i=0; i<list_size; i++)
			{
				// 排除过短的命令
				if(strlen(list[i]) <= cmd.size() && i+1 != list_size)
					continue;

				// 逐字匹配
				for(j=0; j<cmd.size(); j++)
				{
					if(cmd[j] != list[i][j])
						break;
				}

				// 匹配成功
				if(j == cmd.size() && cmd.size() != 0)
				{
					pList = i;
					attr::fore::gray();
					printf("%s", &list[pList][cmd.size()]);
					attr::fore::white();
					attr::fore::light();
					for(j=cmd.size(); j<strlen(list[pList]); j++)
						_putch('\b');
					break;
				}

				// 无匹配项
				if(i+1 == list_size && pList != -1)
				{
					for(j=cmd.size(); j<strlen(list[pList]); j++)
						_putch(' ');
					for(j=cmd.size(); j<strlen(list[pList]); j++)
						_putch('\b');
					pList = -1;
				}
			}

			// 溢出检查
			if(cmd.size() >= cmd.max_size())
			{
				print::err("命令过长");
				break;
			}
		}
		attr::rest();

		// 命令长度为0
		if(cmd.size() == 0)
			continue;

		// 保存到历史记录
		// TODO: 释放hist.front的剩余空间
		hist.push_front(cmd);

		// 分割命令
		char* str = new char[cmd.size()+1];
		strcpy(str, cmd.c_str());

		arg.clear();
		// TODO: 无法识别出双引号括起带空格的参数
		char* pToken = strtok(str, " ");
		while(pToken != NULL)
		{
			arg.push_back(pToken);

			if(arg.size() >= arg.max_size())	// 会溢出
				break;

			pToken = strtok(NULL, " ");
		}
		delete[] str;

		if(arg.size() >= arg.max_size())	// 会溢出
		{
			print::err("参数过多");
			continue;
		}


		if(arg[0] == "exit" || arg[0] == "quit")
			exit();
		else if(arg[0] == "help")
			help();
		else if(arg[0] == "banner")
			banner();
		else if(arg[0] == "cls" || arg[0] == "clear")
			clear();
		else if (arg[0] == "history")
			history();
		else
			print::err("未知命令: "+arg[0]);
	}
}

}	// namespace cmd


// 初始化
void init()
{
	attr::init();
}


int main(int argc, char* argv[])
{
	init();
	console::banner();
	// TODO: 解析参数
	console::console();
	return 0;
}
