//
// Created by Arthur Debeaupte on 25/07/2023.
//

#ifndef NEWICKBIPARTITIONPARSER__PARSER_HPP
#define NEWICKBIPARTITIONPARSER__PARSER_HPP

#include <iostream>
#include <string>
#include <utility>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

vector<string> getStringStackBipartitions(string inputString);

string deleteTaxonDistance(string inputString);

vector<string> splitStringToVector(string inputString);

list<string> splitStringToList(string inputString);

vector<string> getAllTaxons(string inputString);

pair<list<string>, list<string>> createPairBipartition(vector<string> allSpecies, vector<string> currentBipartition);

bool findStringInList(list<string> list, string target);

vector<string> getStringBipartitions(vector<pair<string, int>> inputVector);

vector<pair<string, int>> levelVectorBuilder(string inputString);

string splitSubVectorOfPairs(vector<pair<string, int>> subVector, int departureLevel);

vector<pair<list<string>, list<string>>> getPairBipartitions(string newickInputString);

vector<list<string>> getBipartitions(string newickInputString);





/**
 * UTIL functions
 * */
void printVectorOfPairs2(const vector<pair<string, int>>& data);

void printVectorOfListOfString(vector<list<string>> input);

void printVectorOfPairs(vector<pair<list<string>, list<string>>> vector);

#endif //NEWICKBIPARTITIONPARSER__PARSER_HPP
