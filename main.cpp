#include <iostream>
#include "MyString.hpp"

using std::cout;
using std::endl;
using string=custom::String;


int main()
{
    string str = string("omg lol");

    for (char c : str) {
        cout << c;
    }
    cout << endl;

    for (auto it = str.begin(); it != str.end(); ++it) {
        cout << *it;
    }
    cout << endl;

    return 0;
}
