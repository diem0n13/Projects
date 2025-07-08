#pragma once
#include "Config.h"
#include "CActive_Brick.h"

class CLevel
{
public:
	CLevel();
	void Init();
	void Check_Brick_Level_Hit(int& next_y_pos, double& ball_direction);
	void Draw(HDC &hdc, RECT& paint_area);

	CActive_Brick Active_Brick;
private:
	void Draw_Brick(HDC& hdc, const int& x, const int& y, EBrick_Type brick_type);
	void Set_Brick_Letter_Colors(HPEN& front_pen, HPEN& back_pen, HBRUSH& front_brush, HBRUSH& back_brush, bool is_switch_color);
	void Draw_Letter(HDC& hdc, const int& x, const int& y, EBrick_Type brick_type, ELetter_Type letter_type, int rotation_step);

	HPEN Brick_red_pen, Brick_blue_pen, Letter_pen;
	HBRUSH Brick_red_brush, Brick_blue_brush;
	RECT Level_rect;

	static char Level_01[Config::Level_Height][Config::Level_Width];
};

