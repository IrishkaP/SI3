#include <iostream>
#include <string>
using namespace std;
void result(double left, double right, char oper){
    if (oper == '+') cout << "����� " << left << " � " << right << " ����� " << left + right << "." << endl;
    if (oper == '-') cout << "�������� " << left << " � " << right << " ����� " << left - right << "." << endl;
    if (oper == '*') cout << "������������ " << left << " � " << right << " ����� " << left * right << "." << endl;
    if (oper == '/') cout << "������� " << left << " �� " << right << " ����� " << left / right << "." << endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    char operation;
    double a, b;
    string s, c, d;
    cin >> a >> b >> operation;
    result(a, b, operation);
    cin >> s;
    c = s[0]; d = s[2];
    int i = stoi(c);
    int j = stoi(d);
    result(i, j, s[1]);
    return 0;
}