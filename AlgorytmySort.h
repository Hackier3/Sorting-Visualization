#pragma once
#include <vector>

using namespace std;

class AlgorytmySort
{
	public:
		void scal(vector <int>&, int, int, int);
		void sortuj_scalajac(vector <int>&, int, int); //nie potrafie dodac wartosci domyslnych argumentow, tak aby jedynym argumentem byl vector z nieposortowanymi elementami. Gdy deklaruje prawa = vec.size() - 1 wyœwietla siê b³¹d
		void sortuj_zliczajac(vector <int>&);
		void sortuj_wstawiajac(vector <int>&);
		void sortuj_wybierajac(vector <int>&);
		void sortuj_babelkowo(vector <int>&);
		void drukuj(vector <int>);
}