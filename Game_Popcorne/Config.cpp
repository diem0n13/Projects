#include "Config.h"

CColor::CColor(unsigned char r, unsigned char g, unsigned char b) : R(r), G(g),B(b)
{
}

const CColor Config::BG_Color(15, 63, 31);
const CColor Config::Red_Brick_Color(255, 85, 85);
const CColor Config::Blue_Brick_Color(85, 255, 255);

HPEN Config::BG_pen;
HBRUSH Config::BG_brush;

void Config::Configure_Colors()
{
	Config::InitColor(Config::BG_Color, Config::BG_pen, Config::BG_brush);
}

void Config::InitColor(const CColor &color, HPEN& pen, HBRUSH& brush)
{
	pen = CreatePen(PS_SOLID, 0, RGB(color.R, color.G, color.B));
	brush = CreateSolidBrush(RGB(color.R, color.G, color.B));
}

void Config::InitColor(unsigned char r, unsigned char g, unsigned char b, HPEN& pen, HBRUSH& brush)
{
	pen = CreatePen(PS_SOLID, 0, RGB(r, g, b));
	brush = CreateSolidBrush(RGB(r, g, b));
}