#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string s;
	vector <string> v = {"zero","one","two","three","four"};
	cin >> s;
	for (int i = 0; i < v.size();i++) 
		if (v[i] == s) {
			cout << i;
			return 1;
		}
	cout << "Я не знаю такого числа!";
	return 1;
}

