#include <iostream>
#include <vector>
using namespace std;
bool check(int number) {
    for (int i = 2; i < number; i++)
        if (number % i == 0)
            return false;
    return true;
}

int main()
{
    vector <int> v;
    int n,k = 0,i = 2;
    cin >> n;
    while (k != n) {
        if (check(i) == true) {
            k++;
            v.push_back(i);
        }
        i++;
    }
    for (int i = 0; i < v.size();i++)
        cout << v[i] << ' ';
}


