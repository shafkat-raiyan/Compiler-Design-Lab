#include <iostream>
#include <string>
using namespace std;

int main() {
  
    char dfa[14][2] = {
        // 'a'  'b'
        {'B', 'C'},  // State A (Start)
        {'D', 'E'},  // State B (Final)
        {'F', 'G'},  // State C
        {'D', 'E'},  // State D (Final)
        {'H', 'X'},  // State E ('X' is Empty)
        {'I', 'J'},  // State F (Final)
        {'B', 'G'},  // State G
        {'K', 'L'},  // State H
        {'D', 'E'},  // State I (Final)
        {'M', 'G'},  // State J
        {'D', 'E'},  // State K (Final)
        {'D', 'E'},  // State L (Final)
        {'D', 'N'},  // State M (Final)
        {'M', 'G'}   // State N (Final)
    };

    string input;
    cout << "Enter string: ";
    cin >> input;

    char currentState = 'A'; 

    for (char c : input) {
        int col;
    
        if (c == 'a') {
            col = 0;
        } 
        else if (c == 'b') {
            col = 1;
        } 
        else {
            cout << "Invalid input!" << endl;
            return 0;
        }

        int rowIndex = currentState - 'A';

        currentState = dfa[rowIndex][col];

        // for Dead State
        if (currentState == 'X') {
            cout << "Rejected" << endl;
            return 0;
        }
    }

    if (currentState == 'B' || currentState == 'D' || currentState == 'F' || 
        currentState == 'I' || currentState == 'K' || currentState == 'L' || 
        currentState == 'M' || currentState == 'N') {
        cout << "Accepted" << endl;
    } else {
        cout << "Rejected" << endl;
    }

    return 0;
}