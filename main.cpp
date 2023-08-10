#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stack>
#include "include/parser.hpp"
#include "include/bipartitions.hpp"
#include "tests/unitTests.hpp"
using namespace std;

//TODO create user friendly executable, add trivial bipartitions option

//TODO store branches length somewhere

void unitTests();
void demo();
bool endsWith(string fullString, const string ending);

// two strings to store the trees we want to compare
string Tree1 = "";
string Tree2 = "";

int main(int argc, char* argv[]) {
    //if program compiled with make test :
    if (argc == 1) {
        demo();
    }

    if (argc > 1) {
        if (strcmp(argv[1], "test") == 0) {
            unitTests();
        } else {
            if(argc == 3){
                Tree1 = argv[1];
                Tree2 = argv[2];
            }
            if(endsWith(argv[1], ".txt") && argc == 2) {
                //TODO SRF with txt file
                pair<string, string> newickStrings = extractNewickFromFile(argv[1]);
                Tree1 = newickStrings.first;
                Tree2 = newickStrings.second;
                cout << Tree1 << endl;
                cout << Tree2 << endl;
            }
        }
        SRF(Tree1, Tree2);
    }

    return 0;
}

void unitTests() {
    cout << "\nTESTING BIPARTITION FUNCTIONS" << endl;
    cout << "\n---------------------------------------------------------------------------------\n" << endl;
    /*
    testPairBipartitions();
    cout << "\n---------------------------------------------------------------------------------\n" << endl;
    testBipartitions();
    cout << "\n---------------------------------------------------------------------------------\n" << endl;
    testUnion();
    cout << "\n---------------------------------------------------------------------------------\n" << endl;
    testIntersection();
    cout << "\n---------------------------------------------------------------------------------\n" << endl;
    testDifference();
    cout << "\n---------------------------------------------------------------------------------\n" << endl;
    testBipartitionPairs();
    cout << "\n---------------------------------------------------------------------------------\n" << endl;
    testReduceBipartitionToIntersectionSet();
    cout << "\n---------------------------------------------------------------------------------\n" << endl;
    testIsPairInVector();
    cout << "\n---------------------------------------------------------------------------------\n" << endl;
    testBipartitionOccurences();
    cout << "\n---------------------------------------------------------------------------------\n" << endl;
    testBipartitionOccurenceDifference();
    cout << "\n---------------------------------------------------------------------------------\n" << endl;
     */
    testSRF();
}

void demo() {
    cout << "This program calculates SRF distance between two phylogenetical trees." << endl;
    cout << "To use it, you need to specify two phylogenetic trees in Newick format, using :" << endl;
    cout << "   - a txt file containing both trees : ./SRF yourFile.txt" << endl;
    cout << "   - by putting your trees as arguments : ./SRF newick1 newick2" << endl;
}

/**
 * @brief checks if a string ends with a specific ending
 */
bool endsWith(string fullString, const string ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}