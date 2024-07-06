# Tree Data Structre in C++
The following project implements a flexible tree data structure.
It allows nodes to have a coustomizable number of children and support various traversal methods including pre-order, post-order, in-order, BFS, DFS and Min heap.
The tree can accpet all types of numbers including Complex numbers.

## How to build and run the project:
Use the provided `makefile` to build and run the project:

   - To build main:
        ```bash
        make tree
        ```
  - To run main:
      ```bash
        ./tree
  - To build tests:
      ```bash
      make test
      
  - To run tests:
      ```bash
        ./test
      
 - To clean project:
      ```bash
        make clean
        

## Project structure and explantion:
- main.cpp:
  Main file to show the execute of the project and to demonstrate the traverse methods on action.
- test.cpp:
  File test for unit tests using doctest.
- tree.hpp:
  Implements the tree structure and all the following traverse methods :
  Pre order, Post order, In Order, BFS, DFS, Min heap.
- node.hpp:
  Implements the node class represnting the node in a tree.
- complex.hpp:
  Implements the complex numbers including overloading method for comparing between two complex numbers.
- gui.hpp:
  File for visualizing the trees using sfml gui.
