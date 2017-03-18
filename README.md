# TSP Genetic Algorithm #

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/7f6b74abf0924e6099ceec57eb8151c3)](https://www.codacy.com/app/suddir/TSP?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=suddi/TSP&amp;utm_campaign=Badge_Grade)
[![license](https://img.shields.io/github/license/suddi/TSP.svg?maxAge=2592000)](https://github.com/suddi/TSP/blob/master/LICENSE)

This is a solution to the Travelling Salesman Problem using a genetic algorithm implementation.
This TSP program requires C++11.

The application operates as two working parts:

1. **Map Generation**
1. **Solution**


### Map Generation ###

To generate a map, we can start off by setting values in [`config.h`](config.h).
Here the relevant variables are `MAP_FILE`, `MAP_SIZE`, `NUM_CITIES`, `CITY_SYMBOL` and `EMPTY_SYMBOL`.

After entering the settings we can compile the application by:

    $ make

Now, to generate a map with the settings:

    $ ./tsp createMap

### Solution ###

Once a map has been generated, we can proceed to solve it.
We can again set up the settings as desired in [`config.h`](config.h).

If the settings are changed, we will need to compile the application again:

    $ make

To run the solution:

    $ ./tsp solveMap 
