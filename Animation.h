#pragma once
#include <vector>
#include <raylib.h>
#include <chrono>
#include <thread>
#define HEADER GREEN

using namespace std;

class Animation
{
public:
	// Specyfikacje ekranu
	const int screenWidth = 1200;
	const int screenHeight = 800;
	const int minWindowWidth = 500;
	const int minWindowHeight = 800;

	// Specyfikacje boolowskie
	bool isRandomizeArray = true;
	bool isShowMenuScreen = true;
	bool isExitMenuOpen = false;

	// Pozosta³e specyfikacje
	const int FPS = 120;
	const int numberOfPillars = 100;

	vector<pair<int, int>> vec = vector<pair<int, int>>(numberOfPillars);
	const char* algorithmsNames[10] = { "Bubble sort",
										"Select sort",
										"Insertion sort",
										"Counting sort",
										"Merge sort",
										"Work in progress",
										"Work in progress",
										"Work in progress",
										"Work in progress",
										"Work in progress" };

	// FUNKCJE
	void drawArray(vector<pair<int, int>>);
	void randomizeArray(vector<pair<int, int>>&);
	void showMenuScreen();
	void checkAlgorithm();
	void displayAnimation(vector<pair<int, int>>);
	void finalAnimation(vector<pair<int, int>>&);
	void exitMenu(vector<pair<int, int>>vec);
	void sleep(int);
	void multipleColorAnimation(vector<pair<int, int>>, int sleepValue, int index1, int index2 = -1, int index3 = -1);	//ile kolorow, index1, index2, index3, index4

	Color findColor(int);
};