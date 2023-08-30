# Super-RF

Super-RF - C++ program for calculating SRF distance between two phylogenetic trees.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Building and Running](#building-and-running)
- [Usage](#usage)
- [Custom User Function](#custom-user-function)
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

## Custom User Function

You have the flexibility to implement a custom function and execute it using the provided build system. Follow these steps:

1. **Implement Your Function**: Inside the `src` directory, `main.cpp` file, implement the `user()` function as you wish.

2. **Run your function**: Compile and run your custom function with the command ```make user```.


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
- nadia.tahiri@usherbrooke.ca
- debeaupte.arthur@gmail.com