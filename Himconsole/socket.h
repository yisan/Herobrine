// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// ͳ��socket����

#include "winsock2.h"
#include "type.h"

#ifndef SOCKET_H_
#define SOCKET_H_


// WSA�Զ���ʼ�����ͷ�
class Socket
{
public:
	Socket();
	~Socket();

private:
	static uint num_;	// socket����
};


#endif	// SOCKET_H_
