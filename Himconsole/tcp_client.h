// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// Socket TCP ¿Í»§¶Ë

#include "socket.h"

#ifndef TCPCLIENT_H_
#define TCPCLIENT_H_


class TCPClient : public Socket
{
public:
	TCPClient();
	~TCPClient();

	void		socket(SOCKET sock);
	SOCKET	socket() const;
	string	ip() const;
	ushort	port() const;

	bool send(const string& buf);
	bool recv(string& buf);

	bool connect(const string& ip, ushort port);

private:
	SOCKET			sock_;
	sockaddr_in	addr_;
};


#endif	// TCPCLIENT_H_
