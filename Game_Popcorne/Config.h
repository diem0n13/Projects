#pragma once
#include "Windows.h"

#define _USE_MATH_DEFINES
#include <math.h>

enum EBrick_Type { EBT_none, EBT_red, EBT_blue };
enum ELetter_Type { ELT_none, ELT_O };

class CColor
{
public:
	CColor(unsigned char r, unsigned char g, unsigned char b);

	unsigned char R,G,B;
};

class Config
{
public:
	static void Configure_Colors();
	static void InitColor(const CColor& color, HPEN& pen, HBRUSH& brush);
	static void InitColor(unsigned char r, unsigned char g, unsigned char b, HPEN& pen, HBRUSH& brush);

	static const CColor BG_Color, Red_Brick_Color, Blue_Brick_Color;
	static HPEN BG_pen;
	static HBRUSH BG_brush;

	static const int Global_Scale = 3;
	static const int Border_X_Offset = 6;
	static const int Border_Y_Offset = 4;
	static const int Ball_Size = 4;
	static const int Level_Width = 12;
	static const int Level_Height = 14;
	static const int OffsetX = 8;
	static const int OffsetY = 6;
	static const int Cell_Width = 16;
	static const int Cell_Height = 8;
	static const int Max_X_Pos = OffsetX + Cell_Width * Level_Width;
	static const int Max_Y_Pos = 199 - Ball_Size;
	static const int Platform_Y_Pos = 185;
	static const int FPS = 20;
	static const int Brick_Width = 15;
	static const int Brick_Height = 7;
};

