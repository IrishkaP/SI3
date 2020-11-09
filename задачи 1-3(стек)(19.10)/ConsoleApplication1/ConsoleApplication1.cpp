#include <iostream>
#include "Stack.h"
#include "Bad_area.h"
using namespace std;

int main()
{
	try {
		setlocale(LC_ALL, "Russian");
		Stack res;
		string instruction;
		int x, result_pop,result_top,result_size;
		cin >> instruction;
		while (instruction != "exit") {
			if (instruction == "push") {
				cin >> x;
				res.push(x);
				cout << "OK" << endl;
			}
			if (instruction == "pop") {
				result_pop = res.pop();
				cout << result_pop << endl;
			}
			if (instruction == "top") {
				result_top = res.top();
				cout << result_top << endl;
			}
			if (instruction == "size") {
				result_size = res.size();
				cout << result_size << endl;
			}
			if (instruction == "clear") {
				res.clear();
				cout << "OK" << endl;
			}
			cin >> instruction;
		}
		cout << "bye";
	}
	catch (Bad_area) {
		cout << "Ошибочка :(";
	}
}


