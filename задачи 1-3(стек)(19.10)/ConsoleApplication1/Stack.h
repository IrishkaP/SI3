#pragma once
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
	int top();
	int size();
	void clear();
	bool empty();
};