// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// 被控端

#include "type.h"
#include "tcp_client.h"

#ifndef SLAVE_H_
#define SLAVE_H_


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


class Slave
{
public:
	Slave();
	~Slave();

	static ushort size();

private:
	TCPClient	sock;

	os_info		os_;
	user_info	user_;

	static ushort size_;	// 实例总数
};

#endif	// SLAVE_H_
