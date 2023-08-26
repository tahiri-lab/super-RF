//
// Created by Arthur Debeaupte on 09/08/2023.
//


#include "unitTests.hpp"

string T1 = "((1:1,2:2):1,(3:3,4:4):2,(5:5,(6:6,7:7):3):3);";
string T2 = "((((1:1,2:2):1,8:8):1,(5:5,9:9):2):1,(3:3,(10:10,4:4):3):2);";

//string T1 = "(Guangxi_Pangolin_P2V:0.1,(((Guangdong_Pangolin_P2S_2019:0.1,Guangdong_Pangolin_1_2019:0.1):0.04421[70],(RaTG13:0.1,(Hu_Australia_VIC231_2020:0.1,Hu_Wuhan_2020:0.1,Hu_USA_UT_00346_2020:0.1,Hu_Italy_TE4836_2020:0.1):0.04431[59],(Bat_CoVZXC21:0.1,Bat_CoVZC45:0.1):0.08900[91]):0.1[54]):0.13564[85],((BM48_31_BGR_2008:0.054678,BtKY72:0.029286):0.033400[70],(SARS:0.1,Tor2:0.1,SARS-CoV_BJ182-4:0.1):0.08768[83],Rs3367:0.04400,(((Bovine_CoV:0.1,Bovine_OH440:0.1,Human_ent_4408:0.1,Bovine_AH187:0.1):0.16426[84],Rabbit_HKU14:0.15816,Porcine_v:0.042378,Equine_NC99:0.040086,Human_OC43:0.1,HKU1:0.470188,(Murine_A59:0.04327,(Murine_RA59/R13:0.1,Murine_virus:0.1):0.1[60]):0.048383[60],Murine_JHM:0.025102,Rat_Parker:0.023927,Feline_per:1.403610):0.667926[86],(Bat_HKU5-1:0.076790,MERS-CoV_S:0.233039,Bat_HKU4-1:0.134680):0.561739[76]):0.557886[76],(BtCoV_273_2005:0.1,Rf1:0.1):0.1[97],BtCoV_279_2005:0.13435,(HKU3-12:0.1,HKU3-6:0.1):0.05011[94]):0.06426[79]):0.08915[97],Guangxi_Pangolin_P1E:0.1,Guangxi_Pangolin_P4L:0.1,Guangxi_Pangolin_P5L:0.1,Guangxi_Pangolin_P5E:0.1)";
//string T2 = "((((((Rf1:0.1,BtCoV_273_2005:0.1):0.029572[99],Rs3367:0.08225):0.13862[95],(SARS-CoV_BJ182-4:0.1519,(SARS:0.1,Tor2:0.1):0.1[68]):0.06475[96]):0.13000[90],((BtKY72:0.083591,BM48_31_BGR_2008:0.109237):0.102958[89],(((Guangxi_Pangolin_P5L:0.1,Guangxi_Pangolin_P2V:0.03031,Guangxi_Pangolin_P5E:0.1,Guangxi_Pangolin_P4L:0.1):0.1512[69],Guangxi_Pangolin_P1E:0.1):0.044731[99],(Guangdong_Pangolin_1_2019:0.1,Guangdong_Pangolin_P2S_2019:0.1):0.023527[98],((Hu_Wuhan_2020:0.1,Hu_USA_UT_00346_2020:0.1,Hu_Australia_VIC231_2020:0.1):0.1514[71],Hu_Italy_TE4836_2020:0.1):0.021999[99],((((((((Bovine_OH440:0.1513,Bovine_AH187:0.1):0.1[85],Bovine_CoV:0.03026):0.05009[70],Human_ent_4408:0.04421):0.021282[98],Human_OC43:0.025679,Rabbit_HKU14:0.020934,Porcine_v:0.061453):0.030787[54],Equine_NC99:0.037608):0.092544[78],(Rat_Parker:0.039312,(Murine_virus:0.1489,(Murine_RA59/R13:0.1,Murine_A59:0.1):0.1[64]):0.05843[82],Murine_JHM:0.023375):0.137159[99]):0.100637[60],HKU1:0.134974):0.378470[58],(Bat_HKU4-1:0.199004,Bat_HKU5-1:0.195437,MERS-CoV_S:0.141351):0.419370[61],Feline_per:0.1):17.297781[100],RaTG13:0.1,(Bat_CoVZXC21:0.1,Bat_CoVZC45:0.1):0.035274[100]):0.106789[74]):0.038312[88]):0.021613[91],BtCoV_279_2005:0.020537):0.15542[100],HKU3-6:0.1,HKU3-12:0.1)";

