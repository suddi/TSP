/*
AUTHOR: Sudharshan RAVINDRAN
PROJECT: TSP
*/

#include "map.h"


Map::Map() {
    map = new char*[MAP_SIZE[1]];
    for (int i = 0; i < MAP_SIZE[1]; i++) {
        map[i] = new char[MAP_SIZE[0]];
        for (int j = 0; j < MAP_SIZE[0]; j++) {
            map[i][j] = EMPTY_SYMBOL;
        }
    }
}


void Map::addCities() {
    for (int i = 0; i < NUM_CITIES; i++) {
        int x, y;
        do {
            x = rand() % MAP_SIZE[0];
            y = rand() % MAP_SIZE[1];
        } while (map[y][x] !=EMPTY_SYMBOL);
        map[y][x] = CITY_SYMBOL;

        cities.push_back(City(i, x, y));
    }
}


void Map::saveMap() {
    ofstream fout(MAP_FILE);
    if (fout.is_open()) {
        for (int i = MAP_SIZE[1] - 1; i > -1; i--) {
            for (int j = 0; j < MAP_SIZE[0]; j++) {
                fout << map[i][j];
            }
            fout << endl;
        }

        fout << endl << "There are " << cities.size() << " cities at:" << endl;
        for (auto city : cities)
            fout << city.print() << endl;
    }
}
