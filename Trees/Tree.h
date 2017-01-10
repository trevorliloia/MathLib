#pragma once

class Tree
{
private:
	struct Node
	{
		int data;
		Node *left, *right;
		Node(int v) : data(v), left(nullptr), right(nullptr) {}
	};
	Node *root;

public:
	Tree() : root(nullptr) {}
	~Tree();

	bool isEmpty();
	bool find(int val, Node *a_root);
	bool find(int val);
	bool insert(int val, Node *a_root);
	bool insert(int val);
	bool remove(int val);
	bool findR(int val) const;
	bool _findR(const Node *n, int val) const;
	int _childCount(const Node *) const;
};