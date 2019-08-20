// Copyright 2019 SMS
// License(MIT)
// Author: ShenMian
// Windows

#include "type.h"

#ifndef COLOR_H_
#define COLOR_H_

namespace color
{
void rest();

namespace fore
{

	void black();
	void red();
	void green();
	void yellow();
	void blue();
	void purple();
	void cyan();
	void white();
	void gray();

}	// namespace fore

namespace back
{

	void black();
	void red();
	void green();
	void yellow();
	void blue();
	void purple();
	void cyan();
	void white();
	void gray();

}	// namespace back

namespace mode
{

	void bold();
	void underline();
	void invert();
	void hide();

}	// namespace mode

}	// namespace color

#endif	// COLOR_H_
