// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// ���ض�

#include "type.h"
#include "tcp_client.h"

#ifndef SLAVE_H_
#define SLAVE_H_


// ����ϵͳ����Ϣ
typedef struct
{
	short		type;	// ƽ̨
	string	lang;	// ����
	struct	mem
	{
		short	total;			// ����(GB)
		short	free;				// ϵͳ����(GB)
		short available;	// Ӧ�ÿ���(GB)
	};
} os_info;

// Windows �ں˲���ϵͳ����Ϣ
typedef struct : os_info
{
	short	majorVer;	// ���汾
	short minorVer;	// �ΰ汾
} os_info_windows;

// Linux �ں˲���ϵͳ��Ϣ
typedef struct : os_info
{;
} os_info_linux;


// �û�����Ϣ
typedef struct {
	ushort	id;
	string	name;
} user_info;


class Slave
{
public:
	Slave();
	~Slave();

	static ushort size();

private:
	TCPClient	sock;

	os_info		os_;
	user_info	user_;

	static ushort size_;	// ʵ������
};

#endif	// SLAVE_H_
