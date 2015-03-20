/*
AUTHOR: Sudharshan RAVINDRAN
PROJECT: TSP
*/

#include <fstream>
#include <iostream>
#include <vector>

#include "city.h"
#include "config.h"
#include "tour.h"

using namespace std;


class Manager {
public:
    Manager() {};

    void readMap();

    void addCity(int x, int y);
    City getCity(int index);
    int numCities();
    void printCities(int index = -1);

    void generateTours();
    Tour getTour(int index);
    int numTours();
    void printTours(int index = -1);

    Tour getFittest();
    City* getTourCity(int tourIndex, int cityIndex);

    void evolve();
    Tour selection();
    Tour crossover(Tour parent1, Tour parent2);

private:
    vector<City> cities;
    vector<Tour> tours;
};
