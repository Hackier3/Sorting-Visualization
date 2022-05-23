#pragma once
#include <vector>

using namespace std;

class SortAlgorithms
{
	public:
		void merge(vector <int>&, int, int, int);
		void merge_sort(vector <int>&, int, int); //nie potrafie dodac wartosci domyslnych argumentow, tak aby jedynym argumentem byl vector z nieposortowanymi elementami. Gdy deklaruje right = vec.size() - 1 wyœwietla siê b³¹d
		void counting_sort(vector <int>&);
		void insertion_sort(vector <int>&);
		void select_sort(vector <int>&);
		void bubble_sort(vector <int>&);
		void printData(vector <int>);
};