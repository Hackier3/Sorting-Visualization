#include <iostream>
#include "AlgorytmySort.h"

using namespace std;

void AlgorytmySort::sortuj_scalajac(vector <int>& vec, int lewa, int prawa)
{
	if (lewa != prawa)
	{
		int srodek = (prawa + lewa) / 2;
		sortuj_scalajac(vec, lewa, srodek);
		sortuj_scalajac(vec, srodek + 1, prawa);
		scal(vec, lewa, srodek, prawa);
	}
}

void AlgorytmySort::scal(vector <int>& vec, int lewa, int srodek, int prawa)
{
	//deklaruje rozmiar ka¿dego z podvectorow
	int rozmL = srodek - lewa + 1;
	int rozmP = prawa - srodek;

	//deklaruje vectory pomocniecze dla lewej oraz prawej strony
	vector <int> vecL(rozmL);
	vector <int> vecP(rozmP);

	//przypisuje wartosc vectorom pomocniczym
	for (int i = 0; i < rozmL; i++)
		vecL.at(i) = vec.at(i + lewa);

	for (int i = 0; i < rozmP; i++)
		vecP.at(i) = vec.at(i + srodek + 1);

	//deklaruje wskazniki do pomocniczych tablic, aby moc porownywac w nich elementy
	int wskaznikL = 0;
	int wskaznikP = 0;
	int indexVec;

	//porownuje elementy z pomocniczych vetorow, aby pomosrtowac glowny vector
	for (indexVec = lewa; wskaznikL < rozmL && wskaznikP < rozmP; indexVec++)
	{
		if (vecL[wskaznikL] <= vecP[wskaznikP])
			vec[indexVec] = vecL[wskaznikL++];
		else
			vec[indexVec] = vecP[wskaznikP++];
	}

	//przepisuje elementy do glownego vectora z niewykorzystanego vectora pomocniczego
	while (wskaznikL < rozmL)
		vec[indexVec++] = vecL[wskaznikL++];

	while (wskaznikP < rozmP)
		vec[indexVec++] = vecP[wskaznikP++];
}

void AlgorytmySort::sortuj_zliczajac(vector <int>& vec)
{
	int najwieksza = vec.at(0);
	int najmniejsza = vec.at(0);

	//szukam najmniejszej oraz najwiekszej liczby ze zbioru liczb do posortowania
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec.at(i) > najwieksza)
			najwieksza = vec.at(i);
		if (vec.at(i) < najmniejsza)
			najmniejsza = vec.at(i);
	}

	vector <int> ileLiczb(najwieksza + 1);

	//zeruje wartosc vectora zliczajacego ilosc wystapienia kolejnych liczb
	for (int i = najmniejsza; i <= najwieksza; i++)
		ileLiczb.at(i) = 0;

	//zliczam iloœæ wyst¹pieñ kolejnych liczby
	for (int i = 0; i < vec.size(); i++)
		ileLiczb.at(vec.at(i))++;

	for (int i = najmniejsza; i <= najwieksza; i++)
		for (static int licznik = 0;
			ileLiczb.at(i) > 0;
			ileLiczb.at(i)--, licznik++)
			vec.at(licznik) = i;
}

void AlgorytmySort::sortuj_wstawiajac(vector <int>& vec)
{
	for (int i = 1; i < vec.size(); i++)
		for (int j = i - 1, k = i;
			j >= 0;
			j--, k--)
			if (vec.at(k) < vec.at(j))
				swap(vec.at(k), vec.at(j));
}

void AlgorytmySort::sortuj_wybierajac(vector <int>& vec)
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
void AlgorytmySort::sortuj_babelkowo(vector <int>& vec)
{
	static int i = vec.size();

	for (int j = 0; j < i - 1; j++)
		if (vec.at(j) > vec.at(j + 1))
			swap(vec.at(j), vec.at(j + 1));

	if (i != 1)
	{
		i--;
		sortuj_babelkowo(vec);
	}

	if (i != vec.size())
		i = vec.size();
}

void AlgorytmySort::drukuj(vector <int> vec)
{
	for (auto elem : vec) {
		cout << elem << " ";
	}
	cout << endl;
}