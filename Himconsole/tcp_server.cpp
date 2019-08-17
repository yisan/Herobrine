// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// Socket TCP �����

#include "tcp_server.h"


TCPServer::TCPServer()
{
	sock_ = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}


TCPServer::~TCPServer()
{
	shutdown(sock_, SD_BOTH);
	closesocket(sock_);
}



// ����socket
void TCPServer::socket(SOCKET sock)
{
	sock_ = sock;
}


// ����socket
SOCKET TCPServer::socket() const
{
	return sock_;
}


// ������IP��ָ���˿�
// port: Ҫ�󶨵Ķ˿ں�
bool TCPServer::bind(ushort port)
{
	addr_.sin_family			= AF_INET;
	addr_.sin_port				= htons(port);
	addr_.sin_addr.s_addr	= INADDR_ANY;

	if(::bind(sock_, (sockaddr*)&addr_, sizeof(sockaddr)) == 0)
		return true;
	else
		return false;
}


// ��ָ��IP��ָ���˿�
// ip  : Ҫ�󶨵�IPv4��ַ
// port: Ҫ�󶨵Ķ˿ں�
bool TCPServer::bind(const string& ip, ushort port)
{
	addr_.sin_family			= AF_INET;
	addr_.sin_port				= htons(port);
	addr_.sin_addr.s_addr	= inet_addr(ip.c_str());

	if(::bind(sock_, (sockaddr*)&addr_, sizeof(sockaddr)) == 0)
		return true;
	else
		return false;
}


// ����
// ��������Ӷ��е���󳤶�Ϊ��������ֵ
bool TCPServer::listen()
{
	if(::listen(sock_, SOMAXCONN) == 0)
		return true;
	else
		return false;
}


// ����
// logback: ��������Ӷ��е���󳤶�
bool TCPServer::listen(int logback)
{
	if(::listen(sock_, logback) == 0)
		return true;
	else
		return false;
}


// ����(sock_�ϵ�)��������
SOCKET TCPServer::accept()
{
	SOCKET sock;

	int addrLen = sizeof(addr_);
	sock = ::accept(sock_, (sockaddr*)&addr_, &addrLen);
	return sock;
}
