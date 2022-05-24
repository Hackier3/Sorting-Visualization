#include <iostream>
#include <vector>
#include <raylib.h>
#include "AlgorytmySort.h"

using namespace std;

// Screen specifications
int constexpr screenWidth = 1200;
int constexpr screenHeight = 800;
int constexpr minWindowWidth = 500;
int constexpr minWindowHeight = 800;

// Pillars colors
int constexpr NORMAL = 0;
int constexpr SORTED = 1;
int constexpr SELECTED = 2;

// Boolean specyfications
bool isRandomizeArray = true;
bool isShowMenuScreen = true;

// Other specifications
int constexpr FPS = 120;
int numberOfPillars = 100;

vector<pair<int, int>> arr(numberOfPillars);

//void sortArray();
void drawArray(vector<pair<int, int>>arr);
void randomizeArray(vector<pair<int, int>>& arr);
void showMenuScreen();

Color findColorForPillar(int pillarState);

int main()
{
	SetTargetFPS(FPS);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(screenWidth, screenHeight, "Visualization of Sorting Algorithms");

	while (!WindowShouldClose())
	{
		if (isShowMenuScreen)
			showMenuScreen();

		if (isRandomizeArray)
			randomizeArray(arr);

		BeginDrawing();
		ClearBackground(BLACK);
		EndDrawing();
	}
	CloseWindow;

	return 0;
}

// Funkcja wizualizujaca kolejne wartosci w tablicy
void drawArray(vector<pair<int, int>> arr)
{
	int frame = 0;
	const int frameWidth = 2;
	float BarWidth = (float)(GetScreenWidth() - frameWidth * numberOfPillars) / numberOfPillars;

	for (int i = 0;
		i < numberOfPillars;
		i++, frame += frameWidth)
	{
		Color color = findColorForPillar(arr[i].second);

		// Podaje ( { wspX skad mam zaczynac rysowac, wspY skad mam zaczac rysowac }, { podaje szerokosc slupka, a tu wysokosc }, { kolor } )
		DrawRectangleV(Vector2{ (float)i * BarWidth + frame, (float)GetScreenHeight() - arr[i].first },
			Vector2{ BarWidth, (float)arr[i].first },
			color);
	}
}

// Funkcja przypisująca liczbom w wektorze losowe wartosci
void randomizeArray(vector<pair<int, int>>& arr)
{
	for (int i = 0; i < numberOfPillars; i++)
		arr[i] = { GetRandomValue(10, minWindowHeight), NORMAL };
	isRandomizeArray = false;
}

// Funkcja pokazujaca ekran startowy
void showMenuScreen()
{
	drawArray(arr);
}

// Funkcja aktualizujaca kolory pilarow
Color findColorForPillar(int pillarState)
{
	switch (pillarState)
	{
	case SELECTED:
		return LIGHTGRAY;
		break;

	case SORTED:
		return GREEN;
		break;

	default:
		return MAGENTA;
		break;
	}
}