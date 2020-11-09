#pragma once
class Queue
{
	int* elements;
	int length;
	int currentLength;
	int begin;

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
