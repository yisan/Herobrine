// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// 被控端

#include "tcp_client.h"
#include "type.h"

#ifndef SLAVE_H_
#define SLAVE_H_


class Slave : public TCPClient
{
public:
	Slave();
	~Slave();

	static ushort size();

private:
	os_info		os_;
	user_info user_;

	static ushort size_;	// 实例总数
};


#endif	// SLAVE_H_
