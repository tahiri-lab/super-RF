# Super-RF

Super-RF - C++ program calculating SRF distance between two phylogenetic trees.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Building and Running](#building-and-running)
- [Usage](#usage)
- [Architecture](#architecture)
- [Contributing](#contributing)

## Overview

This project acomplishes two major tasks :
- getting phylogenetic tree bipartitions from a Newick format
- calculating super-RF distance : a new way to compare two phylogenetic trees

Super-RF distance is a new way to compare two phylogenetic trees, following the article *article title*.

## Features

- calculating SRF between 2 phylogenetic trees
- checking triangle inequality between 10 trees
- user custom action, manipulating trees bipartitions, SRF, ...

## Building and Running

No outside library is necessary to compile this project.

Download src files, open folder in your terminal :
- ```make``` compiles the project and create ./SRF executable file on your machine.
- ```make triangle``` compiles the project and create ./SRF executable file, then tests triangle inequality for a given set of trees.
- ```make test``` compiles the project and create ./SRF executable file, then runs a series of unit tests (for developers)

## Usage
The program compares two phylogenetic trees, so it needs a pair of phylogenetic trees as entries.

To use it properly, you can pass your pair of trees (in Newick format) as :
- a txt file containing both of your trees : ./SRF yourFile.txt
- passing both trees as arguments : ./SRF 'newick1' 'newick2'

An example set of trees is available in treesExample.txt file.

## Architecture

TODO

## Contributing

Super-RF formula is not in its final version yet. If you want to modify it, you can by updating the SRF() function in SRF.cpp file.

SRF() can use every function present in SRF.cpp file. The documentation for these functions is available at 'docs/html/index.html'.