string newickString = "(ant:17, (bat:31, cow:22):7, dog:22, (elk:33, fox:12):40);";
string newickString2 = "(ant:17, (bat:31, cow:22, goat:21, bird:12):7, dog:22, (elk:33, (cat:13, rabbit:45):14, fox:12):40)";
string newickString3 = "(ant:17, (bat:31, cow:22, goat:21, bird:12):7, dog:22, (elk:33, (cat:13, (fish:23, whale:3, dolphin:13):12, rabbit:45, (lion:4, tiger:5):12):14, fox:12):40)";
string realNewickString = "((((((Rf1:0.1,BtCoV_273_2005:0.1):0.029572[99],Rs3367:0.08225):0.13862[95],(SARS-CoV_BJ182-4:0.1519,(SARS:0.1,Tor2:0.1):0.1[68]):0.06475[96]):0.13000[90],((BtKY72:0.083591,BM48_31_BGR_2008:0.109237):0.102958[89],(((Guangxi_Pangolin_P5L:0.1,Guangxi_Pangolin_P2V:0.03031,Guangxi_Pangolin_P5E:0.1,Guangxi_Pangolin_P4L:0.1):0.1512[69],Guangxi_Pangolin_P1E:0.1):0.044731[99],(Guangdong_Pangolin_1_2019:0.1,Guangdong_Pangolin_P2S_2019:0.1):0.023527[98],((Hu_Wuhan_2020:0.1,Hu_USA_UT_00346_2020:0.1,Hu_Australia_VIC231_2020:0.1):0.1514[71],Hu_Italy_TE4836_2020:0.1):0.021999[99],((((((((Bovine_OH440:0.1513,Bovine_AH187:0.1):0.1[85],Bovine_CoV:0.03026):0.05009[70],Human_ent_4408:0.04421):0.021282[98],Human_OC43:0.025679,Rabbit_HKU14:0.020934,Porcine_v:0.061453):0.030787[54],Equine_NC99:0.037608):0.092544[78],(Rat_Parker:0.039312,(Murine_virus:0.1489,(Murine_RA59/R13:0.1,Murine_A59:0.1):0.1[64]):0.05843[82],Murine_JHM:0.023375):0.137159[99]):0.100637[60],HKU1:0.134974):0.378470[58],(Bat_HKU4-1:0.199004,Bat_HKU5-1:0.195437,MERS-CoV_S:0.141351):0.419370[61],Feline_per:0.1):17.297781[100],RaTG13:0.1,(Bat_CoVZXC21:0.1,Bat_CoVZC45:0.1):0.035274[100]):0.106789[74]):0.038312[88]):0.021613[91],BtCoV_279_2005:0.020537):0.15542[100],HKU3-6:0.1,HKU3-12:0.1);";
string realNewickString2 = "(1:0.1,(((2:0.1,3:0.1):0.04421[70],(4:0.1,(5:0.1,6:0.1,7:0.1,8:0.1):0.04431[59],(9:0.1,10:0.1):0.08900[91]):0.1[54]):0.13564[85],((11:0.054678,12:0.029286):0.033400[70],(13:0.1,14:0.1,15:0.1):0.08768[83],16:0.04400,(((17:0.1,18:0.1,19:0.1,20:0.1):0.16426[84],21:0.15816,22:0.042378,23:0.040086,24:0.1,25:0.470188,(26:0.04327,(27:0.1,Murine_virus:0.1):0.1[60]):0.048383[60],Murine_JHM:0.025102,Rat_Parker:0.023927,Feline_per:1.403610):0.667926[86],(Bat_HKU5-1:0.076790,MERS-CoV_S:0.233039,Bat_HKU4-1:0.134680):0.561739[76]):0.557886[76],(BtCoV_273_2005:0.1,Rf1:0.1):0.1[97],BtCoV_279_2005:0.13435,(HKU3-12:0.1,HKU3-6:0.1):0.05011[94]):0.06426[79]):0.08915[97],Guangxi_Pangolin_P1E:0.1,Guangxi_Pangolin_P4L:0.1,Guangxi_Pangolin_P5L:0.1,Guangxi_Pangolin_P5E:0.1) ";


