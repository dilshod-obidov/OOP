#include <iostream>
#include <string>

using namespace std;

int main(){
    string str1 = "I like ";
    string str2 = "string class";
    string str3 = str1 + str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    str1 += str2;
    if(str1 == str3)
        cout << "The two strings are identical" << endl;
    else 
        cout << "The two strings are different" << endl;

    string str4;
    cout << "Enter a string: ";
    cin >> str4;
    cout << "You entered: " << str4 << endl;

    return 0;
}