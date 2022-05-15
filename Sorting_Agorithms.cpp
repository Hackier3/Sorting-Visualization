#include <iostream>
#include <vector>

using namespace std;

/////////////////////////////////////
vector <int> sortuj_wybierajac(vector <int>&);
vector <int> sortuj_babelkowo(vector <int>&);
void drukuj(vector <int>);
/////////////////////////////////////

int main()
{
    vector <int> vec = { 4,5,4,6,2,1 };

    drukuj(vec);
    sortuj_babelkowo(vec);
    drukuj(vec);

    return 0;
}

vector <int> sortuj_wybierajac(vector <int> &vec) {

    for (int i = 0; i < vec.size(); i++)
    {
        drukuj(vec);
        int indexMin = i;

        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec.at(indexMin) > vec.at(j))
                indexMin = j;
        }

        if(vec.at(i) != vec.at(indexMin))
            swap(vec.at(i), vec.at(indexMin));
    }

    return vec;
}

vector <int> sortuj_babelkowo(vector <int> &vec) {

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size() - 1; j++)
        {
            if (vec.at(j) > vec.at(j + 1))
                swap(vec.at(j), vec.at(j + 1));
        }
    }

    return vec;
}

void drukuj(vector <int> vec) {

    for (auto elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}