#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "parser.hpp"
using namespace std;

void printVectorOfPairs(const std::vector<std::pair<std::list<std::string>, std::list<std::string>>>& myVector);

int main() {
    string newickString = "(ant:17, (bat:31, cow:22):7, dog:22, (elk:33, fox:12):40);";
    string realNewickString = "((((((Rf1:0.1,BtCoV_273_2005:0.1):0.029572[99],Rs3367:0.08225):0.13862[95],(SARS-CoV_BJ182-4:0.1519,(SARS:0.1,Tor2:0.1):0.1[68]):0.06475[96]):0.13000[90],((BtKY72:0.083591,BM48_31_BGR_2008:0.109237):0.102958[89],(((Guangxi_Pangolin_P5L:0.1,Guangxi_Pangolin_P2V:0.03031,Guangxi_Pangolin_P5E:0.1,Guangxi_Pangolin_P4L:0.1):0.1512[69],Guangxi_Pangolin_P1E:0.1):0.044731[99],(Guangdong_Pangolin_1_2019:0.1,Guangdong_Pangolin_P2S_2019:0.1):0.023527[98],((Hu_Wuhan_2020:0.1,Hu_USA_UT_00346_2020:0.1,Hu_Australia_VIC231_2020:0.1):0.1514[71],Hu_Italy_TE4836_2020:0.1):0.021999[99],((((((((Bovine_OH440:0.1513,Bovine_AH187:0.1):0.1[85],Bovine_CoV:0.03026):0.05009[70],Human_ent_4408:0.04421):0.021282[98],Human_OC43:0.025679,Rabbit_HKU14:0.020934,Porcine_v:0.061453):0.030787[54],Equine_NC99:0.037608):0.092544[78],(Rat_Parker:0.039312,(Murine_virus:0.1489,(Murine_RA59/R13:0.1,Murine_A59:0.1):0.1[64]):0.05843[82],Murine_JHM:0.023375):0.137159[99]):0.100637[60],HKU1:0.134974):0.378470[58],(Bat_HKU4-1:0.199004,Bat_HKU5-1:0.195437,MERS-CoV_S:0.141351):0.419370[61],Feline_per:0.1):17.297781[100],RaTG13:0.1,(Bat_CoVZXC21:0.1,Bat_CoVZC45:0.1):0.035274[100]):0.106789[74]):0.038312[88]):0.021613[91],BtCoV_279_2005:0.020537):0.15542[100],HKU3-6:0.1,HKU3-12:0.1);";

    int result = 0;

    vector<string> test = getStageElements(newickString);
    //cout << test.size() << endl;
    vector<string> taxons;
    vector<vector<string>> stageVector;

    for (int i = 0; i < test.size(); i++) {

        stageVector.push_back(parseStage(test[i]));
    }

    vector<pair<list<string>, list<string>>> finalResult;

    finalResult = stageBipartitioner(stageVector);

    printVectorOfPairs(finalResult);



    return 0;
}




void printVectorOfPairs(const std::vector<std::pair<std::list<std::string>, std::list<std::string>>>& myVector) {
    for (const auto& pair : myVector) {
        const std::list<std::string>& firstList = pair.first;
        const std::list<std::string>& secondList = pair.second;

        std::cout << "First list elements:" << std::endl;
        for (const std::string& str : firstList) {
            std::cout << str << std::endl;
        }

        std::cout << "Second list elements:" << std::endl;
        for (const std::string& str : secondList) {
            std::cout << str << std::endl;
        }
    }
}

