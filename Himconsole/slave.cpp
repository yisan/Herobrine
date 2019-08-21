// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// ±»¿Ø¶Ë

#include "slave.h"

ushort Slave::size_ = 0;

ushort Slave::size()
{
	return size_;
}

void Slave::os_info(string& os_info)
{
	memcpy(&os_info_, os_info.c_str(), os_info.size());
}
