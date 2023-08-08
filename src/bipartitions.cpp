//
// Created by Arthur Debeaupte on 07/08/2023.
//

#include "../include/bipartitions.hpp"

//TODO union, intersection, différence, complément
//TODO élément présent dans l'ensemble ?

//TODO have a set of common bipartitions


int getBipartitionSize(pair<list<string>, list<string>> inputBipartition) {
    return inputBipartition.first.size();
}


vector<list<string>> setDifference(vector<list<string>> set1, vector<list<string>> set2) {
    vector<list<string>> result;

    for (list<string> l1 : set1) {
        bool foundEqual = false;
        for (list<string> l2 : set2) {
            if (areListsEqual(l1, l2)) {
                foundEqual = true;
                break;
            }
        }
        if (!foundEqual) {
            result.push_back(l1);
        }
    }

    return result;
}


vector<string> getTreeSet(string inputString) {
    return getAllTaxons(inputString);
}

//TODO test
vector<string> setUnion(vector<string> set1, vector<string> set2) {
    vector<string> result;

    for(string s: set1) {
        result.push_back(s);
    }

    for (string s: set2) {
        if (!isStringInVector(s, set1)){
            result.push_back(s);
        }
    }
    return result;
}

/**
 * Util functions
 * */

bool areListsEqual(list<string> list1, list<string> list2) {
    unordered_set set1(list1.begin(), list1.end());
    unordered_set set2(list2.begin(), list2.end());

    return set1 == set2;
}

bool isStringInVector(string inputString, vector<string> inputVector) {
    bool result = false;

    for(string s: inputVector) {
        if (s == inputString) {
            result = true;
            break;
        }
    }
    return result;
}