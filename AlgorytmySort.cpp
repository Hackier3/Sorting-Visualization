#include <iostream>
#include "AlgorytmySort.h"

using namespace std;

void SortAlgorithms::merge_sort(vector <int>& vec, int left, int right)
{
	if (left != right)
	{
		int mid = (right + left) / 2;
		merge_sort(vec, left, mid);
		merge_sort(vec, mid + 1, right);
		merge(vec, left, mid, right);
	}
}

void SortAlgorithms::merge(vector <int>& vec, int left, int mid, int right)
{
	// Deklaruje rozmiar ka¿dego z podvectorow
	int sizeL = mid - left + 1;
	int sizeR = right - mid;

	// Deklaruje vectory pomocniecze dla lewej oraz prawej strony
	vector <int> vecL(sizeL);
	vector <int> vecP(sizeR);

	// Przypisuje wartosc vectorom pomocniczym
	for (int i = 0; i < sizeL; i++)
		vecL.at(i) = vec.at(i + left);

	for (int i = 0; i < sizeR; i++)
		vecP.at(i) = vec.at(i + mid + 1);

	// Deklaruje wskazniki do pomocniczych tablic, aby moc porownywac w nich elementy
	int indicatorL = 0;
	int indicatorR = 0;
	int indexVec;

	// Porownuje elementy z pomocniczych vetorow, aby pomosrtowac glowny vector
	for (indexVec = left; indicatorL < sizeL && indicatorR < sizeR; indexVec++)
	{
		if (vecL[indicatorL] <= vecP[indicatorR])
			vec[indexVec] = vecL[indicatorL++];
		else
			vec[indexVec] = vecP[indicatorR++];
	}

	// Przepisuje elementy do glownego vectora z niewykorzystanego vectora pomocniczego
	while (indicatorL < sizeL)
		vec[indexVec++] = vecL[indicatorL++];

	while (indicatorR < sizeR)
		vec[indexVec++] = vecP[indicatorR++];
}

void SortAlgorithms::counting_sort(vector <int>& vec)
{
	int theBiggest = vec.at(0);
	int theSmallest = vec.at(0);

	// Szukam najmniejszej oraz najwiekszej liczby ze zbioru liczb do posortowania
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec.at(i) > theBiggest)
			theBiggest = vec.at(i);
		if (vec.at(i) < theSmallest)
			theSmallest = vec.at(i);
	}

	vector <int> howManyNumbs(theBiggest + 1);

	// Zeruje wartosc vectora zliczajacego ilosc wystapienia kolejnych liczb
	for (int i = theSmallest; i <= theBiggest; i++)
		howManyNumbs.at(i) = 0;

	// Zliczam iloœæ wyst¹pieñ kolejnych liczby
	for (int i = 0; i < vec.size(); i++)
		howManyNumbs.at(vec.at(i))++;

	for (int i = theSmallest; i <= theBiggest; i++)
		for (static int counter = 0;
			howManyNumbs.at(i) > 0;
			howManyNumbs.at(i)--, counter++)
			vec.at(counter) = i;
}

void SortAlgorithms::insertion_sort(vector <int>& vec)
{
	for (int i = 1; i < vec.size(); i++)
		for (int j = i - 1, k = i;
			j >= 0;
			j--, k--)
			if (vec.at(k) < vec.at(j))
				swap(vec.at(k), vec.at(j));
}

void SortAlgorithms::select_sort(vector <int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int indexMin = i;

		for (int j = i + 1; j < vec.size(); j++)
			if (vec.at(indexMin) > vec.at(j))
				indexMin = j;

		if (vec.at(i) != vec.at(indexMin))
			swap(vec.at(i), vec.at(indexMin));
	}
}

//REKURENCYJNIE
void SortAlgorithms::bubble_sort(vector <int>& vec)
{
	static int i = vec.size();

	for (int j = 0; j < i - 1; j++)
		if (vec.at(j) > vec.at(j + 1))
			swap(vec.at(j), vec.at(j + 1));

	if (i != 1)
	{
		i--;
		bubble_sort(vec);
	}

	if (i != vec.size())
		i = vec.size();
}

void SortAlgorithms::printData(vector <int> vec)
{
	for (auto elem : vec) {
		cout << elem << " ";
	}
	cout << endl;
}