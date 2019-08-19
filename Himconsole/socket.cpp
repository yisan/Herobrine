// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian

#include "socket.h"

uint Socket::num_ = 0;

Socket::Socket()
{
	num_++;

	// 如果为第一个实例
	if(num_ == 1)	// 初始化WSA
	{
		WSADATA	WSAData;
		WSAStartup(MAKEWORD(2, 2), &WSAData);
	}
}

Socket::~Socket()
{
	num_--;

	// 如果没有实例
	if(num_ == 0)	// WSA释放
		WSACleanup();
}
