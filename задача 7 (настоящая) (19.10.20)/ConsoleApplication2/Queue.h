#pragma once
class Queue
{
	int* elements;
	int length;
	int currentLength;
	int begin;

public:
	Queue() : length(0), currentLength(0), elements(0) {}
	void push(int x);
	int pop();
	int min();
};
