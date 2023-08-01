#include "parser.hpp"


vector<string> parseStage(string stageString) {
    //newickString = "(ant:17, (bat:31, cow:22):7, dog:22, (elk:33, fox:12):40)";

    string subString; //string used to store what's currently red by the function
    vector<string> taxons;

    for (int i = 0; i < stageString.length(); i++) {
        char currentChar = stageString[i];
        if (currentChar != '(' && currentChar != ')') {
            subString += currentChar;
        }

        if (currentChar == ',') {
            taxons.push_back(cleanTaxon(subString));
            subString = "";
        }
    }
    taxons.push_back(cleanTaxon(subString));
    return taxons;
}

string deleteSpaces(string inputString) {
    string result;
    for (char c : inputString) {
        if (c != ' ') {
            result += c;
        }
    }
    return result;
}

string cleanTaxon(string taxon) {
    string result;
    taxon = deleteSpaces(taxon);

    for (char c : taxon) {
        if (c == ':') {
            return result;
        }
        result += c;
    }
    return result;
}

vector<pair<string, string>> splitFullNewick(string inputString) {
    vector<pair<string, string>> result;

    string firstBip;
    string secondBip;

    return result;
}

vector<string> getStageElements(string str) {
    vector<string> result;
    string subString;

    if (str[0] == '(') {
        str.erase(0,1);
    }

    int parLevel = 0;
    int currentParLevel = 0;

    for (char c : str) {
        currentParLevel = parLevel;
        subString += c;

        if (c == '(') {
            parLevel ++;
        }
        if (c == ')') {
            parLevel --;
        }

        if (currentParLevel != parLevel ) {
            result.push_back(subString);
            cout << subString << endl;
            subString = "";
        }
    }
    return result;
}

//TODO compléter la fonction
vector<pair<list<string>, list<string>>> stageBipartitioner(vector<vector<string>> stageVector) {
    vector<pair<list<string>, list<string>>> result;
    pair<list<string>, list<string>> currentPair;

    int stageElts = stageVector.size(); //TODO clean stageVector to delete empty strings and have the proper number of elements

    cout << "Elements in the stage : " << stageVector.size() << endl;
    printVectorUtil(stageVector);


    if (stageElts >= 4 ) {
        for (int cutIndex = 2; cutIndex <= stageElts - 2; cutIndex++ ) {
            cout << "Cut index : " << cutIndex << endl;
            currentPair = cutStringVector(stageVector, cutIndex); //TODO problème de vecteur ici, à voir si envoyé avec les mauvaises espèces
            result.push_back(currentPair);
        }
    }

    return result;
}

pair<list<string>, list<string>> cutStringVector(vector<vector<string>> vector, int cutIndex) {
    pair<list<string>, list<string>> result;

    list<string> firstBipartition;
    list<string> secondBipartition;

    for (int i = 0; i < vector.size(); i++) {
        for (int j = 0; j < vector[i][j].size(); j++) {
            if (i < cutIndex) {
                firstBipartition.push_back(vector[i][j]);
            } else {
                secondBipartition.push_back(vector[i][j]);
            }
        }
    }
    result.first = firstBipartition;
    result.second = secondBipartition;
    return result;
}


void printVectorUtil(vector<vector<string>> vectorInput) {
    for (vector v : vectorInput) {
        for (string s : v) {
            cout << s << endl;
        }
        cout << "---" << endl;
    }
}

//TODO function to count number of elements in whole Newick for it to stop the recursion
//TODO when all steps analyzed, recursion is stoped
//TODO find a tuto to create recursion functions