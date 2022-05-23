#include <iostream>
#include <vector>
#include <raylib.h>
#include "AlgorytmySort.h"

using namespace std;

int main()
{
	int constexpr ScreenWidth = 1200;
	int constexpr ScreenHeight = 800;
	int constexpr MinWindowWidth = 500;
	int constexpr MinWindowHeight = 800;
	int constexpr FPS = 120;

	SetTargetFPS(FPS);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(ScreenWidth, ScreenHeight, "Visualization of Sorting Algorithms");

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(GREEN);

		EndDrawing();
	}
	CloseWindow;

	/// ////////////////////

	AlgorytmySort doPosortowania;

	vector <int> vec = { 6,5,4,3,2,1 };

	doPosortowania.drukuj(vec);
	doPosortowania.sortuj_scalajac(vec, 0, vec.size() - 1);
	doPosortowania.drukuj(vec);

	return 0;
}

///////////////////////////////////////
