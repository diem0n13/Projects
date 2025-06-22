#pragma once
class RectangleH
{
private:
	float _leftTopX = 0.0f;
	float _leftTopY = 0.0f;

	float _rightBottomX = 0.0f;
	float _rightBottomY = 0.0f;
public:
	RectangleH(float leftTopX, float leftTopY, float rightBottomX, float rightBottomY);

	void setLeftTopX(float);
	void setLeftTopY(float);
	void setRightBottomX(float);
	void setRightBottomY(float);

	int getLeftTopX();
	int getLeftTopY();
	int getRightBottomX();
	int getRightBottomY();

	void SetPositionY(bool isUp, const int& step);
	void SetPositionX(bool toLeft, const int& step);
};

