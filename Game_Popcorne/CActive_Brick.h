#pragma once
#include "Config.h"

class CActive_Brick
{
public:
	CActive_Brick(EBrick_Type type);
	void Act(HWND& hWnd);
	void Draw(HDC& hdc, RECT& paint_area);
	static void Configure_Colors();
private:
	
	EBrick_Type Brick_Type;
	int Fade_Step;
	RECT Brick_Rect;

	static unsigned char Get_Fading_Channel(unsigned char color, unsigned char bg_color, int step);
	static void Get_Fading_Color(const CColor& color, int step, HPEN& pen, HBRUSH& brush);
	
	static const int Max_Fade_Step = 80;

	static HPEN Fading_Blue_Brick_Pens[Max_Fade_Step];
	static HBRUSH Fading_Blue_Brick_Brushes[Max_Fade_Step];
	static HPEN Fading_Red_Brick_Pens[Max_Fade_Step];
	static HBRUSH Fading_Red_Brick_Brushes[Max_Fade_Step];
};


