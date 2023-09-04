# Super-RF

Super-RF - C++ program for calculating SRF distance between two phylogenetic trees.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Building and Running](#building-and-running)
- [Usage](#usage)
- [Custom User Function](#custom-user-function)
- [Documentation](#documentation)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [Contact](#contact)

## Overview

This project accomplishes two major tasks:
- extracting phylogenetic tree bipartitions from a Newick format
- calculating the Super-RF distance: a novel way to compare two phylogenetic trees

The Super-RF distance is a new approach to comparing two phylogenetic trees, as described in the article titled *article title*.

## Features

- Calculate SRF between 2 phylogenetic trees
- Verify the triangle inequality for 10 trees
- User-customizable actions for manipulating tree bipartitions, SRF, and more

## Building and Running

No external libraries are required to compile this project.

Download the source files and open the folder in your terminal:
- Run ```make``` to compile the project and create the ```./SRF``` executable on your machine.
- Run ```make triangle``` to compile the project, create the ```./SRF``` executable, and then test the triangle inequality for a given set of trees.
- Run ```make test``` to compile the project, create the ```./SRF``` executable, and then execute a series of unit tests (for developers).

## Usage

The program compares two phylogenetic trees, requiring a pair of phylogenetic trees as input.

To use the program effectively:
- Provide a text file containing both trees: ```./SRF yourFile.txt```
- Pass both trees as arguments: ```./SRF 'newick1' 'newick2'```

An example set of trees is available in the ```treesExample.txt``` file.

An example to use the program to calculate SRF between two trees in a txt file :
```shell
./SRF data/treesExample.txt
```
The output will be the following :
```shell
Pair of trees used for calculation :
---------------------------------------------------------------------------------------
((1:1,2:2):1,(3:3,4:4):2,(5:5,(6:6,7:7):3):3)
---------------------------------------------------------------------------------------
((((1:1,2:2):1,8:8):1,(5:5,9:9):2):1,(3:3,(10:10,4:4):3):2)
---------------------------------------------------------------------------------------
CALCULATING SRF WITH VALUES :
card(E1/E2) = 2
card(E2/E1) = 3
sum|B1(P) - B2(P)| = 2
card(0) = 1

card(E1 U E2) = 10
=====> SRF = 0.571429
```
Here, we can see the Newick tree format of both trees present in treesExample.txt file. Then, we have the SRF calculation details, with the value for each formula component.
- card(E1/E2) is the cardinal of the symetric difference between two sets E1 and E2.
- sum|B1(P) - B2(P)| is the number of bipartitions of E1 (respectively E2) in T1 (respectively T2),
- that induce the bipartition P of E1 ∩ E2
- card(0) is the number of times a side of a bipartition is null when bipartitions are brought to E1 ∩ E2.
- card(E1 U E2) is the cardinal of E1 U E2.
- The final result is equal to 0.571429


## Custom User Function

You have the flexibility to implement a custom function and execute it using the provided build system. Follow these steps:

1. **Implement Your Function**: Inside the `src` directory, `main.cpp` file, implement the `user()` function as you wish.

2. **Run your function**: Compile and run your custom function with the command ```make user```.

## Documentation

Project documentation is available in ```docs``` folder.

Set manipulation functions are documented in a static html page in ```docs/html/index.html```.

The algorithm to parse a Newick tree format into a vector<pair<list<string>, list<string>>> is explained in a pdf at ```docs/BipartitionAlgorithmPresentation.pdf```.


## Project Structure

The project is organized into 5 folders:

- ```data``` contains input data files (text files containing phylogenetic trees)
- ```docs``` contains documentation for the set manipulation library
- ```include``` includes header files (```.hpp```)
- ```src``` includes source files (```.cpp```)
- ```tests``` includes unit test files

## Contributing

The Super-RF formula is not finalized yet. If you wish to modify it, you can do so by updating the ```SRF()``` function in the ```SRF.cpp``` file.

The ```SRF()``` function can utilize any functions present in the ```SRF.cpp``` file. Documentation for these functions is available at ```docs/html/index.html```.

## Contact
If you have any question or feedback, do not hesitate to reach us at :
- Nadia Tahiri : Nadia.Tahiri@USherbrooke.ca
- Arthur Debeaupte : debeaupte.arthur@gmail.com
