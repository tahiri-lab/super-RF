#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stack>
#include "include/parser.hpp"
#include "include/SRF.hpp"
#include "tests/unitTests.hpp"
using namespace std;

void unitTests();
void demo();
void testTriangleInequality();
bool checkTriangleInequality(vector<string> inputTrees);
bool endsWith(string fullString, const string ending);

// two strings to store the trees we want to compare
string Tree1 = "";
string Tree2 = "";

/**
 * Custom this function as you want and execute it with "make user" command
 * */
void user() {
    cout << "User custom function :" << endl;
    //TODO
}


/*********************************************************************************************************************/
int main(int argc, char* argv[]) {
    //if program compiled with make test :
    if (argc == 1) {
        demo();
    }

    if (argc > 1) {
        if (strcmp(argv[1], "test") == 0) {
            unitTests();
        } else if (strcmp(argv[1], "triangle") == 0) {
            testTriangleInequality();
        } else if (strcmp(argv[1], "user") == 0) {
            user();
        } else {
            if(argc == 3){
                Tree1 = argv[1];
                Tree2 = argv[2];
            }
            if(endsWith(argv[1], ".txt") && argc == 2) {
                pair<string, string> newickStrings = extractNewickFromFile(argv[1]);
                Tree1 = newickStrings.first;
                Tree2 = newickStrings.second;
            }
            cout << "Pair of trees used for calculation :" << endl;
            cout << "---------------------------------------------------------------------------------------" << endl;
            cout << Tree1 << endl;
            cout << "---------------------------------------------------------------------------------------" << endl;
            cout << Tree2 << endl;
            cout << "---------------------------------------------------------------------------------------" << endl;
            SRF(Tree1, Tree2);
        }

    }
    return 0;
}

/*********************************************************************************************************************/

/**
 * @brief testing triangle inequality between 10 different trees
 * */
void testTriangleInequality() {
    vector<string> trees = {
            "(((a,b),((c,d),e)),(f,g))",
            "(((a,b,h),((c,d),e)),(f,g))",
            "(((a,b),((c,d),e)),h,(f,g))",
            "(((a,b),((c,d),(e,h))),(f,g))",
            "(((a,b),((c,d),(e,(h,i)))),(f,g))",
            "(((f,b),((c,d),e)),(a,g))",
            "(((f,b,h),((c,d),e)),(a,g))",
            "(((f,b),((c,d),e)),h,(a,g))",
            "(((f,b),((c,d),(e,h))),(a,g))",
            "(((f,b),((c,d),(e,(h,i)))),(a,g))"
    };
    int numStrings = 10;
    cout << "Calculating SRF and checking triangle inequality :" << endl;
    for (int i = 0; i < numStrings; ++i) {
        for (int j = i + 1; j < numStrings; ++j) {
            std::cout << i << " and " << j << " = " << SRF(trees[i], trees[j]) << std::endl;
        }
    }

    cout << "Checking triangle inequality : " << endl;
    checkTriangleInequality(trees);
}

/**
 * @brief testing triangle inequality between 10 different trees
 * */
bool checkTriangleInequality(vector<string> inputTrees) {
    int numStrings = inputTrees.size();

    for (int i = 0; i < numStrings; ++i) {
        for (int j = 0; j < numStrings; ++j) {
            for (int k = 0; k < numStrings; ++k) {
                if (i != j && j != k && i != k) {
                    double inequalityResult = SRF(inputTrees[i], inputTrees[k]) +
                            SRF(inputTrees[k], inputTrees[j]) -
                            SRF(inputTrees[i], inputTrees[j]);
                    cout << "SRF(" << i << "," << k << ") + " <<
                         "SRF(" << k << "," << j << ") - " <<
                         "SRF(" << i << "," << j << ")" <<
                         " = " << inequalityResult << endl;
                    if (inequalityResult < 0) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

/**
 * @brief unit test function
 * */
void unitTests() {
    cout << "\nTESTING BIPARTITION FUNCTIONS" << endl;
    cout << "\n---------------------------------------------------------------------------------\n" << endl;

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
    testSRF();
}

/**
 * @brief demo function called when program is executed without any argument
 * */
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