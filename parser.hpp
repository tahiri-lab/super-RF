//
// Created by Arthur Debeaupte on 25/07/2023.
//

#ifndef NEWICKBIPARTITIONPARSER__PARSER_HPP
#define NEWICKBIPARTITIONPARSER__PARSER_HPP

#include <iostream>
#include <string>
#include <utility>
#include <list>
using namespace std;

vector<string> parseStage(string stageString);
string deleteSpaces(string inputString);
string cleanTaxon(string taxon);
vector<pair<string, string>> splitFullNewick(string inputString);
vector<string> getStageElements(string str);
vector<pair<list<string>, list<string>>> stageBipartitioner(vector<vector<string>> stageVector);
pair<list<string>, list<string>> cutStringVector(vector<vector<string>> vector, int cutIndex);
void printVectorUtil(vector<vector<string>> vectorInput);


#endif //NEWICKBIPARTITIONPARSER__PARSER_HPP
