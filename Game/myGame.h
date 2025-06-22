#pragma once
#include "GameFrame.h"
#include <windows.h>
#include <iostream>
#include <string.h>
#include <Builder.h>
#include <conio.h> 
#include <cstring>

class myGame : public GameFrame
{
private:
	Builder* builder;
public:

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = 600;
		height = 800;
		fullscreen = false;
	}
	
	virtual bool Init()
	{
		builder = new Builder();
		return true;
	}

	virtual void Close() {
		delete builder;
	}

	virtual bool Tick() {
		builder->BuildHero();
		//CheckInput();
		return false;
	}

	void CheckInput() {
		//HWND hwnd = GetConsoleWindow();
		//auto c = CommandLineToArgvW();
		//auto h  = GetCommandLineW();
		if (_kbhit()) {
			std::string cmd;
			std::cin >> cmd;
			if (cmd == "resize") {
				HWND hwnd = GetConsoleWindow();
				MoveWindow(hwnd, 100, 100, 800, 600, TRUE);
			}
			else {
				std::cout << "Unknown command: " << cmd << std::endl;
			}
		}
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) 
	{
		builder->SetBulletCoordinate(x, y);
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) 
	{
		builder->DrawBullets(button, isReleased);
	}

	virtual void onKeyPressed(FRKey k) 
	{
		builder->SetCurrentSprite(k);
		builder->IsMove = true;
	}

	virtual void onKeyReleased(FRKey k) 
	{
		builder->IsMove = false;
	}

	virtual const char* GetTitle() override
	{
		return "Hello world!!!";
	}
};

