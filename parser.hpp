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


/**
vector<string> parseStage(string stageString);
string deleteSpaces(string inputString);
string cleanTaxon(string taxon);
vector<pair<string, string>> splitFullNewick(string inputString);
vector<string> getStageElements(string str);
vector<pair<list<string>, list<string>>> stageBipartitioner(vector<vector<string>> stageVector);
pair<list<string>, list<string>> cutStringVector(vector<vector<string>> vector, int cutIndex);
void printVectorUtil(vector<vector<string>> vectorInput);

*/


vector<string> getStringStackBipartitions(string inputString);

string deleteTaxonDistance(string inputString);

vector<string> splitStringToVector(string inputString);

vector<string> getAllTaxons(string inputString);

pair<list<string>, list<string>> createPairBipartition(vector<string> allSpecies, vector<string> currentBipartition);

vector<pair<list<string>, list<string>>> getBipartitions(string newickInputString);

bool findStringInList(list<string> list, string target);





#endif //NEWICKBIPARTITIONPARSER__PARSER_HPP
