// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian

#ifndef TCPSERVER_H_
#define TCPSERVER_H_

#include "socket.h"

class TCPServer : public Socket
{
public:
	TCPServer();
	~TCPServer();

	void		socket(SOCKET sock);
	SOCKET	socket() const;

	bool bind(ushort port);
	bool bind(const string& ip, ushort port);

	bool listen();
	bool listen(int backlog);

	SOCKET	accept();

private:
	SOCKET			sock_;
	sockaddr_in	addr_;
};

#endif	// TCPSERVER_H_
