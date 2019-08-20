// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian

#include "print.h"

namespace him
{

vector<string>	arg;	// 参数

// 命令帮助
void help()
{
	puts(
		"  idletime     获取系统空闲时间\n"
		"  screenshot   屏幕截取\n"
		"  keyscan      击键嗅探"
	);
}


// 获取系统空闲时间
void idletime()
{

}


// 屏幕截取
void screenshot()
{

}


// 击键嗅探
void keyscan()
{
	if (arg[1] == "start")			// 开始击键嗅探
	{
	}
	else if (arg[1] == "dump")	// 输出嗅探结果
		;
	else if (arg[1] == "stop")	// 停止击键嗅探
		;
	else
	{
		print::err("参数无效");
		return;
	}
}

}
