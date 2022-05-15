#include <iostream>
#include <vector>

using namespace std;

/////////////////////////////////////                ctr + k + d	znajdowanie sciezki, gra
vector <int> sortuj_zliczajac(vector <int>&);
vector <int> sortuj_wstawiajac(vector <int>&);
vector <int> sortuj_wybierajac(vector <int>&);
vector <int> sortuj_babelkowo(vector <int>&);
void drukuj(vector <int>);
/////////////////////////////////////

int main()
{
	vector <int> vec = { 4,5,4,6,2,1 };

	drukuj(vec);
	sortuj_zliczajac(vec);
	drukuj(vec);

	return 0;
}

///////////////////////////////////////
vector <int> sortuj_zliczajac(vector <int>& vec)
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
	for (int i = najmniejsza; i <= najwieksza; i++) {
		ileLiczb.at(i) = 0;
	}

	//zliczam ilość wystąpień kolejnych liczby
	for (int i = 0; i < vec.size(); i++)
		ileLiczb.at(vec.at(i))++;

	for (int i = najmniejsza; i <= najwieksza; i++)
		for (static int licznik = 0;
			ileLiczb.at(i) > 0;
			ileLiczb.at(i)--, licznik++)
			vec.at(licznik) = i;

	return vec;
}

vector <int> sortuj_wstawiajac(vector <int>& vec)
{
	for (int i = 1; i < vec.size(); i++)
		for (int j = i - 1, k = i; 
			j >= 0; 
			j--, k--)
			if (vec.at(k) < vec.at(j))
				swap(vec.at(k), vec.at(j));

	return vec;
}

vector <int> sortuj_wybierajac(vector <int>& vec)
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

	return vec;
}

vector <int> sortuj_babelkowo(vector <int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
		for (int j = 0; j < vec.size() - 1; j++)
			if (vec.at(j) > vec.at(j + 1))
				swap(vec.at(j), vec.at(j + 1));

	return vec;
}

void drukuj(vector <int> vec)
{
	for (auto elem : vec) {
		cout << elem << " ";
	}
	cout << endl;
}