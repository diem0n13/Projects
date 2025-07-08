#include "CBorder.h"

CBorder::CBorder():Border_White_pen(0), Border_Blue_pen(0),Border_White_brush(0), Border_Blue_brush(0)
{}

void CBorder::Init()
{
	Config::InitColor(85, 255, 255, Border_Blue_pen, Border_Blue_brush);
	Config::InitColor(255, 255, 255, Border_White_pen, Border_White_brush);
}

void CBorder::Draw(HDC &hdc, RECT& paint_area)
{
	int i;
	for (i = 0;i < 50;++i)
	{
		Draw_Element(hdc, 2, 1 + i * 4, false);
		Draw_Element(hdc, 201, 1 + i * 4, false);
		Draw_Element(hdc, 3 + i * 4, 0, true);
	}
}

void CBorder::Draw_Element(HDC &hdc, const int &x, const int &y, bool is_top)
{
	SelectObject(hdc, Border_Blue_pen);
	SelectObject(hdc, Border_Blue_brush);

	if (is_top)
		Rectangle(hdc, x * Config::Global_Scale, y * Config::Global_Scale, (x + 4) * Config::Global_Scale, (y + 4) * Config::Global_Scale);
	else
		Rectangle(hdc, (x + 1) * Config::Global_Scale, y * Config::Global_Scale, (x + 4) * Config::Global_Scale, (y + 4) * Config::Global_Scale);

	SelectObject(hdc, Border_White_pen);
	SelectObject(hdc, Border_White_brush);

	if (is_top)
		Rectangle(hdc, x * Config::Global_Scale, y * Config::Global_Scale, (x + 4) * Config::Global_Scale, (y + 1) * Config::Global_Scale);
	else
		Rectangle(hdc, x * Config::Global_Scale, y * Config::Global_Scale, (x + 1) * Config::Global_Scale, (y + 4) * Config::Global_Scale);

	SelectObject(hdc, Config::BG_pen);
	SelectObject(hdc, Config::BG_brush);

	if (is_top)
		Rectangle(hdc, (x + 2) * Config::Global_Scale, (y + 2) * Config::Global_Scale, (x + 3) * Config::Global_Scale, (y + 3) * Config::Global_Scale);
	else
		Rectangle(hdc, (x + 2) * Config::Global_Scale, (y + 1) * Config::Global_Scale, (x + 3) * Config::Global_Scale, (y + 2) * Config::Global_Scale);
}