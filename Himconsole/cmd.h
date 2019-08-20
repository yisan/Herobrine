// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// ����̨����

#ifndef CMD_H_
#define CMD_H_

#include "type.h"

namespace cmd
{

void console();

void banner();
void clear();
void db();
void exit();
void help();
void history();
void listen();
void ls();
void use();

}	// namespace cmd


#if (hist_size > 999)
	#error hist_size��ֵ��������
#endif


#endif	// CMD_H_
