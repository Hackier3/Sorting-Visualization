#include <iostream>
#include <raylib.h>
#include "Animation.h"
// Pillar colors
#define NORMAL 0
#define SORTED 1
#define SELECTED 2

using namespace std;

// Funkcja wizualizujaca kolejne wartosci w tablicy
void Animation::drawArray(vector<pair<int, int>> arr)
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

// Funkcja przypisuj¹ca liczbom w wektorze losowe wartosci
void Animation::randomizeArray(vector<pair<int, int>>& arr)
{
	for (int i = 0; i < numberOfPillars; i++)
		arr[i] = { GetRandomValue(10, minWindowHeight), NORMAL };
	isRandomizeArray = false;
}

// Funkcja pokazujaca ekran startowy
void Animation::showMenuScreen()
{
	drawArray(arr);
}

// Funkcja aktualizujaca kolory pilarow
Color Animation::findColorForPillar(int pillarState)
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