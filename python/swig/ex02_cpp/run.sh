#!/bin/bash

# add c++ option to compile the cpp code
#swig -c++ -python -shadow example.i
swig -python -c++ -o example_wrap.cpp example.i

#g++ -O2 -fPIC -c example.cpp
g++ -c example.cpp -o example.o -fpic -std=c++0x

#g++ -O2 -fPIC -c example_wrap.cxx -I/usr/include/python2.7
g++ -I/usr/include/python2.7 -c example_wrap.cpp -o example_wrap.o -fpic -std=c++0x

#ld -shared example_wrap.o example.o -o _example.so
#g++ -shared example.o example_wrap.o -o _example.so
g++ example_wrap.o example.o -o _example.so -shared -Wl,-soname,_example.so 
