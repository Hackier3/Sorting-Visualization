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
		if (o.isRandomizeArray)
			o.randomizeArray(o.arr);

		if (o.isShowMenuScreen)
			o.showMenuScreen();

		BeginDrawing();
		ClearBackground(BLACK);
		EndDrawing();
	}
	CloseWindow;

	return 0;
}
