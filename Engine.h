#pragma once

#include "CPlatform.h"
#include "CBorder.h"
#include "CBall.h"

enum EKey_Type { EKT_Left, EKT_Right, EKT_Space };

int const Timer_ID = WM_USER + 1;

class CEngine
{	
public:
	CEngine();
	void Init_Engine(HWND &hWnd);
	void Draw_Frame(HDC &hdc, RECT& paint_area);
	int On_Key_Down(EKey_Type key_type);
	int On_Timer();
		
private:
	HWND HWnd;

	CBall Ball;
	CLevel Level;
	CPlatform Platform;
	CBorder Border;
};