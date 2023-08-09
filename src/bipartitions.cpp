//
// Created by Arthur Debeaupte on 07/08/2023.
//

#include "../include/bipartitions.hpp"

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

vector<string> setIntersection(vector<string> set1, vector<string> set2) {
    vector<string> result;
    for(string s: set1) {
        if(isStringInVector(s, set2)) {
            result.push_back(s);
        }
    }
    return result;
}

vector<string> setDifference(vector<string> set1, vector<string> set2) {
    vector<string> result;
    for(string s: set1) {
        if(!isStringInVector(s, set2)) {
            result.push_back(s);
        }
    }
    return result;
}

int setCardinal(vector<string> inputSet) {
    return inputSet.size();
}

vector<pair<list<string>, list<string>>> reduceBipartitionsToIntersection(vector<pair<list<string>, list<string>>> inputBipartitions, vector<string> intersectionSet) {
    vector<pair<list<string>, list<string>>> result;
    pair<list<string>, list<string>> currentPair;
    list<string> currentFirstList;
    list<string> currentSecondList;

    for(pair<list<string>, list<string>> inputPair : inputBipartitions) {
        for(string s: inputPair.first) {
            if(isStringInVector(s, intersectionSet)) {
                currentFirstList.push_back(s);
            }
        }
        for(string s: inputPair.second) {
            if(isStringInVector(s, intersectionSet)) {
                currentSecondList.push_back(s);
            }
        }
        if (!currentFirstList.empty()) {
            currentPair.first = currentFirstList;
            currentPair.second = currentSecondList;
            result.push_back(currentPair);
        }
        currentFirstList.clear();
        currentSecondList.clear();
    }

    return result;
}

//TODO test this function
vector<pair<pair<list<string>, list<string>>, int>> getBipartitionOccurences(vector<pair<list<string>, list<string>>> inputBipartitions) {
    vector<pair<pair<list<string>, list<string>>, int>> result;
    vector<pair<list<string>, list<string>>> visitedBipartitions;
    pair<pair<list<string>, list<string>>, int> currentPair;
    int currentCount = 0;

    for(pair<list<string>, list<string>> p: inputBipartitions) {
        if(!isPairInVector(p, visitedBipartitions)) {
            for (pair<list<string>, list<string>> p2: inputBipartitions ) {
                if(areListsEqual(p.first, p2.first) || areListsEqual(p.first, p2.second)) {
                    currentCount++;
                }
            }
            visitedBipartitions.push_back(p);
            currentPair.first = p;
            currentPair.second = currentCount;
            result.push_back(currentPair);
            currentCount = 0;
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

bool isPairInVector(pair<list<string>, list<string>> inputPair, vector<pair<list<string>, list<string>>> inputVector) {
    bool result = false;

    for(pair<list<string>, list<string>> p: inputVector) {
        if(areListsEqual(p.first, inputPair.first) || areListsEqual(p.second, inputPair.first)) {
            result = true;
            break;
        }
    }
    return result;
}
