#include <iostream>
#include "edx-io.hpp"
#include <vector>
using namespace std;

int main()
{
    int n, i, x, minimum_znach, minimum_pos;
    io >> n;
    vector<pair <double,int>> a;
    for (i = 0; i < n; i++) {
        io >> x;
        a.push_back(make_pair(x,i));
    }
    for (int j = 0; j < n-1; j++) {
        minimum_znach = a[j + 1].first;
        minimum_pos = a[j + 1].second;
        for (i = j + 2; i < n;i++)
            if (a[i].first < minimum_znach) {
                minimum_znach = a[i].first;
                minimum_pos = a[i].second;
            }
        if (minimum_znach < a[j].first) {
            swap(a[j].first, a[minimum_pos].first);
            io << "Swap elements at indices " << j+1 << " and " <<minimum_pos+1<< ".\n";
        }
    }
    io << "No more swaps needed.";
}

