#pragma once
#include "Config.h"

class CBorder
{
public:
	CBorder();
	void Init();
	void Draw(HDC &hdc, RECT& paint_area);
private:
	void Draw_Element(HDC &hdc, const int &x, const int &y, bool is_top);

	HPEN Border_White_pen, Border_Blue_pen;
	HBRUSH Border_White_brush, Border_Blue_brush;
};

