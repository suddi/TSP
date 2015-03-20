/*
AUTHOR: Sudharshan RAVINDRAN
PROJECT: TSP
*/

#ifndef CITY
#define CITY

#include <cmath>
#include <cstdlib>
#include <string>

#include "config.h"

using namespace std;


class City {
public:
    City() {};
    City(int num, int i, int j): id(num), x(i), y(j) {};

    int getX();
    int getY();
    int getId();

    double distanceTo(City *city);

    string print();

private:
    int id, x, y;
};

#endif
