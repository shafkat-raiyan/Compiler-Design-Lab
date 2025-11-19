#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;


unordered_set<string> keywords = {
    "int", "float", "double", "char", "string", "return", "if", "else", 
    "while", "for", "void", "main", "true", "false"
};

unordered_set<string> operators = {
    "+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">=", "<<", ">>", 
    "++", "--", "&&", "||", "!"
};

unordered_set<string> punctuation = {
    "(", ")", "{", "}", ";", ",", ".", ":", "[", "]"
};


bool DetermineIdentifier(const string &val) {
    if (val.empty()) return false;

    // First char must be letter or underscore
    char first = val[0];
    bool firstValid = (first >= 'A' && first <= 'Z') || 
                      (first >= 'a' && first <= 'z') || 
                      (first == '_');

    if (!firstValid) return false;

    // Rest can be alphanumeric or underscore
    for (int i = 1; i < val.length(); i++) {
        char ch = val[i];
        bool valid = (ch >= 'A' && ch <= 'Z') || 
                     (ch >= 'a' && ch <= 'z') || 
                     (ch >= '0' && ch <= '9') || 
                     (ch == '_');
        if (!valid) return false;
    }
    return true;
}


bool isConstant(const string &val) {
    if (val.empty()) return false;

   
    if (val.length() >= 2 && val.front() == '"' && val.back() == '"') return true;


    if (val.length() >= 3 && val.front() == '\'' && val.back() == '\'') return true;

  
    bool hasDecimal = false;
    for (int i = 0; i < val.length(); i++) {
        char ch = val[i];
        
   
        if (ch == '-' && i == 0) continue;

        if (ch == '.') {
            if (hasDecimal) return false; 
            hasDecimal = true;
        }
        else if (ch < '0' || ch > '9') {
            return false; // Not a digit
        }
    }
    return true;
}

int main() {
    ifstream file("source.txt");

    if (!file) {
        cerr << "Error: Could not open source.txt" << endl;
        return 1;
    }

    string token;
    
    cout << "Token\t\tType" << endl;
    cout << "-------------------------" << endl;


    while (file >> token) {
        
        if (keywords.count(token)) {
            cout << token << "\t\tKeyword" << endl;
        }
        else if (operators.count(token)) {
            cout << token << "\t\tOperator" << endl;
        }
        else if (punctuation.count(token)) {
            cout << token << "\t\tPunctuation" << endl;
        }
        else if (isConstant(token)) {
            cout << token << "\t\tConstant" << endl;
        }
        else if (DetermineIdentifier(token)) {
            cout << token << "\t\tIdentifier" << endl;
        }
        else {
            cout << token << "\t\tInvalid Token" << endl;
        }
    }

    file.close();
    return 0;
}