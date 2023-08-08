//
// Created by Arthur Debeaupte on 07/08/2023.
//

#ifndef NEWICKBIPARTITIONPARSER__BIPARTITIONS_HPP
#define NEWICKBIPARTITIONPARSER__BIPARTITIONS_HPP

#include <iostream>
#include <string>
#include <utility>
#include <list>
#include <stack>
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * @brief get biparition size
 *
 * @param inputBipartition a pair<list<string>, list<string>> representing a bipartition
 *
 * @return int : bipartition's size
 * */
int getBipartitionSize(pair<list<string>, list<string>> inputBipartition);

/**
 * @brief returns set1 minus set2
 *
 * @param set1
 * @param set2
 *
 * @return set1 minus set2
 * */
vector<list<string>> setDifference (vector<list<string>> set1, vector<list<string>> set2 );

/**
 * @brief get symmetric difference between two sets
 *
 * @param set1
 * @param set2
 *
 * @return symmetric difference between set1 and set2
 * */
vector<list<string>> symmetricDifference(vector<list<string>> set1, vector<list<string>> set2);

/**
 * util functions
 * */

bool areListsEqual(list<string> list1, list<string> list2);

#endif //NEWICKBIPARTITIONPARSER__BIPARTITIONS_HPP
