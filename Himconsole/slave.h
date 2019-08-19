// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// 被控端

#include "type.h"
#include "tcp_client.h"

#ifndef SLAVE_H_
#define SLAVE_H_


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
