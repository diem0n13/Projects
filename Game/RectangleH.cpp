#include "RectangleH.h"
#include "cmath"

RectangleH::RectangleH(float leftTopX, float leftTopY, float rightBottomX, float rightBottomY)
{
	_leftTopX = leftTopX;
	_leftTopY = leftTopY;

	_rightBottomX = rightBottomX;
	_rightBottomY = rightBottomY;
}

void RectangleH::setLeftTopX(float leftTopX)
{
	_leftTopX = leftTopX;
}
void RectangleH::setLeftTopY(float leftTopY)
{
	_leftTopY = leftTopY;
}
void RectangleH::setRightBottomX(float rightBottomX)
{
	_rightBottomX = rightBottomX;
}

void RectangleH::setRightBottomY(float rightBottomY)
{
	_rightBottomY = rightBottomY;
}

int RectangleH::getLeftTopX()
{
	return (int)round(_leftTopX);
}
int RectangleH::getLeftTopY()
{
	return (int)round(_leftTopY);
}
int RectangleH::getRightBottomX()
{
	return (int)round(_rightBottomX);
}
int RectangleH::getRightBottomY()
{
	return (int)round(_rightBottomY);
}

void RectangleH::SetPositionY(bool isUp, const int& step)
{
	if (isUp)
	{
		_leftTopY -= step;
		_rightBottomY -= step;
	}
	else
	{
		_leftTopY += step;
		_rightBottomY += step;
	}
}

void RectangleH::SetPositionX(bool toLeft, const int& step)
{
	if (toLeft)
	{
		_leftTopX -= step;
		_rightBottomX -= step;
	}
	else
	{
		_leftTopX += step;
		_rightBottomX += step;
	}
}