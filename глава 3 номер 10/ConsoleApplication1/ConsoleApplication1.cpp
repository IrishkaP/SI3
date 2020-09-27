#include <iostream>
using namespace std;

int main()
{
    double left, right;
    string operation;
    cin >> left >> right >> operation;
    if (operation == "+" or operation == "plus")
        cout << left + right;
    if (operation == "-" or operation == "minus")
        cout << left - right;
    if (operation == "*" or operation == "mul")
        cout << left * right;
    if (operation == "/" or operation == "div")
        cout << left / right;
}


