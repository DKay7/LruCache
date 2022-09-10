# LRU-cache algorithm realization

Given project implements LRU cache algorithm

## Requirements
- To build and run this program you should have installed:
    - C++ compiler with cpp-20 standard support
    - CMake >= 3.10
    - Make
- To generate your own tests you should have installed:
    - python 3x

## Run
To run program execute following lines:

1. `mkdir build && cd build`
2. `cmake ..`
3. `make`
4. 
    1. `./lru_cache` to run program
    2. `./lru_cache-tests` to run tests

To generate new tests execute following lines:

1. `python -m pip install -r test_generation/requirements.txt`
2. `python test_generation/testgen.py`

## Test format
Generator generates and program expects tests in next format:

`CACHE_SIZE` `NUMBER_OF_DATA` `DATA`
