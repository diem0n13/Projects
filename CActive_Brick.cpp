#include "CActive_Brick.h"

HPEN CActive_Brick::Fading_Blue_Brick_Pens[Max_Fade_Step];
HBRUSH CActive_Brick::Fading_Blue_Brick_Brushes[Max_Fade_Step];
HPEN CActive_Brick::Fading_Red_Brick_Pens[Max_Fade_Step];
HBRUSH CActive_Brick::Fading_Red_Brick_Brushes[Max_Fade_Step];

CActive_Brick::CActive_Brick(EBrick_Type type) : Brick_Type(type), Fade_Step(0), Brick_Rect{}
{
}

void CActive_Brick::Act(HWND& hWnd)
{
	if (Fade_Step < Max_Fade_Step - 1)
	{
		++Fade_Step;
		InvalidateRect(hWnd, &Brick_Rect, false);
	}
}

void CActive_Brick::Draw(HDC& hdc, RECT& paint_area)
{
	//HPEN pen = nullptr;
	//HBRUSH brush = nullptr;

	switch (Brick_Type)
	{
	case EBT_blue:
		SelectObject(hdc, Fading_Blue_Brick_Pens[Fade_Step]);//pen = Fading_Blue_Brick_Pens[Fade_Step];
		SelectObject(hdc, Fading_Blue_Brick_Brushes[Fade_Step]);//brush = Fading_Blue_Brick_Brushes[Fade_Step];
		break;
	case EBT_red:
		SelectObject(hdc, Fading_Red_Brick_Pens[Fade_Step]);//pen = Fading_Red_Brick_Pens[Fade_Step];
		SelectObject(hdc, Fading_Red_Brick_Brushes[Fade_Step]);//brush = Fading_Red_Brick_Brushes[Fade_Step];
		break;
	}

	//SelectObject(hdc, pen);
	//SelectObject(hdc, brush);

	Brick_Rect.left = (Config::OffsetX + Config::Cell_Width) * Config::Global_Scale;
	Brick_Rect.top = (Config::OffsetY + Config::Cell_Height) * Config::Global_Scale;
	Brick_Rect.right = Brick_Rect.left + Config::Brick_Width * Config::Global_Scale;
	Brick_Rect.bottom = Brick_Rect.top + Config::Brick_Height * Config::Global_Scale;

	RoundRect(hdc, 1 * Brick_Rect.left, 1 * Brick_Rect.top, Brick_Rect.right, Brick_Rect.bottom, Config::Global_Scale * 2,
		Config::Global_Scale * 2);
}

void CActive_Brick::Configure_Colors()
{
	int i;
	for (i = 0; i < Max_Fade_Step; i++)
	{
		Get_Fading_Color(Config::Blue_Brick_Color, i, Fading_Blue_Brick_Pens[i], Fading_Blue_Brick_Brushes[i]);
		Get_Fading_Color(Config::Red_Brick_Color, i, Fading_Red_Brick_Pens[i], Fading_Red_Brick_Brushes[i]);
	}	
}
unsigned char CActive_Brick::Get_Fading_Channel(unsigned char color, unsigned char bg_color, int step)
{
	return color - step * (color - bg_color) / Max_Fade_Step - 1;
}

void CActive_Brick::Get_Fading_Color(const CColor &color, int step, HPEN &pen, HBRUSH &brush)
{
	unsigned char r, g, b;

	r = CActive_Brick::Get_Fading_Channel(Config::Blue_Brick_Color.R, Config::BG_Color.R, step);
	g = CActive_Brick::Get_Fading_Channel(Config::Blue_Brick_Color.G, Config::BG_Color.G, step);
	b = CActive_Brick::Get_Fading_Channel(Config::Blue_Brick_Color.B, Config::BG_Color.B, step);

	Config::InitColor(r, g, b, pen, brush);
}
