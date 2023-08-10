//
// Created by Arthur Debeaupte on 09/08/2023.
//

#ifndef NEWICKBIPARTITIONPARSER__UNITTESTS_HPP
#define NEWICKBIPARTITIONPARSER__UNITTESTS_HPP

#include <iostream>
#include <string>
#include <utility>
#include <list>
#include <stack>
#include <unordered_set>
#include <algorithm>

#include "../include/parser.hpp"
#include "../include/bipartitions.hpp"


void testPairBipartitions();
void testBipartitions();
void testUnion ();
void testIntersection();
void testDifference();
void testBipartitionPairs();
void testReduceBipartitionToIntersectionSet();
void testIsPairInVector();
void testBipartitionOccurences();
void testBipartitionOccurenceDifference();
void testSRF();


#endif //NEWICKBIPARTITIONPARSER__UNITTESTS_HPP
