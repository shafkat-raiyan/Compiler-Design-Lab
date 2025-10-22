#include<iostream>
using namespace std;

void constant_checker() {
      string s;
      cin>>s;

      for (int i=0; i<s.length(); i++) {

        if( (int)s[i] >= 48 && (int)s[i] <= 57  ) {

           cout<<"Numeric Constant";
           break;

           }

        else {

            cout<<"Not Numeric";
            break;
        }

      }

}


void operator_checker() {
    char arr1[] = { '+', '-', '*', '/', '%', '=' };
    string s;
    cin >> s;

    char temp[s.length()];
    int count = 0;


    for (int i = 0; i < s.length(); i++) {

        for (int j = 0; j < 6; j++) {
            if (s[i] == arr1[j]) {
                temp[count] = s[i];
                count++;
                break;
            }
        }
    }


    for (int i = 0; i < count; i++) {
        cout << "Operator " << i + 1 << ": " << temp[i] << endl;
    }
}


void comment_checker() {
    string s;


    getline(cin, s);


    if (s[0] == '/' && s[1] == '/') {
        cout << "Single line Comment" << endl;
    }

    else if (s[0] == '/' && s[1] == '*' && s[s.length() - 2] == '*' && s[s.length() - 1] == '/') {
        cout << "Multi line Comment" << endl;
    }
    else {
        cout << "Not a Comment" << endl;
    }
}




int main() {

    //constant_checker();
    //operator_checker();
    comment_checker();

}
