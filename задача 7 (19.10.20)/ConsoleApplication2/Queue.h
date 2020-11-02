#pragma once
#include "Bad_area.h"
class Queue
{
	struct Item {
		int data;
		Item* next;
	};
	Item* head = nullptr;

public:
	void push(int value) {
		Item* node = new Item;
		node->data = value;
		node->next = nullptr;
		if (head == nullptr)
			head = node;
		else
		{
			Item* p = head;
			while (p->next != nullptr)
			{
				p = p->next;
			}
			p->next = node;
		}
	}

	int pop() {
		if (head == nullptr)
			throw Bad_area();
		Item *del = head;
		head = head->next;
		return del->data;
	}
};

