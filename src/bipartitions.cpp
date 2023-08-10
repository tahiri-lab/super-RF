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

pair<int, int> bipartitionOccurencesDifference(vector<pair<pair<list<string>, list<string>>, int>> bipartitions1, vector<pair<pair<list<string>, list<string>>, int>> bipartitions2) {
    pair<int, int> result;
    int currentDif = 0;
    int nulResultCount = 0;
    int totalSum = 0;

    bool isTreated = false;

    vector<pair<list<string>, list<string>>> visitedBipartitions;

    for(pair<pair<list<string>, list<string>>, int> pairs1: bipartitions1) {
        for(pair<pair<list<string>, list<string>>, int> pairs2: bipartitions2) {
            if (areBipartitionsEqual(pairs1.first, pairs2.first)) {
                currentDif = abs(pairs1.second - pairs2.second);
                if (currentDif == 0) {
                    nulResultCount ++;
                } else {
                    totalSum += currentDif;
                }
                isTreated = true;
            }
        }
        if (!isTreated) {
            totalSum += pairs1.second;
        }
        visitedBipartitions.push_back(pairs1.first);
        isTreated = false;
        currentDif = 0;
    }

    for(pair<pair<list<string>, list<string>>, int> pairs2 : bipartitions2) {
        if(!isPairInVector(pairs2.first, visitedBipartitions)) {
            totalSum += pairs2.second;
            visitedBipartitions.push_back(pairs2.first);
        }
    }

    result.first = totalSum;
    result.second = nulResultCount;
    return result;
}

double SRF(string newick1, string newick2) {
    double result = 0;

    //initializing all needed variables
    int unionCard = 0;
    int nullResultCard = 0;
    int set1_set2Card = 0;
    int set2_set1Card = 0;
    int bipartitionsOccurenceSum = 0;

    vector<string> set1;
    vector<string> set2;
    vector<string> intersectionSet;
    vector<string> unionSet;

    // set1\set2 and set2\set1
    vector<string> set1_set2;
    vector<string> set2_set1;

    //vector of each tree bipartitions
    vector<pair<list<string>, list<string>>> T1bipartitions;
    vector<pair<list<string>, list<string>>> T2bipartitions;

    vector<pair<list<string>, list<string>>> T1reducedBipartitions;
    vector<pair<list<string>, list<string>>> T2reducedBipartitions;

    vector<pair<pair<list<string>, list<string>>, int>> T1bipartitionsOccurence;
    vector<pair<pair<list<string>, list<string>>, int>> T2bipartitionsOccurence;

    pair<int, int> bipartitionOccurenceDifference;

    //filling data structures :
    set1 = getTreeSet(newick1);
    set2 = getTreeSet(newick2);
    intersectionSet = setIntersection(set1, set2);
    unionSet = setUnion(set1, set2);
    set1_set2 = setDifference(set1, set2);
    set2_set1 = setDifference(set2, set1);

    //getting all bipartitions for both trees
    T1bipartitions = getPairBipartitions(newick1);
    T2bipartitions = getPairBipartitions(newick2);

    //reducing bepartitions to intersectionSet
    T1reducedBipartitions = reduceBipartitionsToIntersection(T1bipartitions, intersectionSet);
    T2reducedBipartitions = reduceBipartitionsToIntersection(T2bipartitions, intersectionSet);

    //getting the number of occurence for each bipartition
    T1bipartitionsOccurence = getBipartitionOccurences(T1reducedBipartitions);
    T2bipartitionsOccurence = getBipartitionOccurences(T2reducedBipartitions);

    bipartitionOccurenceDifference = bipartitionOccurencesDifference(T1bipartitionsOccurence, T2bipartitionsOccurence);

    //filing variables:
    unionCard = unionSet.size();
    set1_set2Card = set1_set2.size();
    set2_set1Card = set2_set1.size();
    bipartitionsOccurenceSum = bipartitionOccurenceDifference.first;
    nullResultCard = bipartitionOccurenceDifference.second;

    printSRFCalculation(unionCard, set1_set2Card, set2_set1Card, bipartitionsOccurenceSum, nullResultCard);

    result = (bipartitionsOccurenceSum + nullResultCard + set1_set2Card + set2_set1Card) / ((2 * unionCard) -6);
    double numerator = bipartitionsOccurenceSum + nullResultCard + set1_set2Card + set2_set1Card;

    double denominator = (2 * unionCard) -6;

    result = numerator / denominator;

    cout << "EQUALS " << fixed << setprecision(2) << result << endl;
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

void printBipartitionOccurences(const vector<pair<pair<list<string>, list<string>>, int>>& data) {
    for (const auto& entry : data) {
        const auto& bipartitionPair = entry.first;
        const auto& firstList = bipartitionPair.first;
        const auto& secondList = bipartitionPair.second;
        int count = entry.second;

        cout << "First List: ";
        for (const auto& str : firstList) {
            cout << str << " ";
        }

        cout << "\nSecond List: ";
        for (const auto& str : secondList) {
            cout << str << " ";
        }

        cout << "\nCount: " << count << "\n\n";
    }
}

bool areBipartitionsEqual(pair<list<string>, list<string>> bip1, pair<list<string>, list<string>> bip2) {
    bool result = false;
    if (areListsEqual(bip1.first, bip2.first)) {
        if(areListsEqual(bip1.second, bip2.second)) {
            result = true;
        }
    }
    if(areListsEqual(bip1.second, bip2.first)) {
        if(areListsEqual(bip1.first, bip2.second)) {
            result = true;
        }
    }
    return result;
}


void printSRFCalculation(int unionCard, int set1_set2Card, int set2_set1Card, int bipartitionsOccurenceSum, int nullResultCard) {
    cout << "CALCULATING SRF :" << endl;
    cout << bipartitionsOccurenceSum << " + " << nullResultCard << " + " << set1_set2Card << " + " << set2_set1Card << endl;
    cout << "--------------------" << endl;
    cout << "2 x " << unionCard << " - 6" << endl;
}

