#include <iostream>
#include <raylib.h>
#include "Animation.h"
#include <string>
#include <conio.h>

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
#define col GREEN
	Font fontRegular = LoadFont("");
	int posY = 80;
	int fontSize = 40;
	const char* headerName = "Select a sorting algorithm: 0-9";

	// Tekst g³owny
	int textWidth = MeasureTextEx(fontRegular, headerName, fontSize, fontSize / 10).x;
	DrawText(headerName, GetScreenWidth() / 2 - textWidth / 2, posY, fontSize, col);
	fontSize = 25;
	posY += 170;

	////////////////////////////////////
	for (int i = 0; i < 9; i++)
	{
		textWidth = MeasureTextEx(fontRegular, algorithmsNames[i], fontSize, fontSize / 10).x;

		if (i % 3 == 0)
			DrawText(algorithmsNames[i], GetScreenWidth() / 5 - textWidth / 2, posY, fontSize, col);
		else if (i % 3 == 1)
			DrawText(algorithmsNames[i], GetScreenWidth() / 2 - textWidth / 2, posY, fontSize, col);
		else if (i % 3 == 2) {
			DrawText(algorithmsNames[i], GetScreenWidth() - GetScreenWidth() / 5 - textWidth / 2, posY, fontSize, col);
			posY += 140;
		}
	}

	/////////////////////////////////////
	const char* fontName9 = "Costam sort";
	textWidth = MeasureTextEx(fontRegular, fontName9, fontSize, fontSize / 10).x;
	DrawText(fontName9, GetScreenWidth() / 2 - textWidth / 2, posY, fontSize, col);

	// Action before pressed key
	IsAnyKeyPressed();

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

void Animation::IsAnyKeyPressed()
{
	static bool keyPressed = false;

	while (!IsKeyReleased)
	{
		system("pause");
	}
}