/*
AUTHOR: Sudharshan RAVINDRAN
PROJECT: TSP
*/

#include <fstream>
#include <vector>

#include "config.h"
#include "city.h"

using namespace std;


class Map {
public:
    Map();

    void addCities();
    void saveMap();

private:
    char **map;

    vector<City> cities;
};
