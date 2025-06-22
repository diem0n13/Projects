#include "RectangleN.h"

RectangleN::RectangleN(int leftTopX, int leftTopY, int rightBottomX, int rightBottomY, unsigned int timer)
{
	LeftTopX = leftTopX;
	LeftTopY = leftTopY;
	RightBottomX = rightBottomX;
	RightBottomY = rightBottomY;
	PTimer = timer;
}

void RectangleN::SetRectangle(const int& step)
{
	LeftTopY += step;
	RightBottomY += step;
}