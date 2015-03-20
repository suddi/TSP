/*
AUTHOR: Sudharshan RAVINDRAN
PROJECT: TSP
*/

#include "city.h"


int City::getId() {
    return id;
}


int City::getX() {
    return x;
}


int City::getY() {
    return y;
}


double City::distanceTo(City *city) {
    int diffX = abs(x - city->getX());
    int diffY = abs(y - city->getY());

    switch (DIST_FUNC) {
    case EUCLIDEAN:
        return sqrt((diffX * diffX) + (diffY * diffY));
    case MANHATTAN:
        return diffX + diffY;
    default:
        return sqrt((diffX * diffX) + (diffY * diffY));
    }
}


string City::print() {
    return "(" + to_string(x) + ", " + to_string(y) + ")";
}
