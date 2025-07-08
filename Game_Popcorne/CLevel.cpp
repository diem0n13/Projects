#include "CLevel.h"

char CLevel::Level_01[Config::Level_Height][Config::Level_Width]
{
	0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,
	2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,
	1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,
	2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,
	0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0
};

CLevel::CLevel() : Active_Brick(EBT_blue), Brick_red_pen(0), Brick_blue_pen(0), Letter_pen(0), Brick_red_brush(0), Brick_blue_brush(0), Level_rect{}
{
}

void CLevel::Init()
{
	Letter_pen = CreatePen(PS_SOLID, Config::Global_Scale, RGB(255, 255, 255));

	Config::InitColor(Config::Red_Brick_Color, Brick_red_pen, Brick_red_brush);
	Config::InitColor(Config::Blue_Brick_Color, Brick_blue_pen, Brick_blue_brush);

	Level_rect.left = Config::OffsetX * Config::Global_Scale;
	Level_rect.top = Config::OffsetY * Config::Global_Scale;
	Level_rect.right = Level_rect.left + Config::Cell_Width * Config::Level_Width * Config::Global_Scale;
	Level_rect.bottom = Level_rect.top + Config::Cell_Height * Config::Level_Height * Config::Global_Scale;
}

void CLevel::Check_Brick_Level_Hit(int& next_y_pos, double& ball_direction)
{
	int i, j;
	int brick_y_pos = Config::OffsetX + Config::Level_Height * Config::Cell_Height;
	for (i = Config::Level_Height - 1;i > 0;--i)
	{
		for (j = 0;j < Config::Level_Width;++j)
		{
			if (Level_01[i][j] == 0)
				continue;

			if (next_y_pos < brick_y_pos)
			{
				next_y_pos = brick_y_pos - (next_y_pos - brick_y_pos);
				ball_direction = -ball_direction;
			}
		}
		brick_y_pos -= Config::Cell_Height;
	}
}

void CLevel::Draw(HDC& hdc, RECT& paint_area)
{
	RECT intersection_Rect;

	if (!IntersectRect(&intersection_Rect, &paint_area, &Level_rect))
		return;
	int i, j;
	for (i = 0;i < Config::Level_Height;++i)
	{
		for (j = 0;j < Config::Level_Width;++j)
		{
			Draw_Brick(hdc, Config::OffsetX + j * Config::Cell_Width, Config::OffsetY + i * Config::Cell_Height, (EBrick_Type)Level_01[i][j]);
		}
	}
	Active_Brick.Draw(hdc, paint_area);
}

void CLevel::Draw_Brick(HDC& hdc, const int& x, const int& y, EBrick_Type brick_type)
{
	HPEN pen;
	HBRUSH brush;
	switch (brick_type)
	{
	case EBT_none:
		return;
	case EBT_red:
		pen = Brick_red_pen;
		brush = Brick_red_brush;
		break;
	case EBT_blue:
		pen = Brick_blue_pen;
		brush = Brick_blue_brush;
		break;
	default:
		return;
	}

	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	RoundRect(hdc, x * Config::Global_Scale, y * Config::Global_Scale, (x + Config::Brick_Width) *
		Config::Global_Scale, (y + Config::Brick_Height) * Config::Global_Scale, Config::Global_Scale * 2,
		Config::Global_Scale * 2);
}

void CLevel::Set_Brick_Letter_Colors(HPEN& front_pen, HPEN& back_pen, HBRUSH& front_brush, HBRUSH& back_brush, bool is_switch_color)
{

	if (is_switch_color)
	{
		front_pen = Brick_red_pen;
		front_brush = Brick_red_brush;

		back_pen = Brick_blue_pen;
		back_brush = Brick_blue_brush;
	}
	else
	{
		front_pen = Brick_blue_pen;
		front_brush = Brick_blue_brush;

		back_pen = Brick_red_pen;
		back_brush = Brick_red_brush;
	}
}

void CLevel::Draw_Letter(HDC& hdc, const int& x, const int& y, EBrick_Type brick_type, ELetter_Type letter_type, int rotation_step)
{
	bool switch_color;
	double offset;
	double rotate_angle;
	int brick_half_height = (int)(Config::Brick_Height * Config::Global_Scale * 0.5);
	int back_part_offset;
	XFORM xform, prev_xform;
	HPEN front_pen, back_pen;
	HBRUSH front_brush, back_brush;

	rotation_step = rotation_step % 16;

	if (rotation_step < 8)
		rotate_angle = 2.0 * M_PI / 16.0 * (double)rotation_step;
	else
		rotate_angle = 2.0 * M_PI / 16.0 * (double)(8 - rotation_step);

	if ((brick_type & (EBT_blue | EBT_red)) == 0)
		//if (!(brick_type == EBT_blue || brick_type == EBT_red))
		return;

	if (rotation_step > 4 && rotation_step <= 12)
		switch_color = brick_type == EBT_blue;
	else
		switch_color = brick_type == EBT_red;
	Set_Brick_Letter_Colors(front_pen, back_pen, front_brush, back_brush, switch_color);

	if (rotation_step == 4 || rotation_step == 12)
	{
		SelectObject(hdc, back_pen);
		SelectObject(hdc, back_brush);

		Rectangle(hdc, x, y + brick_half_height - Config::Global_Scale, x + Config::Brick_Width * Config::Global_Scale, y + brick_half_height);

		SelectObject(hdc, front_pen);
		SelectObject(hdc, front_brush);

		Rectangle(hdc, x, y + brick_half_height, x + Config::Brick_Width * Config::Global_Scale, y + brick_half_height + Config::Global_Scale - 1);
	}
	else
	{
		SetGraphicsMode(hdc, GM_ADVANCED);

		xform.eM11 = 1.0f;
		xform.eM12 = 0.0f;
		xform.eM21 = 0.0f;
		xform.eM22 = (float)cos(rotate_angle);
		xform.eDx = (float)x;
		xform.eDy = (float)y + (float)brick_half_height;
		GetWorldTransform(hdc, &prev_xform);
		SetWorldTransform(hdc, &xform);

		SelectObject(hdc, back_pen);
		SelectObject(hdc, back_brush);

		offset = 3.0 * (1.0 - fabs(xform.eM22)) * (double)Config::Global_Scale;
		back_part_offset = (int)round(offset);
		Rectangle(hdc, 0, -brick_half_height - back_part_offset, Config::Brick_Width * Config::Global_Scale, brick_half_height - back_part_offset);

		SelectObject(hdc, front_pen);
		SelectObject(hdc, front_brush);

		Rectangle(hdc, 0, -brick_half_height, Config::Brick_Width * Config::Global_Scale, brick_half_height);

		if (rotation_step > 4 && rotation_step <= 12)
		{
			if (letter_type == ELT_O)
			{
				SelectObject(hdc, Letter_pen);
				Ellipse(hdc, 0 + 5 * Config::Global_Scale, (int)(-5 * Config::Global_Scale * 0.5), 0 + 10 * Config::Global_Scale, (int)(5 * Config::Global_Scale * 0.5));
			}
		}

		SetWorldTransform(hdc, &prev_xform);
	}
}