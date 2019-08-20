// Copyright 2019 SMS
// License(MIT)
// Author: ShenMian
// Windows

#include "color.h"
#include <windows.h>
#include "type.h"

namespace color
{
HANDLE hStdOut;
bool	 firstCall = true;	// 是否为第一次调用
ushort foreAttr;					// 默认前景属性
ushort backAttr;					// 默认背景属性

// 获取当前缓冲区字符属性
WORD GetAttr()
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo;
	GetConsoleScreenBufferInfo(hStdOut, &bufInfo);
	return bufInfo.wAttributes;
}

void Init()
{
	hStdOut	= GetStdHandle(STD_OUTPUT_HANDLE);
	foreAttr = GetAttr() & 0x0f;
	backAttr = GetAttr() & 0xf0;

	firstCall = false;
}

void rest()
{
	if (firstCall)
		Init();
	SetConsoleTextAttribute(hStdOut, foreAttr | backAttr);
}

namespace fore
{
	void black()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, 0x0 | backAttr);
	}

	void red()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
	}

	void green()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
	}

	void yellow()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, 0x6 | backAttr);
	}

	void blue()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
	}

	void purple()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, 0x5 | backAttr);
	}

	void cyan()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, 0x3 | backAttr);
	}

	void white()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, 0x7 | backAttr);
	}

	void gray()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, 0x8 | backAttr);

	}	// namespace fore

}	// namespace fore

namespace back
{
	void black()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, foreAttr | 0x0);
	}

	void red()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, BACKGROUND_RED);
	}

	void green()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, BACKGROUND_GREEN);
	}

	void yellow()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, foreAttr | 0x6);
	}

	void blue()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, BACKGROUND_BLUE);
	}

	void purple()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, foreAttr | 0x5);
	}

	void cyan()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, foreAttr | 0x3);
	}

	void white()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, foreAttr | 0x7);
	}

	void gray()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, foreAttr | 0x8);
	}

}	// namespace back

namespace mode
{
	void bold()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, GetAttr() | FOREGROUND_INTENSITY);
	}

	void underline()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, GetAttr() | COMMON_LVB_UNDERSCORE);
	}

	void invert()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, GetAttr() | COMMON_LVB_REVERSE_VIDEO);
	}

	void hide()
	{
		if (firstCall)
			Init();
		SetConsoleTextAttribute(hStdOut, GetAttr() & 0xf0 | GetAttr() & 0xf0);
	}

}	// namespace mode

}	// namespace color
