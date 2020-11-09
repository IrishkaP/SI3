#include <iostream>
#include "Queue.h"
#include "Bad_area.h"
using namespace std;

int main()
{
	try {
		setlocale(LC_ALL, "Russian");
		Queue res;
		char instruction;
		int x, result_pop, result_min, k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> instruction;
			if (instruction == '+') {
				cin >> x;
				res.push(x);
				cout << "OK" << endl;
			}
			if (instruction == '-') {
				result_pop = res.pop();
				cout << result_pop << endl;
			}
			if (instruction == '?') {
				result_min = res.min();
				cout << result_min << endl;
			}
		}
	}
	catch (Bad_area) {
		cout << "Ошибочка :(";
	}
}
