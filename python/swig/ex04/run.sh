#!/bin/bash

swig -python -c++ -o mymodule_wrap.cpp mymodule.i 

g++ -c some_class.cpp -o some_class.o -fpic -std=c++0x

g++ -I/usr/include/python2.7 -c mymodule_wrap.cpp -o mymodule_wrap.o -fpic -std=c++0x

# when shared lib are present in nondefault directories
g++ mymodule_wrap.o some_class.o -o _mymodule.so -shared -Wl,-soname,_mymodule.so 
#g++ saxpy_wrap.o saxpy.o -o _saxpy.so -shared
