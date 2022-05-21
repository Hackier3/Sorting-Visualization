#include <iostream>
#include <vector>

using namespace std;

/////////////////////////////////////    ctr + k + d	znajdowanie sciezki, gra	http://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/msvc2019/index.php
void scal(vector <int>& vec);
void sortuj_scalajac(vector <int>&, int, int, int);
void sortuj_zliczajac(vector <int>&, int, int, int);
void sortuj_wstawiajac(vector <int>&);
void sortuj_wybierajac(vector <int>&);
void sortuj_babelkowo(vector <int>&);
void drukuj(vector <int>);
/////////////////////////////////////

int main()
{
	vector <int> vec = { 6,5,4,3,2,1 };

	drukuj(vec);
	sortuj_babelkowo(vec);
	drukuj(vec);

	return 0;
}

///////////////////////////////////////
void sortuj_scalajac(vector <int>& vec, int lewa, int srodek, int prawa)
{

}

void scal(vector <int>& vec)
{

}

void sortuj_zliczajac(vector <int>& vec)
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

	//zliczam ilość wystąpień kolejnych liczby
	for (int i = 0; i < vec.size(); i++)
		ileLiczb.at(vec.at(i))++;

	for (int i = najmniejsza; i <= najwieksza; i++)
		for (static int licznik = 0;
			ileLiczb.at(i) > 0;
			ileLiczb.at(i)--, licznik++)
			vec.at(licznik) = i;
}

void sortuj_wstawiajac(vector <int>& vec)
{
	for (int i = 1; i < vec.size(); i++)
		for (int j = i - 1, k = i;
			j >= 0;
			j--, k--)
			if (vec.at(k) < vec.at(j))
				swap(vec.at(k), vec.at(j));
}

void sortuj_wybierajac(vector <int>& vec)
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
void sortuj_babelkowo(vector <int>& vec)
{
	static int i = vec.size();

	for (int j = 0; j < i - 1; j++)
		if (vec.at(j) > vec.at(j + 1))
			swap(vec.at(j), vec.at(j + 1));

	if (i != 1)
	{
		i--;	sortuj_babelkowo(vec);
	
}
		
	if (i != vec.size())
		i = vec.size();
}

void drukuj(vector <int> vec)
{
	for (auto elem : vec) {
		cout << elem << " ";
	}
	cout << endl;
}