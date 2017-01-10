#pragma once

class List
{
private:
	struct Node
	{
		int data;
		Node *next;
		Node(int a_data) : data(a_data), next(nullptr) {}
	};

	Node *head;

public:
	List() : head(nullptr) {}
	~List();

	void add_back(int data)
	{
		Node *t = head;
		while (t->next)
		{
			t = head->next;
		}
		t->next = new Node(data);
	}
};