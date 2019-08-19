// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian

#include "socket.h"

uint Socket::num_ = 0;

Socket::Socket()
{
	num_++;

	// ���Ϊ��һ��ʵ��
	if(num_ == 1)	// ��ʼ��WSA
	{
		WSADATA	WSAData;
		WSAStartup(MAKEWORD(2, 2), &WSAData);
	}
}

Socket::~Socket()
{
	num_--;

	// ���û��ʵ��
	if(num_ == 0)	// WSA�ͷ�
		WSACleanup();
}
