// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian

#ifndef SOCKET_H_
#define SOCKET_H_

#include <winsock2.h>
#include "type.h"

// WSA自动初始化和释放
class Socket
{
public:
	Socket();
	~Socket();

private:
	static uint num_;	// socket总数
};

#endif	// SOCKET_H_
