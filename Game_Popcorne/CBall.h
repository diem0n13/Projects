#pragma once
#include "Config.h"
#include "CLevel.h"

class CBall
{
public:
	CBall();
	void Init();
	void Draw(HDC hdc, RECT& paint_area);
	void Move(HWND &hWnd, CLevel* level, const int &platform_x_pos, const int& platform_width);
	
private:
	HPEN Ball_pen;
	HBRUSH Ball_brush;
	RECT Ball_rect, Prev_Ball_rect;

	int Ball_X_Pos, Ball_Y_Pos;
	double Ball_Speed, Ball_Direction;
};


