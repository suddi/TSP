/*
AUTHOR: Sudharshan RAVINDRAN
PROJECT: TSP
*/

#ifndef CONFIGURATION
#define CONFIGURATION

// The filename for the map to be generated/read.
const char MAP_FILE[] = "input.txt";
// Size of the map to be created and read.
// Given as an integer array: { WIDTH, HEIGHT }
const int MAP_SIZE[2] = { 100, 100 };
// Number of cities to be created on the map.
//
// Make sure there is enough space to place the cities on the map by
// setting MAP_SIZE
const int NUM_CITIES = 10;

// The character to signify a city on the map.
const char CITY_SYMBOL = 'X';
// The character to signify an empty spot on the map.
const char EMPTY_SYMBOL = '#';

// Number of tours to be generated.
const int POPULATION_SIZE = 50;
// This is the selection pool for generating parents for crossover.
// It is recommended to keep GENE_POOL < 10.
//
// If GENE_POOL > POPULATION then GENE_POOL in the program will be taken
// as POPULATION, this will lead to the same parent being used in every
// crossover and thus will not lead to good results.
const int GENE_POOL = 5;
// MUTATION is the percentage chance of a mutation in the tours.
// The number should be between 0 - 1.
//
// If MUTATION = 1, there will be a mutation in every destination in a tour.
const double MUTATION = 0.15;

// Number of generations to evolve the population.
const int NUM_GENERATIONS = 100;

enum DISTANCE_FUNCTION { MANHATTAN, EUCLIDEAN };
const DISTANCE_FUNCTION DIST_FUNC = EUCLIDEAN;

#endif
