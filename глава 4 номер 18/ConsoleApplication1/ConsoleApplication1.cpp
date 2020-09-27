#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, c;
    double x1, x2 = 0;
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0)
            if (c == 0) {
                cout << "Бесконечное множество решений.";
                return 1;
            }
            else {
                cout << "Нет решений.";
                return 1;
            }
        else
            x1 = (-c) / b;
    }
    else
        if (b == 0)
        {
            if (c == 0)
                x1 = 0;
            else {
                x1 = 0;
                x2 = (-b) / a;
            }
        }
        else {
            x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
            x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        }
    if (x2 == 0 or x1 == x2)
        cout << x1;
    else
        cout << x1 << ' ' << x2;
}


