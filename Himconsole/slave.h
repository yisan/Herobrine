// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// ���ض�

#include "type.h"
#include "tcp_client.h"

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
	user_info	user_;

	static ushort size_;	// ʵ������
};


#endif	// SLAVE_H_
