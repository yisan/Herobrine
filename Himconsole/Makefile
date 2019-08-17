# Copyright 2019 SMS
# License(GPL)
# Author: ShenMian

TARGET = himconsole.exe

SRCS = himconsole.cpp attr.cpp print.cpp socket.cpp tcp_server.cpp tcp_client.cpp

OBJS = bin/himconsole.o bin/attr.o bin/print.o bin/socket.o bin/tcp_server.o bin/tcp_client.o bin/slave.o lib/libmysql.lib

DEBUG = 1

CFLAGS	= -O3
LDFLAGS	= -lwsock32

ifdef DEBUG
CFLAGS	= -g -Wall
endif

$(TARGET) : $(OBJS)
	g++ $^ -o bin/$@ $(LDFLAGS) $(CFLAGS)

bin/himconsole.o : himconsole.cpp
	g++ $^ -o $@ -c $(CFLAGS)

bin/attr.o : attr.cpp
	g++ $^ -o $@ -c $(CFLAGS)

bin/print.o : print.cpp
	g++ $^ -o $@ -c $(CFLAGS)

bin/socket.o : socket.cpp
	g++ $^ -o $@ -c $(CFLAGS)

bin/tcp_server.o : tcp_server.cpp
	g++ $^ -o $@ -c $(CFLAGS)

bin/tcp_client.o : tcp_client.cpp
	g++ $^ -o $@ -c $(CFLAGS)

bin/slave.o : slave.cpp
	g++ $^ -o $@ -c $(CFLAGS)


clean:
	del /s /q *.o
