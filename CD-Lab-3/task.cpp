/* Write a program to determine whether the Given Input is Identifier or Not. []
Conditions/convention to detect identifier:

a) The first character should be alphabet characters/underscore (A-Z, a-z, _)
b) From the Second character should be alpha-numeric characters/underscore (A-Z, a-z, _ , 0-9)
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool DetermineIdentifier(string val) {

    if (val.empty()) return false;


    for (char ch : val) {
        if (ch == ' ') return false;
    }


    char first = val[0];
    bool firstValid = (first >= 65 && first <= 90) ||
                      (first >= 97 && first <= 122) ||
                      (first == 95);

    if (!firstValid) return false;


    for (int i = 1; i < val.length(); i++) {
        char ch = val[i];
        bool valid = (ch >= 65 && ch <= 90) ||
                     (ch >= 97 && ch <= 122) ||
                     (ch >= 48 && ch <= 57) ||
                     (ch == 95);
        if (!valid) return false;
    }

    return true;
}


int main() {
    ifstream file("C:/Users/student/Pictures/Compiler Lab Task/source.txt");
    string line;

    if (!file) {
        cerr << "Error opening file!" << endl;
    }
    int count=1;

    while (getline(file, line)) {
        bool res=DetermineIdentifier(line);
        if(res==true){
            cout<<"Identifier is valid at line "<<count<<endl;
            count++;
        }else{
            cout<<"Identifier is invalid at line "<<count<<endl;
            count++;
        }

    }

    file.close();
    return 0;
}
