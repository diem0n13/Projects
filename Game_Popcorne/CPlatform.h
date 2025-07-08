#pragma once
#include "Config.h"

class CPlatform
{
public:
	CPlatform();

	void Init();
	void Redraw(HWND& hWnd);
	void Draw(HDC &hdc, RECT& paint_area);

	int X_Pos;
	int X_Step;
	int Width;
private:
	int Inner_Width;

	HPEN Circle_pen, Inner_pen, Highlight_pen;
	HBRUSH Circle_brush, Inner_brush;
	RECT Platform_rect, Prev_Platform_rect;

	static const int Size_Circle = 7;
	static const int Height = 7;
};


