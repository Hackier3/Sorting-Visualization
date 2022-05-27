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
	Font fontRegular = LoadFont("");
	int posY = 80;
#define col GREEN

	int fontSize = 40;
	const char* headerName = "Select a sorting algorithm: 0-9";
	int textWidth = MeasureTextEx(fontRegular, headerName, fontSize, fontSize / 10).x;

	// Tekst g³owny
	DrawText(headerName, GetScreenWidth() / 2 - textWidth / 2, posY, fontSize, col);
	fontSize = 25;
	posY += 170;

	// Wyswietl nazwy sortowan do wyboru
	const char* fontName0 = "0. Bubble sort";
	textWidth = MeasureTextEx(fontRegular, fontName0, fontSize, fontSize / 10).x;
	DrawText(fontName0, GetScreenWidth() / 5 - textWidth / 2, posY, fontSize, col);

	const char* fontName1 = "1. Select sort";
	textWidth = MeasureTextEx(fontRegular, fontName1, fontSize, fontSize / 10).x;
	DrawText(fontName1, GetScreenWidth() / 2 - textWidth / 2, posY, fontSize, col);

	const char* fontName2 = "2. Insertion sort";
	textWidth = MeasureTextEx(fontRegular, fontName2, fontSize, fontSize / 10).x;
	DrawText(fontName2, GetScreenWidth() - GetScreenWidth() / 5 - textWidth / 2, posY, fontSize, col);
	posY += 140;

	//////////////////////////////////////
	const char* fontName3 = "3. Counting sort";
	textWidth = MeasureTextEx(fontRegular, fontName3, fontSize, fontSize / 10).x;
	DrawText(fontName3, GetScreenWidth() / 5 - textWidth / 2, posY, fontSize, col);

	const char* fontName4 = "4. Merge sort";
	textWidth = MeasureTextEx(fontRegular, fontName4, fontSize, fontSize / 10).x;
	DrawText(fontName4, GetScreenWidth() / 2 - textWidth / 2, posY, fontSize, col);

	const char* fontName5 = "5. Costam sort";
	textWidth = MeasureTextEx(fontRegular, fontName5, fontSize, fontSize / 10).x;
	DrawText(fontName5, GetScreenWidth() - GetScreenWidth() / 5 - textWidth / 2, posY, fontSize, col);
	posY += 140;

	/////////////////////////////////////
	const char* fontName6 = "6. Costam sort";
	textWidth = MeasureTextEx(fontRegular, fontName6, fontSize, fontSize / 10).x;
	DrawText(fontName6, GetScreenWidth() / 5 - textWidth / 2, posY, fontSize, col);

	const char* fontName7 = "7. Costam sort";
	textWidth = MeasureTextEx(fontRegular, fontName7, fontSize, fontSize / 10).x;
	DrawText(fontName7, GetScreenWidth() / 2 - textWidth / 2, posY, fontSize, col);

	const char* fontName8 = "8. Costam sort";
	textWidth = MeasureTextEx(fontRegular, fontName8, fontSize, fontSize / 10).x;
	DrawText(fontName8, GetScreenWidth() - GetScreenWidth() / 5 - textWidth / 2, posY, fontSize, col);
	posY += 140;

	/////////////////////////////////////
	const char* fontName9 = "9. Costam sort";
	textWidth = MeasureTextEx(fontRegular, fontName9, fontSize, fontSize / 10).x;
	DrawText(fontName9, GetScreenWidth() / 2 - textWidth / 2, posY, fontSize, col);

	//drawArray(arr);
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