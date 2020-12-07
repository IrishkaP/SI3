#include <iostream>
#include <vector>
#include "edx-io.hpp"
using namespace std;

int main()
{
    int n,i,x;
    io >> n;
    vector<int> a,b;
    b.push_back(1);
    for (i = 0; i < n; i++) {
        io >> x;
        a.push_back(x);
    }
    for (int j = 1; j < n; j++) {
        i = j - 1;
        while (i >= 0 && a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
            i--;
        }
        b.push_back(i+2);
    }
    for (i = 0; i < b.size(); i++) {
        io << b[i] << ' ';
    }
    io << "\n";
    for (i = 0; i < n; i++) {
        io << a[i]<<' ';
    }
}

