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

void identifier_checker()
{
    string s;
    cout << "Enter input for Identifier Checker: ";
    cin >> s;

    if (s.empty())
    {
        cout << "Not an Identifier (empty)" << endl;
        return;
    }

    char firstChar = s[0];
    bool isFirstCharValid = (firstChar >= 'a' && firstChar <= 'z') ||
                            (firstChar >= 'A' && firstChar <= 'Z') ||
                            (firstChar == '_');

    if (!isFirstCharValid)
    {
        cout << "Not an Identifier (invalid first character)" << endl;
        return;
    }


    for (int i = 1; i < s.length(); i++)
    {
        char currentChar = s[i];
        bool isCharValid = (currentChar >= 'a' && currentChar <= 'z') ||
                           (currentChar >= 'A' && currentChar <= 'Z') ||
                           (currentChar >= '0' && currentChar <= '9') ||
                           (currentChar == '_');

        if (!isCharValid)
        {
            cout << "Not an Identifier (invalid character at position " << i << ")" << endl;
            return;
        }
    }

    cout << "Is an Identifier" << endl;
}

void array_average()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    double arr[n];
    double sum = 0.0;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    double average = sum / n;
    cout << "Average: " << average << endl;
}

void array_min_max()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;


    int arr[n];

    cout << "Enter " << n << " elements: ";
    
    cin >> arr[0];
    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }

    cout << "Minimum value: " << minVal << endl;
    cout << "Maximum value: " << maxVal << endl;
}

void concatenate_names()
{
    string firstName, lastName;
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;

    string fullName = firstName + " " + lastName;
    cout << "Full name: " << fullName << endl;
}


int main() {

    //constant_checker();
    //operator_checker();
    //comment_checker();
    //identifier_checker();
    //array_average();
    //array_min_max();
    //concatenate_names();
    int choice;
    cout << "\n--- Function Menu ---" << endl;
        cout << "1. Constant Checker" << endl;
        cout << "2. Operator Checker" << endl;
        cout << "3. Comment Checker" << endl;
        cout << "4. Identifier Checker" << endl;
        cout << "5. Array Average" << endl;
        cout << "6. Array Min/Max" << endl;
        cout << "7. Concatenate Names" << endl;
        cout << "-----------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            constant_checker();
            break;
        case 2:
            operator_checker();
            break;
        case 3:
            cout << "Enter input for Comment Checker: ";
            comment_checker();
            break;
        case 4:
            identifier_checker();
            break;
        case 5:
            array_average();
            break;
        case 6:
            array_min_max();
            break;
        case 7:
            concatenate_names();
            break;

        }
}
