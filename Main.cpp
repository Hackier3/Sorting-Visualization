#include <iostream>
#include <vector>
#include <raylib.h>
#include "Sorts.h"
#include "Animation.h"
#include <string>

using namespace std;

int main()
{
	Animation o;
	SetTargetFPS(o.FPS);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(o.screenWidth, o.screenHeight, "Visualization of Sorting Algorithms");

	while (!WindowShouldClose())
	{
		if (o.isRandomizeArray)
			o.randomizeArray(o.arr);

		BeginDrawing();
		ClearBackground(BLACK);

		if (o.isShowMenuScreen)
			o.showMenuScreen();

		if (!o.isShowMenuScreen)
			o.isNumberPressed();

		EndDrawing();
	}
	CloseWindow;

	return 0;
}
