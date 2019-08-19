// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian

#include "print.h"
#include <stdio.h>

namespace print
{

void info(const string str)
{
	attr::fore::blue();
	attr::fore::light();
	printf("[*] ");
	attr::rest();
	puts(str.c_str());
}

void good(const string str)
{
	attr::fore::green();
	attr::fore::light();
	printf("[+] ");
	attr::rest();
	puts(str.c_str());
}

void err(const string str)
{
	attr::fore::red();
	attr::fore::light();
	printf("[-] ");
	attr::rest();
	puts(str.c_str());
}

void warn(const string str)
{
	attr::fore::yellow();
	attr::fore::light();
	printf("[!] ");
	attr::rest();
	puts(str.c_str());
}

}	// namespcae print
