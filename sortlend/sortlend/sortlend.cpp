#include <iostream>
#include "edx-io.hpp"
#include <vector>
using namespace std;

int main()
{
    int n, i;
    io >> n;
    double x;
    vector<pair <double,int>> a;
    for (i = 0; i < n; i++) {
        io >> x;
        a.push_back(make_pair(x,i+1));
    }
    for (int j = 1; j < n; j++) {
        i = j - 1;
        while (i >= 0 && a[i].first > a[i + 1].first) {
            swap(a[i], a[i + 1]);
            i--;
        }
    }
        io << a[0].second << ' ' << a[a.size()/2].second << ' ' << a[a.size()-1].second;
}


