/*
AUTHOR: Sudharshan RAVINDRAN
PROJECT: TSP
*/

#include <cstring>
#include <ctime>
#include <iostream>

#include "config.h"
#include "manager.h"
#include "map.h"

using namespace std;


int main(int argc, char* argv[]) {
    srand(time(0));

    if (argc > 1) {
        if (strcmp(argv[1], "createMap") == 0) {
            Map map;
            map.addCities();
            map.saveMap();
        }
        else if (strcmp(argv[1], "solveMap") == 0) {
            Manager manager;
            manager.readMap();

            manager.generateTours();
            cout << "Population: " << manager.numTours() << endl;
            cout << "Initial Fittest Tour: " << manager.getFittest().print() << endl;
            cout << "Initial Distance: " << manager.getFittest().calcDistance() << endl;

            int generations = NUM_GENERATIONS > 0 ? NUM_GENERATIONS : 0;
            for (int i = 0; i < generations; i++)
                manager.evolve();

            cout << "Final Fittest Tour: " << manager.getFittest().print() << endl;
            cout << "Final Distance: " << manager.getFittest().calcDistance() << endl;
        }
    }

    return 0;
}
