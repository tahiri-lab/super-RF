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

int countWordsInParentheses(const string& inputString) {
    // Remove any leading or trailing whitespaces
    string trimmedString = inputString;
    size_t start_pos = trimmedString.find_first_not_of(" \t");
    size_t end_pos = trimmedString.find_last_not_of(" \t");
    if (start_pos != string::npos && end_pos != string::npos)
        trimmedString = trimmedString.substr(start_pos, end_pos - start_pos + 1);

    // Check if the input string is empty or invalid
    if (trimmedString.empty() || trimmedString[0] != '(' || trimmedString.back() != ')')
        return 0;

    // Extract the words within parentheses
    string words_inside_parentheses = trimmedString.substr(1, trimmedString.length() - 2);

    // Count the number of words within parentheses
    int count = 1; // At least one word is always present
    for (char c : words_inside_parentheses) {
        if (c == ',') {
            count++;
        }
    }
    return count;
}

int countSubTrees(string inputString) {
    int result = 0;
    char currentChar;
    for (int i = 0; i < inputString.length(); i++) {
        currentChar = inputString[i];
        if (currentChar == '(') {
            result ++;
        }
    }
    return result;
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


int countElementsInParenthesis(string str) {
    if (str[0] == '(') {
        str.erase(0,1);
    }

    int count = 0;
    int parLevel = 0;

    for (char c : str) {
        if (c == '(') {
            parLevel ++;
        }
        if (c == ')') {
            parLevel --;
        }
        if (parLevel == 0 && c == ',') {
            count ++;
        }
    }
    count ++; //for the last element
    return count;
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

    if (stageElts >= 4 ) {
        for (int cutIndex = 2; cutIndex <= stageElts - 2; cutIndex++ ) {
            currentPair = cutStringVector(stageVector, cutIndex);
            result.push_back(currentPair);
        }
    }

    /**
    for (int i = 0; i < stageVector.size(); i++) {
        for (int j = 0; j < stageVector[i].size(); j++) {
            cout << stageVector[i][j] << endl;
        }
        cout << endl;
    }
    */

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