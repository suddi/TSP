/*
AUTHOR: Sudharshan RAVINDRAN
PROJECT: TSP
*/

#include "manager.h"


void Manager::readMap() {
    ifstream fin(MAP_FILE);
    for (int i = MAP_SIZE[1] - 1; i > -1; i--) {
        for (int j = 0; j < MAP_SIZE[0]; j++) {
            char value;
            fin >> value;
            if (value == CITY_SYMBOL)
                cities.push_back(City(cities.size(), j, i));
        }
    }
}


void Manager::addCity(int x, int y) {
    cities.push_back(City(cities.size(), x, y));
}


City Manager::getCity(int index) {
    return cities.at(index);
}


int Manager::numCities() {
    return cities.size();
}


void Manager::printCities(int index) {
    if (index != -1)
        cout << cities.at(index).print() << endl;
    else {
        for (auto city : cities)
            cout << city.print() << endl;
    }
}


void Manager::generateTours() {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        Tour tour;
        for (int j = 0; j < cities.size(); j++)
            tour.addCity(&cities.at(j));
        tour.randomize();
        tours.push_back(tour);
    }
}


Tour Manager::getTour(int index) {
    return tours.at(index);
}


int Manager::numTours() {
    return tours.size();
}


void Manager::printTours(int index) {
    if (index != -1)
        cout << tours.at(index).print() << endl;
    else {
        for (auto tour : tours)
            cout << tour.print() << endl;
    }
}


Tour Manager::getFittest() {
    Tour fittest = tours.at(0);

    for (int i = 1; i < tours.size(); i++) {
        if (fittest.calcDistance() > tours.at(i).calcDistance())
            fittest = tours.at(i);
    }
    return fittest;
}


City* Manager::getTourCity(int tourIndex, int cityIndex) {
    return tours.at(tourIndex).getCity(cityIndex);
}


void Manager::evolve() {
    vector<Tour> evolvedTours;

    evolvedTours.push_back(getFittest());

    for (int i = 1; i < tours.size(); i++)
        evolvedTours.push_back(crossover(selection(), selection()));

    tours.clear();
    for (auto tour : evolvedTours)
        tours.push_back(tour);
    evolvedTours.clear();
}


Tour Manager::selection() {
    int population = tours.size();
    int genePool = GENE_POOL < population ? GENE_POOL : population;
    genePool = genePool > 1 ? genePool : 1;

    int tour = rand() % population;
    int distance = tours.at(tour).calcDistance();
    for (int i = 1; i < genePool; i++) {
        int newTour = rand() % population;
        int newDistance = tours.at(newTour).calcDistance();

        if (distance > newDistance) {
            tour = newTour;
            distance = newDistance;
        }
    }

    return tours.at(tour);
}


Tour Manager::crossover(Tour parent1, Tour parent2) {
    int  numCities = cities.size();
    int  positions[numCities];
    bool city_index[numCities];

    int start = rand() % numCities;
    int end   = rand() % numCities;

    for (int i = 0; i < numCities; i++) {
        city_index[i] = false;

        if (start < end && (i > start && i < end))
            positions[i] = parent1.getCity(i)->getId();
        else if (start > end && (i > start || i < end))
            positions[i] = parent1.getCity(i)->getId();
        else
            positions[i] = parent2.getCity(i)->getId();
    }

    Tour child;
    for (int i = 0; i < numCities; i++) {
        if (!city_index[positions[i]]) {
            child.addCity(&cities.at(positions[i]));
            city_index[positions[i]] = true;
        }
        else {
            for (int j = 0; j < numCities; j++) {
                int index = parent2.getCity(j)->getId();
                if (!city_index[index]) {
                    child.addCity(&cities.at(index));
                    city_index[index] = true;
                    break;
                }
            }
        }
    }

    child.mutate();
    return child;
}
