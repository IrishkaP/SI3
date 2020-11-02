#include "Queue.h"
#include "Bad_area.h"
#include <iostream>
using namespace std;

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
}
int Queue::pop() {
	if (currentLength == 0) throw Bad_area(); 
	begin++;
	return elements[begin-1];
}
int Queue::min() {
	 if (currentLength == 0) throw Bad_area();
	int min = elements[begin];
	for (int i = begin+1; i < currentLength; i++)
		if (elements[i] < min)
			min = elements[i];
	return min;
}