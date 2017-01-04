#pragma once

template<typename T>
class LinkedList
{
private:
	struct Node
	{
		T data;
		Node *prev, *next;
		Node() : prev(nullptr), next(nullptr) {}
	};
	Node *head, *tail;
	size_t count;
public:

	T &front() { return head->data; }
	T &back() { return tail->data; }

	const T &front() const { return head->data; }
	const T &back() const { return tail->data; }

	void add_front(const T &val)
	{
		auto t = new Node;
		t->data = val;

		if (count == 0)
		{
			head = tail = t;
		}
		else
		{
			t->next = head;
			head->prev = t;
			head = t;
		}
	}
	void add_back(const T &val);

	T del_front();
	T del_back();

	void clear() {};
	bool empty() const { return count == 0; }
	size_t size() const { return count; }
	LinkedList() : head(nullptr), tail(nullptr), count(0) {}
	~LinkedList() { clear(); }

	void DEBUG_TEMP_PRINT()
	{
		for (auto ptr = head; ptr != nullptr; ptr = ptr->next)
		{
			cout << ptr->data << " ";
		}
		cout << endl;
	}
};