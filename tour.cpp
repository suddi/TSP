/*
AUTHOR: Sudharshan RAVINDRAN
PROJECT: TSP
*/

#include "tour.h"


void Tour::addCity(City *city) {
    tour.push_back(city);
    changed = true;
}


City* Tour::getCity(int index) {
    return tour.at(index);
}


void Tour::setCity(int index, City *city) {
    tour.at(index) = city;
    changed = true;
}


void Tour::randomize() {
    random_shuffle(tour.begin(), tour.end());
}


double Tour::calcDistance() {
    if (changed) {
        for (int i = 0; i < tour.size(); i++) {
            City *from = tour.at(i);
            City *to;

            if (i + 1 < tour.size())
                to = tour.at(i + 1);
            else
                to = tour.at(0);

            distance += from->distanceTo(to);
        }
        changed = false;
    }

    return distance;
}


void Tour::mutate() {
    int numTours = tour.size();
    double mutation = MUTATION < 1.0 ? MUTATION : 1.0;
    mutation = mutation > 0.0 ? mutation : 0.0;


    for (int i = 0; i < numTours; i++) {
        if (((double) rand() / (RAND_MAX)) < mutation) {
            int switchWith = rand() % numTours;

            City *temp = tour.at(i);
            tour.at(i) = tour.at(switchWith);
            tour.at(switchWith) = temp;
        }
    }

    changed = true;
}


string Tour::print() {
    string output = "";
    for (int i = 0; i < tour.size(); i++)
        output += tour.at(i)->print() + " -> ";
    return output + tour.at(0)->print();
}
