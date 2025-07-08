#include "Engine.h"

CEngine::CEngine():HWnd(0)
{
}

void CEngine::Init_Engine( HWND &hWnd)
{
	HWnd = hWnd;

	CActive_Brick::Configure_Colors();

	Ball.Init();
	Level.Init();
	Platform.Init();
	Border.Init();

	Platform.Redraw(hWnd);

	SetTimer(hWnd, Timer_ID, 1000 / Config::FPS, 0);
}

void CEngine::Draw_Frame(HDC &hdc, RECT& paint_area)
{
	Level.Draw(hdc, paint_area);
	Platform.Draw(hdc, paint_area);

	/*int i;
	for (i = 0;i < 16;++i)
	{
		Draw_Letter(hdc, 20 + i * Cell_Width * Global_Scale, 100, EBT_blue, ELT_O, i);
		Draw_Letter(hdc, 20 + i * Cell_Width * Global_Scale, 130, EBT_red, ELT_O, i);
	}*/

	Ball.Draw(hdc, paint_area);
	Border.Draw(hdc, paint_area);
}

int CEngine::On_Key_Down(EKey_Type key_type)
{
	switch (key_type)
	{
	case EKT_Left:
		Platform.X_Pos -= Platform.X_Step;
		if (Platform.X_Pos <= Config::Border_X_Offset)
			Platform.X_Pos = Config::Border_X_Offset;
		Platform.Redraw(HWnd);
		break;
	case EKT_Right:
		Platform.X_Pos += Platform.X_Step;
		if (Platform.X_Pos >= Config::Max_X_Pos - Platform.Width + 1)
			Platform.X_Pos = Config::Max_X_Pos - Platform.Width + 1;
		Platform.Redraw(HWnd);
		break;
	case EKT_Space:
		break;
	default:
		break;
	}

	return 0;
}

int CEngine::On_Timer()
{
	Ball.Move(HWnd, &Level, Platform.X_Pos, Platform.Width);

	Level.Active_Brick.Act(HWnd);

	return 0;
}


/*
class Dot
{
	int X, Y;
	void Draw();
};
class Line
{
	int X1, X2, Y1, Y2;
	void Draw();
	void Get_Length();
};
class Circle
{
	int X, X, Radius;
	void Draw();
	void Get_Length();
	void Get_Square();
};
class Rectangle
{
	int X1, X2, Y1, Y2;
	void Draw();
	void Get_Perimeter();
	void Get_Square();
};*/