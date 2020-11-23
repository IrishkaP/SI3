#include <iostream>
#include "edx-io.hpp"
using namespace std;

class Bad_area
{
};

class Queue
{
	struct Item {
		int data;
		Item* next;
	};
	Item* head = nullptr;
	Item* end = nullptr;

public:
	void push(int value) {
		Item* node = new Item;
		node->data = value;
		node->next = nullptr;
		if (head == nullptr) 
			head = node;
		else
		{
			Item* p = end;
			p->next = node;
		}
		end = node;
	}

	int pop() {
		if (head == nullptr)
			throw Bad_area();
		Item* del = head;
		head = head->next;
		return del->data;
	}
};



int main()
{
	try {
		setlocale(LC_ALL, "Russian");
		int m, n, e;
		char operation;
		io >> m;
		Queue ex;
		for (int i = 0; i < m; i++) {
			io >> operation;
			if (operation == '+') {
				io >> n;
				ex.push(n);
			}
			if (operation == '-') {
				e = ex.pop();
				io << e << "\n";
			}
		}
	}
	catch (Bad_area) {
		cout << "Ошибочка (;_;)";
	}
}

