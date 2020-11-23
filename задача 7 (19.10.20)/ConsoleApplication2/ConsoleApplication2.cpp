#include <iostream>
#include "edx-io.hpp"
using namespace std;

class Bad_area
{
};

class Queue
{
	int* elements;
	int length;
	int currentLength;
	int begin;
	//stack< pair <int,int> > s1, s2;

public:
	Queue() : length(0), currentLength(0), elements(0) {}
	Queue(const Queue& item) {
		elements = new int[item.length];
		length = item.length;
		currentLength = item.currentLength;
		begin = item.begin;
		for (int i = 0; i < item.length; i++) {
			elements[i] = item.elements[i];
		}
	}
	~Queue() {
		delete[] elements;
		length = 0;
		currentLength = 0;
	}
	void operator= (const Queue& right) {
		delete[] elements;
		elements = new int[right.length];
		length = right.length;
		currentLength = right.currentLength;
		begin = right.begin;
		for (int i = 0; i < right.length; i++) {
			elements[i] = right.elements[i];
		}
	}
	void push(int x);
	int pop();
	int min();
};

void Queue::push(int x) {
	if (elements == 0) {
		elements = new int[1];
		elements[0] = x;
		currentLength = 1;
		length = 1;
		begin = 0;
		return;
	}

	if (currentLength < length) {
		elements[currentLength] = x;
		currentLength++;
		return;
	}

	if (currentLength == length) {
		int* help = new int[length + 1];
		for (int i = 0; i < currentLength; i++)
			help[i] = elements[i];
		help[currentLength] = x;
		delete[] elements;
		elements = help;
		length++;
		currentLength++;
		return;
	}
	/*
	int minima = s1.empty() ? new_element : min (new_element, s1.top().second);
    s1.push (make_pair (new_element, minima));
	*/
}
int Queue::pop() {
	if (currentLength == 0) throw Bad_area();
	begin++;
	return elements[begin - 1];
	/*
	if (s2.empty())
	while (!s1.empty()) {
		int element = s1.top().first;
		s1.pop();
		int minima = s2.empty() ? element : min (element, s2.top().second);
		s2.push (make_pair (element, minima));
	}
    result = s2.top().first;
    s2.pop();
	*/
}
int Queue::min() {
	if (currentLength == 0) throw Bad_area();
	int min = elements[begin];
	for (int i = begin + 1; i < currentLength; i++)
		if (elements[i] < min)
			min = elements[i];
	return min;
	/*
	if (s1.empty() || s2.empty())
	current_minimum = s1.empty ? s2.top().second : s1.top().second;
else
	current_minimum = min (s1.top().second, s2.top().second);
	*/
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
				result_min = res.min();
				io << result_min << "\n";
			}
		}
	}
	catch (Bad_area) {
		cout << "Ошибочка :(";
	}
}
