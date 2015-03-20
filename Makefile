tsp: main.o city.o manager.o map.o tour.o
	g++ -std=c++11 -o tsp main.o city.o manager.o map.o tour.o

main.o: main.cpp config.h manager.h map.h
	g++ -std=c++11 -c main.cpp

city.o: city.cpp city.h config.h
	g++ -std=c++11 -c city.cpp

manager.o: manager.cpp manager.h config.h city.h tour.h
	g++ -std=c++11 -c manager.cpp

map.o: map.cpp map.h config.h city.h
	g++ -std=c++11 -c map.cpp

tour.o: tour.cpp tour.h config.h city.h
	g++ -std=c++11 -c tour.cpp
