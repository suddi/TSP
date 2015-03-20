# TSP Genetic Algorithm #

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
