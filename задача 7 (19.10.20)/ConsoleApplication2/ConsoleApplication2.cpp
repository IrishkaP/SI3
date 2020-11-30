#include <iostream>
#include <stack>
#include <algorithm>
#include "edx-io.hpp"
using namespace std;

class Bad_area
{
};

class Queue
{
	stack< pair <int,int> > s1, s2;

public:
	void push(int x);
	int pop();
	int mini();
};

void Queue::push(int x) {
	int minima;
	if (!s1.empty())
		minima = min(x, s1.top().second);
	else
		minima = x;
    s1.push (make_pair (x, minima));
}
int Queue::pop() {
	if (s2.empty())
	while (!s1.empty()) {
		int element = s1.top().first;
		s1.pop();
		int minima = s2.empty() ? element : min (element, s2.top().second);
		s2.push (make_pair (element, minima));
	}
    int result = s2.top().first;
    s2.pop();
	return result;
}
int Queue::mini() {
	int current_minimum;
	if (s1.empty())
	 current_minimum =  s2.top().second;
	else
		if (s2.empty())
			current_minimum = s1.top().second;
		else
			current_minimum = min (s1.top().second, s2.top().second);
	return current_minimum;
}

int main()
{
	try {
		setlocale(LC_ALL, "Russian");
		Queue res;
		char instruction;
		int x, result_pop, result_min, k;
		io >> k;
		for (int i = 0; i < k; i++) {
			io >> instruction;
			if (instruction == '+') {
				io >> x;
				res.push(x);
			}
			if (instruction == '-') {
				result_pop = res.pop();
			}
			if (instruction == '?') {
				result_min = res.mini();
				io << result_min << "\n";
			}
		}
	}
	catch (Bad_area) {
		cout << "Ошибочка :(";
	}
}
