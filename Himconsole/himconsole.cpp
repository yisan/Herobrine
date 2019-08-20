// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// HIM控制端: 命令行用户接口
// 程序入口

#include "cmd.h"
#include "print.h"
#include "slave.h"

int main(int argc, char* argv[])
{
	SetConsoleTitleA("Himconsole");
	cmd::banner();
	// TODO: 解析参数
	cmd::console();
	return 0;
}
