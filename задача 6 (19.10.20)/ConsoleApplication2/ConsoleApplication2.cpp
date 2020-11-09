#include <iostream>
#include "Queue.h"
#include "Bad_area.h"
using namespace std;



int main()
{
	try {
		setlocale(LC_ALL, "Russian");
		int m, n, e;
		char operation;
		cin >> m;
		Queue ex;
		for (int i = 0; i < m; i++) {
			cin >> operation;
			if (operation == '+') {
				cin >> n;
				ex.push(n);
				cout << "Ok" << endl;
			}
			if (operation == '-') {
				e = ex.pop();
				cout << e << endl;
			}
		}
	}
	catch (Bad_area) {
		cout << "Ошибочка (;_;)";
	}
}