void testPairBipartitions() {
    /** TEST FOR getPairBipartitions returning a vector<pair<list<string>, list<string>>> */
    cout << "------------------\nTESTING pair bipartitions for :\n" << T1 << "\n------------------\n\n" << endl;

   vector<pair<list<string>, list<string>>> finalResult;
   finalResult = getPairBipartitions(T1);

   printVectorOfPairs(finalResult);
    
   cout << "\n\nNumber of bipartitions : " << finalResult.size() << endl;
}

void testBipartitions() {
    /** TEST FOR getBipartitions returning a vector<vector<string>> */
    cout << "--------------------\nBipartitions of :\n" << T1 << "\n--------------------\n" << endl;
    vector<list<string>> finalResult;
    finalResult = getBipartitions(T1);
    printVectorOfListOfString(finalResult);
    cout << "\nNumber of bipartitions : " << finalResult.size() << "\n" << endl;
}

void testUnion () {
    vector<string> set1 = getTreeSet(T1);
    vector<string> set2 = getTreeSet(T2);

    vector<string> unionSet = setUnion(set1, set2);

    cout << "Testing union of :" << endl;
    printVectorOfString(set1);
    cout << "and" << endl;
    printVectorOfString(set2);
    cout << "-----------------"<< endl;
    printVectorOfString(unionSet);
}

void testIntersection() {
    vector<string> set1 = getTreeSet(T1);
    vector<string> set2 = getTreeSet(T2);

    vector<string> intersectionSet = setIntersection(set1, set2);
    cout << "Testing intersection of :" << endl;
    printVectorOfString(set1);
    cout << "and" << endl;
    printVectorOfString(set2);
    cout << "-----------------"<< endl;
    printVectorOfString(intersectionSet);
}


void testDifference() {
    vector<string> set1 = getTreeSet(T1);
    vector<string> set2 = getTreeSet(T2);

    vector<string> differenceVector = setDifference(set1, set2);
    vector<string> differenceVector1 = setDifference(set2, set1);

    cout << "Testing E1\\E2, the difference between :" << endl;
    printVectorOfString(set1);
    cout << "and" << endl;
    printVectorOfString(set2);
    cout << "-----------------"<< endl;
    printVectorOfString(differenceVector);

    cout << "\nTesting E2\\E1, the difference between :" << endl;
    printVectorOfString(set2);
    cout << "and" << endl;
    printVectorOfString(set1);
    cout << "-----------------"<< endl;
    printVectorOfString(differenceVector1);
}

void testBipartitionPairs() {
    vector<pair<list<string>, list<string>>> T1pairBipartitions;
    T1pairBipartitions = getPairBipartitions(T1);
    cout << "Bipartitions of : " << T1 << " :"<< endl;
    printVectorOfPairs(T1pairBipartitions);

    vector<pair<list<string>, list<string>>> T2pairBipartitions;
    T2pairBipartitions = getPairBipartitions(T2);
    cout << "Bipartitions of : " << T2 << " :"<< endl;
    printVectorOfPairs(T2pairBipartitions);
}

