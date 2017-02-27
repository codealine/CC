#!/bin/bash

g++ -c boy_implementation.cpp
g++ -c girl_implementation.cpp
g++ -c utils_implementation.cpp
g++ -c giftBasket_implementation.cpp
g++ -c luxury_implementation.cpp
g++ -c utility_implementation.cpp
g++ -c read_implementation.cpp
g++ -c essential_implementation.cpp
ar rvs library_file.a boy_implementation.o read_implementation.o essential_implementation.o giftBasket_implementation.o luxury_implementation.o utility_implementation.o utils_implementation.o girl_implementation.o
g++ main.cpp library_file.a


