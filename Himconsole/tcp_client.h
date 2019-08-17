// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian

#ifndef TCPCLIENT_H_
#define TCPCLIENT_H_

#include "socket.h"

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
