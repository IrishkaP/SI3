#include <iostream>
#include <vector>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    vector <string> v = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int c, i = 0;
    string s;
    cin >> c;
    if (c < v.size())
        cout << v[c]<< endl;
    else
    {
        cout << "Неверные входные данные.";
        return 1;
    }
    cin >> s;
    for (int i = 0;i < v.size();i++)
        if (v[i] == s)
        {
            cout << i;
            return 1;
        }
    cout << "Неверные входные данные.";
    return 0;
}