#include <iostream>
#include <vector>
using namespace std;
class oshibka {};

vector <double> root(int a, int b, int c) {
    double x1, x2 = 0;
    vector <double> v;
    if (a == 0) {
        if (b == 0)
            if (c == 0) {
                cout << "Бесконечное множество решений.";
                return v = { 0,0 };
            }
            else {
                throw oshibka();
                return v = { 0,0 };
            }
        else {
            double k = (-c) / b;
            v = { k,0 };
        }
    }
    else
        if (b == 0)
        {
            if (c == 0)
                v = { 0,0 };
            else {
                double k = (-c) / a;
                v = { sqrt(k),-sqrt(k)};
            }
        }
        else {
            if (b * b - 4 * a * c < 0) throw oshibka();
            v.push_back((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
            v.push_back((-b - sqrt(b * b - 4 * a * c)) / (2 * a));
        }
    return v;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, c;
    double x1, x2 = 0;

    vector <double> result;
    cin >> a >> b >> c;
    try {
        result = root(a, b, c);
        if ((result[1] == 0 && result[0] != result[1]) or (result[0]==result[1] && result[0] != 0))
            cout << result[0];
        else
            if (result[0] != result[1])
            cout << result[0] << ' ' << result[1];
    }
    catch (oshibka) {
        cout << "Нет корней.";
    }
    return 1;
}


