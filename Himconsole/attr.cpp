// Copyright 2019 SMS
// License(GPL)
// Author: ShenMian
// 控制字体属性

#include "attr.h"
#include "type.h"
#include <windows.h>

namespace attr
{

HANDLE hStdOut;

ushort attr;			// 当前字符属性值
ushort foreColor;	// 原字符前景色
ushort backColor;	// 原字符背景色

void init()
{
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

	// 获取原字符属性
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdOut, &bufferInfo);
	attr = bufferInfo.wAttributes;
	foreColor = bufferInfo.wAttributes & 0x0f;
	backColor = bufferInfo.wAttributes & 0xf0;
}

void rest()
{
	attr = foreColor | backColor;
	SetConsoleTextAttribute(hStdOut, attr);
}

void underscore()
{
	attr |= COMMON_LVB_UNDERSCORE;
	SetConsoleTextAttribute(hStdOut, attr);
}

namespace fore
{

	void light()
	{
		attr |= FOREGROUND_INTENSITY;
		SetConsoleTextAttribute(hStdOut, attr);
	}

	void blue()
	{
		attr = FOREGROUND_BLUE;
		SetConsoleTextAttribute(hStdOut, attr);
	}

	void green()
	{
		attr = FOREGROUND_GREEN;
		SetConsoleTextAttribute(hStdOut, attr);
	}

	void red()
	{
		attr = FOREGROUND_RED;
		SetConsoleTextAttribute(hStdOut, attr);
	}

	void yellow()
	{
		attr = 0x6 | backColor;
		SetConsoleTextAttribute(hStdOut, attr);
	}

	void gray()
	{
		attr = 0x8 | backColor;
		SetConsoleTextAttribute(hStdOut, attr);
	}

	void white()
	{
		attr = 0x7 | backColor;
		SetConsoleTextAttribute(hStdOut, attr);
	}

}	// namespace fore

namespace back
{

	void light()
	{
		attr |= BACKGROUND_INTENSITY;
		SetConsoleTextAttribute(hStdOut, attr);
	}

	void blue()
	{
		attr |= BACKGROUND_BLUE;
		SetConsoleTextAttribute(hStdOut, attr);
	}

	void green()
	{
		attr |= BACKGROUND_GREEN;
		SetConsoleTextAttribute(hStdOut, attr);
	}

	void red()
	{
		attr |= BACKGROUND_RED;
		SetConsoleTextAttribute(hStdOut, attr);
	}

}	// namespcae back

}	// namespace attr
