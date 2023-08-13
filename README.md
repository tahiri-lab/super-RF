# Super-RF distance calculator
C++ program calculating SRF distance between two phylogenetic trees.

## Compile

Download the files, open the folder in your terminal :
- ```make``` compiles the project and create ./SRF executable file on your machine.
- ```make test``` compiles the project and create ./SRF executable file, then runs a series of tests


## Execute
The program compares two phylogenetic trees, so it needs a pair of phylogenetic trees as entries.

To use it properly, you can pass your pair of trees as :
- a txt file containing both of your trees : ./SRF yourFile.txt
- passing both trees as arguments : ./SRF 'newick1' 'newick2'

An example set of trees is available in treesExample.txt file.

## Function library

The program contains some functions to manipulate bipartitions and species sets.

