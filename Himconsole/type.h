// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// ����/�����������

#ifndef TYPE_H_
#define TYPE_H_


#include <string>
using std::string;
using std::to_string;

#include <vector>
using std::vector;

#include <deque>
using std::deque;


typedef unsigned char		uchar;
typedef unsigned short	ushort;
typedef unsigned int		uint;


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


#endif	// TYPE_H_
