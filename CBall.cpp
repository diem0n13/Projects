#include "CBall.h"

CBall::CBall() : Ball_pen(0), Ball_brush(0), Ball_Direction(M_PI - M_PI_4), Ball_rect{}, Prev_Ball_rect{}, Ball_X_Pos(20), Ball_Y_Pos(170), Ball_Speed(3.0)
{
}

void CBall::Init()
{
	Config::InitColor(255, 255, 255, Ball_pen, Ball_brush);
}

void CBall::Draw(HDC hdc, RECT& paint_area)
{
	RECT intersection_Rect;
	if (!IntersectRect(&intersection_Rect, &paint_area, &Ball_rect))
		return;
	SelectObject(hdc, Config::BG_pen);
	SelectObject(hdc, Config::BG_brush);

	Ellipse(hdc, Prev_Ball_rect.left, Prev_Ball_rect.top, Prev_Ball_rect.right - 1, Prev_Ball_rect.bottom - 1);

	SelectObject(hdc, Ball_pen);
	SelectObject(hdc, Ball_brush);

	Ellipse(hdc, Ball_rect.left, Ball_rect.top, Ball_rect.right - 1, Ball_rect.bottom - 1);
}

void CBall::Move(HWND &hWnd, CLevel* level, const int& platform_x_pos, const int& platform_width)
{
	int next_x_pos, next_y_pos;
	int max_x_pos = Config::Max_X_Pos - Config::Ball_Size;
	int platform_y_pos = Config::Platform_Y_Pos - Config::Ball_Size;

	Prev_Ball_rect = Ball_rect;

	next_x_pos = Ball_X_Pos + (int)(Ball_Speed * cos(Ball_Direction));
	next_y_pos = Ball_Y_Pos - (int)(Ball_Speed * sin(Ball_Direction));

	if (next_x_pos < Config::Border_X_Offset)
	{
		next_x_pos = Config::OffsetX - (next_x_pos - Config::OffsetX);
		Ball_Direction = M_PI - Ball_Direction;
	}

	if (next_y_pos < Config::Border_Y_Offset)
	{
		next_y_pos = Config::Border_Y_Offset - (next_y_pos - Config::Border_Y_Offset);
		Ball_Direction = -Ball_Direction;
	}

	if (next_x_pos > max_x_pos)
	{
		next_x_pos = max_x_pos - (next_x_pos - max_x_pos);
		Ball_Direction = M_PI - Ball_Direction;
	}

	if (next_y_pos > Config::Max_Y_Pos)
	{
		next_y_pos = Config::Max_Y_Pos - (next_y_pos - Config::Max_Y_Pos);
		Ball_Direction = M_PI + (M_PI - Ball_Direction);
	}

	if (next_y_pos > platform_y_pos)
	{
		if (next_x_pos >= platform_x_pos && next_x_pos <= platform_x_pos + platform_width)
		{
			next_y_pos = platform_y_pos - (next_y_pos - platform_y_pos);
			Ball_Direction = M_PI + (M_PI - Ball_Direction);
		}
	}

	level->Check_Brick_Level_Hit(next_y_pos, Ball_Direction);

	Ball_X_Pos = next_x_pos;
	Ball_Y_Pos = next_y_pos;

	Ball_rect.left = Ball_X_Pos * Config::Global_Scale;
	Ball_rect.top = Ball_Y_Pos * Config::Global_Scale;
	Ball_rect.right = Ball_rect.left + Config::Ball_Size * Config::Global_Scale;//(OffsetX + Platform_rect.left) + Platform_Width * Global_Scale;
	Ball_rect.bottom = Ball_rect.top + Config::Ball_Size * Config::Global_Scale;

	InvalidateRect(hWnd, &Prev_Ball_rect, FALSE);
	InvalidateRect(hWnd, &Ball_rect, FALSE);
}