// Copyright 2019 SMS
// License(MIT)
// Author: ShenMian
// Linux

#include <stdio.h>

namespace color
{

const auto rest_ = "\033[0m";

void rest()
{
	printf(rest_);
}

namespace fore
{

	const auto black_	= "\033[30m";
	const auto red_		= "\033[31m";
	const auto green_	= "\033[32m";
	const auto yellow_= "\033[33m";
	const auto blue_	= "\033[34m";
	const auto purple_= "\033[35m";
	const auto cyan_	= "\033[36m";
	const auto white_	= "\033[37m";

	void black()
	{
		printf(black_);
	}

	void red()
	{
		printf(red_);
	}

	void green()
	{
		printf(green_);
	}

	void yellow()
	{
		printf(yellow_);
	}

	void blue()
	{
		printf(blue_);
	}

	void purple()
	{
		printf(purple_);
	}

	void cyan()
	{
		printf(cyan_);
	}

	void white()
	{
		printf(white_);
	}

	void gray()
	{
		printf("\33[8;37m");
	}

}	// namespace fore

namespace back
{

	const auto black_	= "\033[40m";
	const auto red_		= "\033[41m";
	const auto green_	= "\033[42m";
	const auto yellow_= "\033[43m";
	const auto blue_	= "\033[44m";
	const auto purple_= "\033[45m";
	const auto cyan_	= "\033[46m";
	const auto white_	= "\033[47m";

	void black()
	{
		printf(black_);
	}

	void red()
	{
		printf(red_);
	}

	void green()
	{
		printf(green_);
	}

	void yellow()
	{
		printf(yellow_);
	}

	void blue()
	{
		printf(blue_);
	}

	void purple()
	{
		printf(purple_);
	}

	void cyan()
	{
		printf(cyan_);
	}

	void white()
	{
		printf(white_);
	}

	void gray()
	{
		printf("\33[8;47m");
	}

}	// namespace back

namespace mode
{

	const auto bold_			= "\033[1m";
	const auto underline_	= "\033[4m";
	const auto blink_			= "\033[5m";
	const auto invert_		= "\033[7m";
	const auto hide_			= "\033[8m";

	void bold()
	{
		printf(bold_);
	}

	void underline()
	{
		printf(underline_);
	}

	void blink()
	{
		printf(blink_);
	}

	void invert()
	{
		printf(invert_);
	}

	void hide()
	{
		printf(hide_);
	}

}	// namespace mode

}	// namespace color
