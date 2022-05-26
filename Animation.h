#pragma once
#include <vector>

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

		// Pozosta³e specyfikacje
		const int FPS = 120;
		const int numberOfPillars = 100;

		vector<pair<int, int>> arr = vector<pair<int,int>>(numberOfPillars);

		//void sortArray();
		void drawArray(vector<pair<int, int>>);
		void randomizeArray(vector<pair<int, int>>&);
		void showMenuScreen();

		Color findColorForPillar(int pillarState);
};