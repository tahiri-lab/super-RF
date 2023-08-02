#include "parser.hpp"

/**
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

 */

vector<string> getStringStackBipartitions(string inputString) {
    vector<string> result;
    stack<string> stack;
    string subString = "";

    for(char c : inputString) {
        if(c == '(') {
            subString = "";
            stack.push(subString);
        } else if (c == ')') {
            result.push_back(stack.top());
            stack.pop();
        } else {
            subString += c;
            if (!stack.empty()) {
                stack.top() = (stack.top() += c);
            }
        }
    }
    return result;
}

/**
 * @brief deletes a taxon distance
 *
 * @param inputString a taxon with its distance : "cat:13"
 * @return taxon without its distance : "cat"
 * */
string deleteTaxonDistance(string inputString) {
    string result;

    for(char c: inputString) {
        if (c == ':'){
            break;
        }
        result += c;
    }
    return result;
}

/**
 * @brief splits a string in Newick format such as bat:31, cow:22, goat:21, bird:12 into a vector<string>
 *
 * @param inputString newick format string : "bat:31, cow:22, goat:21, bird:12"
 * @return vector<string> : bat cow goat bird
 * */
vector<string> splitStringToVector(string inputString) {
    vector<string> result;
    string subString;

    for(char c: inputString) {
        if(c == ',' && subString != "") {
            if (deleteTaxonDistance(subString) != "") {
                result.push_back(deleteTaxonDistance(subString));
            }
            subString = "";
        } else if (c != ' '){
            subString += c;
        }
    }
    if ((deleteTaxonDistance(subString) != "")) {
        result.push_back(deleteTaxonDistance(subString));
    }
    return result;
}

/**
 * @brief gets all taxons of a phylogenetic tree
 *
 * @param inputString newick representation of the tree
 * @return vector<string> where each string is one of the tree's taxon
 * */
vector<string> getAllTaxons(string inputString) {
    vector<string> result;
    vector<string> stringBipartitions = getStringStackBipartitions(inputString);
    vector<string> currentVector;

    for (string s: stringBipartitions) {
        currentVector = splitStringToVector(s);
        result.insert(result.end(), currentVector.begin(), currentVector.end());
    }
    return result;
}

/**
 * @brief creates a pair<list<string>, list<string>> bipartition
 *
 * @param allSpecies a vector<string> with all taxons from a tree
 * @param currentBipartition a vector<string> with a tree bipartition's species
 *
 * @return a pair<list<string>, list<string>> corresponding to a bipartition, each list being a side of the tree
 *         bipartition
 * */
pair<list<string>, list<string>> createPairBipartition(vector<string> allSpecies, vector<string> currentBipartition) {
    pair<list<string>, list<string>> result;
    list<string> list1;
    list<string> list2;

    for(string s: currentBipartition) {
        list1.push_back(s);
    }

    for(string s: allSpecies) {
        if (!findStringInList(list1, s)) {
            list2.push_back(s);
        }
    }

    result.first = list1;
    result.second = list2;

    return result;
}

/**
 * @brief checks if a string is present in a list<string>
 *
 * @param list the list
 * @param target the string target
 *
 * @return true if target found
 * */
bool findStringInList(list<string> list, string target) {
    bool result = false;
    for (string s: list) {
        if(s == target) {
            result = true;
            break;
        }
    }
    return result;
}



/**
 * @brief gets all bipartions of a phylogenetical tree in Newick representation
 *
 * @param newickInputString newick representation of the phylogenetic tree
 * @return <vector<pair<list<string>, list<string>>> where each pair corresponds to a bipartition
 * */
vector<pair<list<string>, list<string>>> getBipartitions(string newickInputString) {

}