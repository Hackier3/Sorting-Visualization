#pragma once
#include <vector>

#define BACKGROUND BLACK

// Pillar colors
#define NORMAL 0
#define SORTED 1
#define SELECTED 2
#define EXITTEXT 3
#define SWAP 4
#define SWAP2 5

using namespace std;

class Sorts
{
public:
	void merge(vector<pair<int, int>>&, int, int, int);
	void merge_sort(vector<pair<int, int>>&, int, int);
	void counting_sort(vector<pair<int, int>>&);
	void insertion_sort(vector<pair<int, int>>&);
	void select_sort(vector<pair<int, int>>&);
	void bubble_sort(vector<pair<int, int>>&);
	void printData(vector<int>&);

private:
	int counter = 0;
};