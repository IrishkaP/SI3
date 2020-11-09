#include "Stack.h"
#include "Bad_area.h"
#include <iostream>
using namespace std;

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
}
int Stack::pop() {
	if (currentLength == 0) { throw Bad_area(); return 0; }
	currentLength--;
	return elements[currentLength];
}
int Stack::top() {
	if (currentLength == 0) { throw Bad_area(); return 0; }
	return elements[currentLength-1];
}
int Stack::size() {
	return currentLength;
}
void Stack::clear() {
	currentLength = 0;
}
bool Stack::empty() {
	if (currentLength == 0)
		return true;
	return false;
}