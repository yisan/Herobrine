// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian

#include "print.h"

namespace him
{

vector<string>	arg;	// ����

// �������
void help()
{
	puts(
		"  idletime     ��ȡϵͳ����ʱ��\n"
		"  screenshot   ��Ļ��ȡ\n"
		"  keyscan      ������̽"
	);
}


// ��ȡϵͳ����ʱ��
void idletime()
{

}


// ��Ļ��ȡ
void screenshot()
{

}


// ������̽
void keyscan()
{
	if (arg[1] == "start")			// ��ʼ������̽
	{
	}
	else if (arg[1] == "dump")	// �����̽���
		;
	else if (arg[1] == "stop")	// ֹͣ������̽
		;
	else
	{
		print::err("������Ч");
		return;
	}
}

}
