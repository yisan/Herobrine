// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// øÿ÷∆◊÷ÃÂ Ù–‘

#include <windows.h>
#include "type.h"

#ifndef ATTR_H_
#define ATTR_H_

namespace attr
{

void init();

void rest();
void underscore();

namespace fore
{
	void light();	// intensity
	void blue();
	void green();
	void red();
	void yellow();
	void gray();
	void white();
}	// namespcae fore

namespace back
{
	void light();	// intensity
	void blue();
	void green();
	void red();
}	// namespace back

}	// namespace attr

#endif	// ATTR_H_
