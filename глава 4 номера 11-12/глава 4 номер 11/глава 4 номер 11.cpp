
#include <iostream>
#include <vector>
using namespace std;


bool check(int number) {
    int i = 0;
    vector <int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    if (number == 1) return false;
    while (primes[i] < number) {
        if (number % primes[i] == 0) return false;
        i++;
    }
    return true;
}

int main()
{
    int max;
    cin >> max;
    vector <int> result;
    for (int i = 1; i <= max; i++)
        if (check(i) == true)
            result.push_back(i);
    for (int i = 0; i < result.size();i++)
        cout << result[i] << " ";
}

