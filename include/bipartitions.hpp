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

#include "parser.hpp"

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
 * @brief returns a set containing all species of a phylogenetic tree
 *
 *@param inputString Newick representation of the tree
 *
 *@return vector<string>, each string being a tree leaf
 * */
vector<string> getTreeSet(string inputString);

/**
 * @brief returns the union of two sets
 *
 * @param set1
 * @param set2
 *
 * @return vector<string> the union of the given sets
 * */
vector<string> setUnion(vector<string> set1, vector<string> set2);

/**
 * @brief returns the intersection of two sets
 *
 * @param set1
 * @param set2
 *
 * @return vector<string> being the intersection of the two sets
 * */
vector<string> setIntersection(vector<string> set1, vector<string> set2);

/**
 * @brief returns the difference between two sets --> E1\E2
 *
 * @param set1
 * @param set2
 *
 * @return set1\set2 (E1\E2)
 * */
vector<string> setDifference(vector<string> set1, vector<string> set2);

/**
 * util functions
 * */

bool areListsEqual(list<string> list1, list<string> list2);

bool isStringInVector(string s, vector<string> v);

#endif //NEWICKBIPARTITIONPARSER__BIPARTITIONS_HPP
