// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian

#include "print.h"
#include <stdio.h>
#include "color.h"

namespace print
{

void info(const string str)
{
	color::fore::blue();
	color::mode::bold();
	printf("[*] ");
	color::rest();
	puts(str.c_str());
}

void good(const string str)
{
	color::fore::green();
	color::mode::bold();
	printf("[+] ");
	color::rest();
	puts(str.c_str());
}

void err(const string str)
{
	color::fore::red();
	color::mode::bold();
	printf("[-] ");
	color::rest();
	puts(str.c_str());
}

void warn(const string str)
{
	color::fore::yellow();
	color::mode::bold();
	printf("[!] ");
	color::rest();
	puts(str.c_str());
}

}	// namespcae print
