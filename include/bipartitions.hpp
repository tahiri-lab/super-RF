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
#include <iomanip>

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
 * @brief returns a set cardinal
 *
 * @param inputSet as vector<string>
 * @return int, cardinal of the set
 * */
int setCardinal(vector<string> inputSet);


/**
 * @brief reduces a set of bipartitions to the one existing in a given set
 *
 * @param inputBipartitions departure bipartition set
 * @param intersectionSet target set
 *
 * @return bipartitions existing in intersectionSet
 * */
vector<pair<list<string>, list<string>>> reduceBipartitionsToIntersection(vector<pair<list<string>, list<string>>> inputBipartitions, vector<string> intersectionSet);

/**
 * @brief counts the number of time each bipartition appears in a set of bipartition pairs
 *
 * @param inputBipartitions a vector<pair<list<string>, list<string>>> containing a set of bipartitions
 * @return vector<pair<pair<list<string>, list<string>>, int>>, each pair corresponding to the bipartition and the number
 *          of time it appears in the initial bipartitions set
 * */
vector<pair<pair<list<string>, list<string>>, int>> getBipartitionOccurences(vector<pair<list<string>, list<string>>> inputBipartitions);

/**
 * @brief makes the difference between the number of occurence of each similar bipartition between two bipartition sets
 *
 * @param bipartitions1
 * @param bipartitions2
 *
 * @return pair<int, int>, first int : sum of the results of every difference
 *         second int : number of time the result of the difference is equal to 0
 * */
pair<int, int> bipartitionOccurencesDifference(vector<pair<pair<list<string>, list<string>>, int>> bipartitions1, vector<pair<pair<list<string>, list<string>>, int>> bipartitions2);

/**
 * @brief calculates the sum of absolute differences of similar bipartitions occurences and the cardinal of null results
 *
 * @param bipartitions1 first set of bipartitions and their occurences
 * @param bipartitions2 second set of bipartitions and their occurences
 *
 * @return pair<int, int>, first int : sum of the absolute value of occurences difference for two identical bipartitions
 * */
pair<int, int> bipartitionOccurencesDifference(vector<pair<pair<list<string>, list<string>>, int>> bipartitions1, vector<pair<pair<list<string>, list<string>>, int>> bipartitions2);

/**
 * @brief calculates SRF distance for two phylogenetical trees
 *
 * @param newick1 Newick representation of T1
 * @param newick2 Newick representation of T2
 *
 * @return double : SRF value
 * */
double SRF(string newick1, string newick2);

/**
 * util functions
 * */

bool areListsEqual(list<string> list1, list<string> list2);

bool isStringInVector(string s, vector<string> v);

bool isPairInVector(pair<list<string>, list<string>> inputPair, vector<pair<list<string>, list<string>>> inputVector);

void printBipartitionOccurences(const vector<pair<pair<list<string>, list<string>>, int>>& data);

bool areBipartitionsEqual(pair<list<string>, list<string>> bip1, pair<list<string>, list<string>> bip2);

void printSRFCalculation(int unionCard, int set1_set2Card, int set2_set1Card, int bipartitionsOccurenceSum, int nullResultCard);

#endif //NEWICKBIPARTITIONPARSER__BIPARTITIONS_HPP
