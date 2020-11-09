#pragma once
class Stack
{
	int* elements;
	int length;
	int currentLength;

public:
	Stack() : length(0),currentlength(0),elements(0) {}
	void push(int x);
};

