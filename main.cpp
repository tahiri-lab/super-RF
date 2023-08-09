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

int main() {
    unitTests();
    return 0;
}

void unitTests() {
    cout << "\nTESTING BIPARTITION FUNCTIONS" << endl;
    //cout << "\n---------------------------------------------------------------------------------\n" << endl;
    //testPairBipartitions();
    //cout << "\n---------------------------------------------------------------------------------\n" << endl;
    //testBipartitions();
    //cout << "\n---------------------------------------------------------------------------------\n" << endl;
    //testUnion();
    //cout << "\n---------------------------------------------------------------------------------\n" << endl;
    //testIntersection();
    cout << "\n---------------------------------------------------------------------------------\n" << endl;
    testDifference();
}