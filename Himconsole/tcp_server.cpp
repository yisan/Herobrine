// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// Socket TCP 服务端

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



// 设置socket
void TCPServer::socket(SOCKET sock)
{
	sock_ = sock;
}


// 返回socket
SOCKET TCPServer::socket() const
{
	return sock_;
}


// 绑定任意IP的指定端口
// port: 要绑定的端口号
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


// 绑定指定IP的指定端口
// ip  : 要绑定的IPv4地址
// port: 要绑定的端口号
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


// 监听
// 挂起的连接队列的最大长度为合理的最大值
bool TCPServer::listen()
{
	if(::listen(sock_, SOMAXCONN) == 0)
		return true;
	else
		return false;
}


// 监听
// logback: 挂起的连接队列的最大长度
bool TCPServer::listen(int logback)
{
	if(::listen(sock_, logback) == 0)
		return true;
	else
		return false;
}


// 接受(sock_上的)连接请求
SOCKET TCPServer::accept()
{
	SOCKET sock;

	int addrLen = sizeof(addr_);
	sock = ::accept(sock_, (sockaddr*)&addr_, &addrLen);
	return sock;
}
