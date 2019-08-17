// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// Socket TCP 客户端

#include "tcp_client.h"


TCPClient::TCPClient()
{
	sock_ = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}


TCPClient::~TCPClient()
{
	closesocket(sock_);
}



// 设置socket
void TCPClient::socket(SOCKET sock)
{
	sock_ = sock;
}


// 返回socket
SOCKET TCPClient::socket() const
{
	return sock_;
}


// 返回IPv4地址
string TCPClient::ip() const
{
	return inet_ntoa(((struct sockaddr_in*)&addr_) -> sin_addr);
}


// 返回端口号
ushort TCPClient::port() const
{
	return ntohs(((struct sockaddr_in*)&addr_) -> sin_port);
}



// 发送数据
// buf: 指向包含要传输的数据的缓冲区的指针
bool TCPClient::send(const string& buf)
{
	char*		buffer;
	ushort	sendLen = 0;

	buffer = new char[buf.length()+1];
	strcpy(buffer, buf.c_str());

	// 加密数据
	

	do
	{
		sendLen += ::send(sock_, &buffer[sendLen], (strlen(buffer)-sendLen)*sizeof(char), 0);
	} while(sendLen == strlen(buffer));

	delete buffer;

	return true;
}


// 接收数据
// buf: 指向缓冲区的指针, 用于接收传入数据
#define	recv_buf_len	512	/* 缓冲区长度 min:2 min:cmd_len_min, max:1501 */
bool TCPClient::recv(string& buf)
{
	short	recvLen;
	uint	recvLenSum = 0;
	char	buffer[recv_buf_len+1];

	buf.clear();

	do
	{
		recvLen = ::recv(sock_, buffer, recv_buf_len*sizeof(char), 0);

		if(recvLen == -1)	// 异常
		{
			return false;
		}

		if(recvLen == 0)	// 目标已关闭连接
		{
			return false;
		}

		if(recvLenSum >= buf.max_size())	// 会溢出
		{
			return false;
		}

		recvLenSum += recvLen;
		buffer[recvLen] = '\0';
		buf.append(buffer);
	} while(recvLen == recv_buf_len);

	return true;
}
#undef recv_buf_len


// 发送连接请求, 建立连接
bool TCPClient::connect(const string& ip, ushort port)
{
	addr_.sin_family			= AF_INET;
	addr_.sin_port				= htons(port);
	addr_.sin_addr.s_addr	= inet_addr(ip.c_str());

	if(::connect(sock_, (sockaddr*)&addr_, sizeof(sockaddr)) == 0)
		return true;
	else
		return false;
}
