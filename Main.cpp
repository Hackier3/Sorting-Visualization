#include <iostream>
#include <vector>
#include <raylib.h>
#include "Sorts.h"
#include "Animation.h"

using namespace std;

int main()
{
	Animation o;
	SetTargetFPS(o.FPS);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(o.screenWidth, o.screenHeight, "Visualization of Sorting Algorithms");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BACKGROUND);
		
		if (o.isRandomizeArray)
		{
			o.randomizeArray(o.vec);
			o.isRandomizeArray = false;
			o.isShowMenuScreen = true;
		}

		else if (o.isShowMenuScreen)
		{
			o.showMenuScreen();
			o.checkAlgorithm();
		}

		else if (o.isExitMenuOpen)
		{ 
			o.exitMenu(o.vec);
			o.drawArray(o.vec);
		}

		EndDrawing();
	}
	CloseWindow;

	return 0;
}
