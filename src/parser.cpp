#include "../include/parser.hpp"

/**
 * @brief cuts a Newick string into a vector of strings, each string containing species of a bipartition
 *
 * @param inputString Newick representation of a phylogenetical tree
 *
 * @return vector<string>, each string containing a bipartition species
 * */
vector<string> getStringStackBipartitions(string inputString) {
    vector<string> result;
    stack<string> stringStack;
    string subString = "";

    int level = -1;
    stack<string> memoryStack;

    for(char c : inputString) {
        if(c == '(') {
            subString = "";
            stringStack.push(subString);
            level ++;
        } else if (c == ')') {
            result.push_back(stringStack.top());
            stringStack.pop();
            level --;
        } else {
            subString += c;
            if (!stringStack.empty()) {
                stringStack.top() = (stringStack.top() += c);
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
        //getting rid of taxon's distances
        if (c == ':'){
            break;
        }
        //getting rid of remaining parenthesis
        if (c != '(' && c != ')') {
            result += c;
        }
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
 * @brief splits a string in Newick format such as bat:31, cow:22, goat:21, bird:12 into a list<string>
 *
 * @param inputString newick format string : "bat:31, cow:22, goat:21, bird:12"
 * @return list<string> : bat cow goat bird
 * */
list<string> splitStringToList(string inputString) {
    list<string> result;
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
 * @brief
 *
 * @param inputVector a vector<pair<string, int>> containing leveled strings from a Newick representation (obtained via
 *         levelVectorBuilder function)
 *
 * @return vector<string> with all bipartitinos as strings
 * */
vector<string> getStringBipartitions(vector<pair<string, int>> inputVector) {
    vector<string> result;
    string currentString;
    int currentLevel = 0;
    int currentIndex = -1;

    for (pair<string, int> p: inputVector) {
        currentIndex ++;
        if (p.second > currentLevel) {
            vector<pair<string, int>> newVector(inputVector.begin() + currentIndex, inputVector.end());
            //printVectorOfPairs2(newVector);
            result.push_back(splitSubVectorOfPairs(newVector, p.second));
        }
        currentLevel = p.second;
    }
    return result;
}

/**
 * @brief builds a vector<pair<string, int>> from a Newick string
 *
 * @param inputString Newick representation
 * @return vector<pair<string, int>>, string being the content and int the level of its content
 * */
vector<pair<string, int>> levelVectorBuilder(string inputString) {
    vector<pair<string, int>> result;
    pair<string, int> currentPair;
    string subString;
    int level = -1;

    for(char c: inputString) {
        //TODO get all content in parenthesis every time there is a new one
        if (c == '(') {
            if (subString != "") {
                currentPair.first = subString;
                currentPair.second = level;
                result.push_back(currentPair);
                subString = "";
            }
            level ++;
        } else if (c == ')') {
            if (subString != "") {
                currentPair.first = subString;
                currentPair.second = level;
                result.push_back(currentPair);
                subString = "";
            }
            level --;
        }
        subString += c;
    }
    return result;
}

/**
 * @brief splits a vector<pair<string, int>> into a single level
 *
 * @param departureLevel level beyond which it cuts the initial vector
 * @param subVector subpart to cut
 *
 * @return entire bipartition level string
 * */
string splitSubVectorOfPairs(vector<pair<string, int>> subVector, int departureLevel) {
    string result;
    for (pair<string, int> p: subVector) {
        if(p.second < departureLevel) {
            break;
        }
        result += p.first;
    }
    return result;
}

/**
 * @brief delete duplicates bipartitions
 *
 * @param inputVector vector<pair<list<string>, list<string>>>
 * @return vector<pair<list<string>, list<string>>>, all bipartitions of a tree without duplicates
 * */
vector<pair<list<string>, list<string>>> deleteDuplicates(vector<pair<list<string>, list<string>>> inputVector) {
    /*
    vector<pair<list<string>, list<string>>> result;
    vector<pair<list<string>, list<string>>> seenBipartitions;


    for (pair<list<string>, list<string>> inputPair : inputVector) {
        for(pair<list<string>, list<string>> p : seenBipartitions) {
            if(!areListsEqual(inputPair.first, p.first)) {
                if(!areListsEqual(inputPair.first, p.second)) {
                    result.push_back(inputPair);
                }
            }
        }
        seenBipartitions.push_back(inputPair);
    }

    return result;
     */

    vector<pair<list<string>, list<string>>> result;
    vector<pair<list<string>, list<string>>> seenBipartitions;

    for (pair<list<string>, list<string>> inputPair : inputVector) {
        bool duplicateFound = false;

        for (pair<list<string>, list<string>>& p : seenBipartitions) {
            if (isDuplicate(inputPair, p)) {
                duplicateFound = true;
                break;
            }
        }

        if (!duplicateFound) {
            result.push_back(inputPair);
            seenBipartitions.push_back(inputPair);
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
vector<pair<list<string>, list<string>>> getPairBipartitions(string newickInputString) {
    vector<pair<list<string>, list<string>>> result;

    vector<string> stringBipartitions;
    vector<string> allSpecies;
    vector<vector<string>> bipartitionsVector;
    vector<pair<string, int>> pairVector;

    allSpecies = getAllTaxons(newickInputString);

    pairVector = levelVectorBuilder(newickInputString);

    stringBipartitions = getStringBipartitions(pairVector);

    for(string s : stringBipartitions) {
        bipartitionsVector.push_back(splitStringToVector(s));
    }

    for (vector<string> v: bipartitionsVector) {
        result.push_back(createPairBipartition(allSpecies, v));
    }
    return deleteDuplicates(result);
}

/**
 * @brief gets all bipartitions of a tree and returns a vector<list<string>>, each list<string> being a bipartition
 *
 * @param newickInputString Newick representation of a phylogenetical tree
 * @return vector<list<string>>, each list<string> being a bipartition
 * */
vector<list<string>> getBipartitions(string newickInputString) {
    vector<string> stringBipartitions;
    vector<list<string>> bipartitionsList;
    vector<pair<string, int>> pairVector;

    pairVector = levelVectorBuilder(newickInputString);

    stringBipartitions = getStringBipartitions(pairVector);

    for(string s : stringBipartitions) {
        bipartitionsList.push_back(splitStringToList(s));
    }

    return bipartitionsList;
}



/**
 * UTIL functions
 * */
void printVectorOfPairs2(const vector<pair<string, int>> data) {
    for (const auto& pair : data) {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }
}

void printVectorOfListOfString(vector<list<string>> input) {
    for(list<string> stringList : input ) {
        for (string s: stringList) {
            cout << s << " " ;
        }
        cout << endl;
    }
}

void printVectorOfString(vector<string> inputVector) {
    for(string s: inputVector) {
        cout << s << ", ";
    }
    cout << endl;
}

/**
 * @brief util function to print a vector<pair<list<string>, list<string>>>
 *
 * @param vector vector<pair<list<string>, list<string>>> to print
 * */
void printVectorOfPairs(vector<pair<list<string>, list<string>>> vector) {
    for (pair p : vector) {
        cout << "FIRST : " << endl;
        for (string s : p.first) {
            cout << s << endl;
        }
        cout << "--------------------------------------------------" << endl;
        cout << "SECOND : " << endl;
        for (string s : p.second) {
            cout << s << endl;
        }
        cout << endl;
    }
}

void printPairOfLists(pair<list<string>, list<string>> inputPair) {
    for (string s : inputPair.first) {
        cout << s << endl;
    }
    cout << "--------------------------------------------------" << endl;
    cout << "SECOND : " << endl;
    for (string s : inputPair.second) {
        cout << s << endl;
    }
    cout << endl;
}

bool isDuplicate(pair<list<string>, list<string>> inputPair, pair<list<string>, list<string>> existingPair) {
    return (areListsEqual(inputPair.first, existingPair.first) &&
            areListsEqual(inputPair.second, existingPair.second)) ||
           (areListsEqual(inputPair.first, existingPair.second) &&
           areListsEqual(inputPair.second, existingPair.first));
}



/**
 * @brief extracts newick strings from a txt file
 * */
pair<string, string> extractNewickFromFile(string inputFile) {
    std::ifstream input(inputFile);
    if (!input.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return std::make_pair("", "");
    }

    std::pair<std::string, std::string> extractedPair;
    std::string firstString, secondString;

    std::getline(input, firstString, ';');
    std::getline(input, secondString, ';');

    input.close();

    extractedPair = std::make_pair(firstString, secondString);

    // Remove '\n' at the beginning of the second string
    if (!extractedPair.second.empty() && extractedPair.second[0] == '\n') {
        extractedPair.second.erase(0, 1);
    }

    return extractedPair;
}
