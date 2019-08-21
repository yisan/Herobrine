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

	static	ushort size();

	void		os_info(string&);

	ushort	os_lang();

	ushort	os_mem_total();
	ushort	os_mem_free();
	ushort	os_mem_available();

private:
	char			os_info_[os_info_size];
	user_info user_;

	static ushort size_;	// 实例总数
};


#endif	// SLAVE_H_
