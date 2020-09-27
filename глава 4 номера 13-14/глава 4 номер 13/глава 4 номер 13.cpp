

#include <iostream>
using namespace std;

int main()
{
    int max;
    cin >> max;
    int* a = new int[max + 1];
    for (int i = 1; i <= max; i++)
        a[i] = i;
    for (int p = 2; p <= max; p++)
    {
        if (a[p] != 0)
        {
            cout << a[p] << " ";
            for (int j = p * p; j <= max; j += p)
                a[j] = 0;
        }
    }
}


