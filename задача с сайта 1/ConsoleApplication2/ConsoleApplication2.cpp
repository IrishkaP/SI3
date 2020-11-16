#include <iostream>
#include "edx-io.hpp"
using namespace std;

class Bad_area
{
};

class Stack
{
	int* elements;
	int length;
	int currentLength;

public:
	Stack() : length(0), currentLength(0), elements(0) {}
	Stack(const Stack& item) {
		elements = new int[item.length];
		length = item.length;
		currentLength = item.currentLength;
		for (int i = 0; i < item.length; i++) {
			elements[i] = item.elements[i];
		}
	}
	~Stack() {
		delete[] elements;
		length = 0;
		currentLength = 0;
	}
	void operator= (const Stack& right) {
		delete[] elements;
		elements = new int[right.length];
		length = right.length;
		currentLength = right.currentLength;
		for (int i = 0; i < right.length; i++) {
			elements[i] = right.elements[i];
		}
	}
	void push(int x);
	int pop();
	bool empty();
};

void Stack::push(int x) {
	if (elements == 0) {
		elements = new int[1];
		elements[0] = x;
		currentLength = 1;
		length = 1;
		return;
	}

	if (currentLength < length) {
		elements[currentLength] = x;
		currentLength++;
		return;
	}

	if (currentLength == length) {
		length = (length + 1)*2;
		int* help = new int[length];
		for (int i = 0; i < currentLength; i++)
			help[i] = elements[i];
		help[currentLength] = x;
		delete[] elements;
		elements = help;
		currentLength++;
		return;
	}
}
int Stack::pop() {
	if (currentLength == 0) { throw Bad_area(); return 0; }
	currentLength--;
	return elements[currentLength];
}
bool Stack::empty() {
	if (currentLength == 0)
		return true;
	return false;
}

int main()
{
	try {
		setlocale(LC_ALL, "Russian");
		Stack res;
		char instruction;
		int x,k, result_pop;
		io >> k;
		for (int i = 0; i < k; i++) {
			io >> instruction;
			if (instruction == '+') {
				io >> x;
				res.push(x);
			}
			if (instruction == '-') {
				result_pop = res.pop();
				io << result_pop << "\n";
			}
		}
	}
	catch (Bad_area) {
		cout << "Ошибочка :(";
	}
}


