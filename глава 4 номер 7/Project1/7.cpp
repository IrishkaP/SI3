#include <iostream>
#include <string>
using namespace std;
void result(double left, double right, char oper){
    if (oper == '+') cout << "Сумма " << left << " и " << right << " равна " << left + right << "." << endl;
    if (oper == '-') cout << "Разность " << left << " и " << right << " равна " << left - right << "." << endl;
    if (oper == '*') cout << "Произведение " << left << " и " << right << " равно " << left * right << "." << endl;
    if (oper == '/') cout << "Деление " << left << " на " << right << " равно " << left / right << "." << endl;
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