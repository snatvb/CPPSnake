#pragma once

using ui8 = unsigned __int8;

struct Color
{
	ui8 r;
	ui8 g;
	ui8 b;

	Color() {
		r = 0;
		g = 0;
		b = 0;
	}

	Color(ui8 r, ui8 g, ui8 b)
		: r(r), g(g), b(b)
	{
	}
};

struct AlphaColor : Color
{
	ui8 a;

	AlphaColor() : Color() {
		a = 255;
	}

	AlphaColor(ui8 r, ui8 g, ui8 b, ui8 a)
		: Color(r, g, b), a(a)
	{
	}
};