void testReduceBipartitionToIntersectionSet() {
    vector<string> set1 = getTreeSet(T1);
    vector<string> set2 = getTreeSet(T2);
    vector<string> intersectionSet = setIntersection(set1, set2);

    vector<pair<list<string>, list<string>>> T1pairBipartitions;
    T1pairBipartitions = getPairBipartitions(T1);

    vector<pair<list<string>, list<string>>> T2pairBipartitions;
    T2pairBipartitions = getPairBipartitions(T2);

    vector<pair<list<string>, list<string>>> T1reducedBipartitions = reduceBipartitionsToIntersection(T1pairBipartitions, intersectionSet);
    vector<pair<list<string>, list<string>>> T2reducedBipartitions = reduceBipartitionsToIntersection(T2pairBipartitions, intersectionSet);

    cout << "Reducing bipartitions to this set : " << endl;
    printVectorOfString(intersectionSet);
    cout << "T1 :" << endl;
    printVectorOfPairs(T1reducedBipartitions);
    cout << "T2 :" << endl;
    printVectorOfPairs(T2reducedBipartitions);
}

void testIsPairInVector() {
    cout << "CHECK if a pair is in a vector of pairs" << endl;
    vector<string> set1 = getTreeSet(T1);
    vector<string> set2 = getTreeSet(T2);
    vector<string> intersectionSet = setIntersection(set1, set2);

    pair<list<string>, list<string>> comparedPair;

    vector<pair<list<string>, list<string>>> T2pairBipartitions;
    T2pairBipartitions = getPairBipartitions(T2);
    vector<pair<list<string>, list<string>>> T2reducedBipartitions = reduceBipartitionsToIntersection(T2pairBipartitions, intersectionSet);

    comparedPair = T2reducedBipartitions[1];
    cout << "Is the pair :" << endl;
    printPairOfLists(comparedPair);
    cout << "In the vector : " << endl;
    printVectorOfPairs(T2reducedBipartitions);
    cout << "====> " << isPairInVector(comparedPair, T2reducedBipartitions) << endl;
}

void testBipartitionOccurences() {
    vector<string> set1 = getTreeSet(T1);
    vector<string> set2 = getTreeSet(T2);
    vector<string> intersectionSet = setIntersection(set1, set2);

    vector<pair<list<string>, list<string>>> T2pairBipartitions;
    T2pairBipartitions = getPairBipartitions(T2);
    vector<pair<list<string>, list<string>>> T2reducedBipartitions = reduceBipartitionsToIntersection(T2pairBipartitions, intersectionSet);

    vector<pair<pair<list<string>, list<string>>, int>> bipartitionsOccurence = getBipartitionOccurences(T2reducedBipartitions);
    printBipartitionOccurences(bipartitionsOccurence);

}

void testBipartitionOccurenceDifference() {
    vector<string> set1 = getTreeSet(T1);
    vector<string> set2 = getTreeSet(T2);
    vector<string> intersectionSet = setIntersection(set1, set2);

    vector<pair<list<string>, list<string>>> T1pairBipartitions;
    T1pairBipartitions = getPairBipartitions(T1);

    vector<pair<list<string>, list<string>>> T2pairBipartitions;
    T2pairBipartitions = getPairBipartitions(T2);

    vector<pair<list<string>, list<string>>> T1reducedBipartitions = reduceBipartitionsToIntersection(T1pairBipartitions, intersectionSet);
    vector<pair<list<string>, list<string>>> T2reducedBipartitions = reduceBipartitionsToIntersection(T2pairBipartitions, intersectionSet);

    vector<pair<pair<list<string>, list<string>>, int>> T1bipartitionsOccurence = getBipartitionOccurences(T1reducedBipartitions);
    vector<pair<pair<list<string>, list<string>>, int>> T2bipartitionsOccurence = getBipartitionOccurences(T2reducedBipartitions);

    printBipartitionOccurences(T1bipartitionsOccurence);
    cout << "-------------------------" << endl;
    printBipartitionOccurences(T2bipartitionsOccurence);
    cout << "-------------------------" << endl;

    pair<int, int> result = bipartitionOccurencesDifference(T1bipartitionsOccurence,T2bipartitionsOccurence);
    cout << "Sum : " << result.first << endl;
    cout << "Card of 0 : " << result.second << endl;
}

void testSRF() {
    int SRFvalue = SRF(T1, T2, true);
}
