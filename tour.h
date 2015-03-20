/*
AUTHOR: Sudharshan RAVINDRAN
PROJECT: TSP
*/

#include <algorithm>
#include <vector>

#include "city.h"
#include "config.h"

using namespace std;


class Tour {
public:
    Tour(): distance(0.0), changed(false) {};

    City* getCity(int index);
    void addCity(City *city);
    void setCity(int index, City *city);

    void randomize();
    double calcDistance();
    void mutate();

    string print();

private:
    vector<City*> tour;

    double distance;
    bool changed;
};
