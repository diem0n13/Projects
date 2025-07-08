
#include "CPlatform.h"

CPlatform::CPlatform() : X_Pos(Config::Border_X_Offset), X_Step(Config::Global_Scale * 2), Width(28), Inner_Width(21), Circle_pen(0), Inner_pen(0), Highlight_pen(0), Circle_brush(0), Inner_brush(0), Platform_rect{}, Prev_Platform_rect{}
{
}
void CPlatform::Init()
{
	Highlight_pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	Config::InitColor(151, 0, 0, Circle_pen, Circle_brush);
	Config::InitColor(0, 128, 192, Inner_pen, Inner_brush);
}

void CPlatform::Redraw(HWND& hWnd)
{
	Prev_Platform_rect = Platform_rect;

	Platform_rect.left = X_Pos * Config::Global_Scale;
	Platform_rect.top = Config::Platform_Y_Pos * Config::Global_Scale;
	Platform_rect.right = Platform_rect.left + Width * Config::Global_Scale;//(OffsetX + Platform_rect.left) + Platform_Width * Global_Scale;
	Platform_rect.bottom = Platform_rect.top + Height * Config::Global_Scale;

	InvalidateRect(hWnd, &Prev_Platform_rect, FALSE);
	InvalidateRect(hWnd, &Platform_rect, FALSE);
}

void CPlatform::Draw(HDC &hdc, RECT& paint_area)
{
	int x = X_Pos, y = Config::Platform_Y_Pos;

	RECT intersection_Rect;
	if (!IntersectRect(&intersection_Rect, &paint_area, &Platform_rect))
		return;
	SelectObject(hdc, Config::BG_pen);
	SelectObject(hdc, Config::BG_brush);
	Rectangle(hdc, Prev_Platform_rect.left, Prev_Platform_rect.top, Prev_Platform_rect.right, Prev_Platform_rect.bottom);

	SelectObject(hdc, Circle_pen);
	SelectObject(hdc, Circle_brush);

	Ellipse(hdc, x * Config::Global_Scale, y * Config::Global_Scale, (x + Size_Circle) *
		Config::Global_Scale, (y + Size_Circle) * Config::Global_Scale);
	Ellipse(hdc, (x + Inner_Width) * Config::Global_Scale, y * Config::Global_Scale,
		(Inner_Width + x + Size_Circle) * Config::Global_Scale, (y + Size_Circle) * Config::Global_Scale);

	SelectObject(hdc, Highlight_pen);
	Arc(hdc, (x + 1) * Config::Global_Scale, (y + 1) * Config::Global_Scale, (x + Size_Circle - 1) * Config::Global_Scale,
		(y + Size_Circle - 1) * Config::Global_Scale, (x + 1 + 1) * Config::Global_Scale, (y + 1) * Config::Global_Scale,
		(x + 1) * Config::Global_Scale, (y + 1 + 2) * Config::Global_Scale);

	SelectObject(hdc, Inner_pen);
	SelectObject(hdc, Inner_brush);

	RoundRect(hdc, (x + 4) * Config::Global_Scale, (y + 1) * Config::Global_Scale,
		(x + 4 + Inner_Width - 1) * Config::Global_Scale, (y + 1 + 5) * Config::Global_Scale,
		3 * Config::Global_Scale, 3 * Config::Global_Scale);
}

