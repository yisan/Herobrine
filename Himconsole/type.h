// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// 声明/定义各种类型

#ifndef TYPE_H_
#define TYPE_H_


#include <string>
using std::string;
using std::to_string;

#include <vector>
using std::vector;

#include <deque>
using std::deque;


typedef unsigned char		uchar;
typedef unsigned short	ushort;
typedef unsigned int		uint;


// 操作系统的信息
typedef struct
{
	short		type;	// 平台
	string	lang;	// 语言
	struct	mem
	{
		short	total;			// 总数(GB)
		short	free;				// 系统可用(GB)
		short available;	// 应用可用(GB)
	};
} os_info;

// Windows 内核操作系统的信息
typedef struct : os_info
{
	short	majorVer;	// 主版本
	short minorVer;	// 次版本
} os_info_windows;

// Linux 内核操作系统信息
typedef struct : os_info
{;
} os_info_linux;


// 用户的信息
typedef struct {
	ushort	id;
	string	name;
} user_info;


#endif	// TYPE_H_
