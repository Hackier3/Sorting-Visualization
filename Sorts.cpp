#include <iostream>
#include "Sorts.h"
#include "Animation.h"
#include <raylib.h>

using namespace std;

Animation o;

void Sorts::merge_sort(vector<pair<int, int>>& vec, int left, int right)
{
	if (left != right)
	{
		int mid = (right + left) / 2;
		merge_sort(vec, left, mid);
		merge_sort(vec, mid + 1, right);
		merge(vec, left, mid, right);
	}

	if (right == o.numberOfPillars - 1 && left == 0)
		o.finalAnimation(vec);
}

void Sorts::merge(vector<pair<int, int>>& vec, int left, int mid, int right)
{
	// Deklaruje rozmiar ka¿dego z podvectorow
	int sizeL = mid - left + 1;
	int sizeR = right - mid;

	// Deklaruje vectory pomocniecze dla lewej oraz prawej strony
	vector<int> vecL(sizeL);
	vector<int> vecP(sizeR);

	// Przypisuje wartosc vectorom pomocniczym
	for (int i = 0; i < sizeL; i++)
		vecL.at(i) = vec.at(i + left).first;

	for (int i = 0; i < sizeR; i++)
		vecP.at(i) = vec.at(i + mid + 1).first;

	// Deklaruje wskazniki do pomocniczych tablic, aby moc porownywac w nich elementy
	int indicatorL = 0;
	int indicatorR = 0;
	int indexVec;

	// Porownuje elementy z pomocniczych vetorow, aby posortowac glowny vector
	for (indexVec = left; indicatorL < sizeL && indicatorR < sizeR; indexVec++)
	{
		if (vecL[indicatorL] <= vecP[indicatorR])
			vec[indexVec].first = vecL[indicatorL++];
		else
			vec[indexVec].first = vecP[indicatorR++];

		o.multipleColorAnimation(vec, 100, indexVec, left, right);
	}

	// Przepisuje elementy do glownego vectora z niewykorzystanego vectora pomocniczego
	while (indicatorL < sizeL)
		vec[indexVec++].first = vecL[indicatorL++];

	while (indicatorR < sizeR)
		vec[indexVec++].first = vecP[indicatorR++];
}

void Sorts::counting_sort(vector<pair<int, int>>& vec)
{
	int theBiggest = vec.at(0).first;
	int theSmallest = vec.at(0).first;

	// Szukam najmniejszej oraz najwiekszej liczby ze zbioru liczb do posortowania
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec.at(i).first > theBiggest)
			theBiggest = vec.at(i).first;
		if (vec.at(i).first < theSmallest)
			theSmallest = vec.at(i).first;
	}

	vector <int> howManyNumbs(theBiggest + 1);

	// Zeruje wartosc vectora zliczajacego ilosc wystapienia kolejnych liczb
	for (int i = theSmallest; i <= theBiggest; i++)
		howManyNumbs.at(i) = 0;

	// Zliczam iloœæ wyst¹pieñ kolejnych liczby
	for (int i = 0; i < vec.size(); i++)
		howManyNumbs.at(vec.at(i).first)++;

	for (int i = theSmallest; i <= theBiggest; i++)
		while (howManyNumbs.at(i) > 0)
		{
			vec.at(counter).first = i;
			o.multipleColorAnimation(vec, 100, counter);

			howManyNumbs.at(i)--;
			counter++;
		}

	counter = 0;
	o.finalAnimation(vec);
}

void Sorts::insertion_sort(vector<pair<int, int>>& vec)
{
	int indicator = 0;

	for (int i = 1; i < vec.size(); i++)
	{
		for (int j = i - 1, k = i;
			j >= 0;
			j--, k--)
		{
			if (vec.at(k) < vec.at(j))
				swap(vec.at(k), vec.at(j));
			else
				indicator = j;

			o.multipleColorAnimation(vec, 20, i, k, indicator);
		}
	}

	o.finalAnimation(vec);
}

void Sorts::select_sort(vector<pair<int, int>>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int indexMin = i;

		for (int j = i + 1; j < vec.size(); j++)
			if (vec.at(indexMin) > vec.at(j))
				indexMin = j;

		if (vec.at(i) != vec.at(indexMin))
			swap(vec.at(i), vec.at(indexMin));

		o.multipleColorAnimation(vec, 100, i, indexMin);
	}

	o.finalAnimation(vec);
}

//REKURENCYJNIE
void Sorts::bubble_sort(vector<pair<int, int>>& vec)
{
	static int i = vec.size();
	int k = 0;

	for (int j = 0; j < i - 1; j++)
	{
		if (vec.at(j) > vec.at(j + 1))
			swap(vec.at(j), vec.at(j + 1));
		else	
			k = j;

		o.multipleColorAnimation(vec, 13, j + 1, k);
	}

	if (i != 1)
	{
		i--;
		bubble_sort(vec);
	}

	if (i != vec.size())
	{
		i = vec.size();
		o.finalAnimation(vec);
	}
}

void Sorts::printData(vector<int>& vec)
{
	for (auto elem : vec) {
		cout << elem << " ";
	}
	cout << endl;
}