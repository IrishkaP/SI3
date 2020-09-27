#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int a;
    cin >> a;
    if (a % 2 == 0)
        cout << "Число " << a << " является четным.";
    else
        cout << "Число " << a << " является нечетным.";
}


