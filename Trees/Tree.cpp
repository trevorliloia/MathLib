#include "Tree.h"
#include <iostream>
using namespace std;

Tree::~Tree()
{
	root = nullptr;
}

bool Tree::isEmpty()
{
	
	return false;
}

bool Tree::find(int val, Node *a_root)
{
	if (a_root->data == val)
	{
		cout << "Found " << val << endl;
		return true;
	}
	else if (a_root->right != nullptr && val > a_root->data)
	{
		return find(val, a_root->right);
	}
	else if (a_root->left != nullptr &&val < a_root->data)
	{
		return find(val, a_root->left);
	}
	else
	return false;
}

bool Tree::find(int val)
{
	Node *t = root;
	while (t != nullptr)
	{
		if (val == t->data)
			return true;

		if (val < t->data)
			t = t->left;

		else t = t->right;
	}
	return false;
	//return find(val, root);
}

bool Tree::insert(int val, Node *a_root)
{
	if (root == nullptr)
	{
		root = new Node(val);
		root->data = val;
		return true;
	}

	Node *tmp = a_root;
	if (tmp == nullptr)
	{
		tmp = new Node(val);
		tmp->data = val;
	}
	else if (val >= tmp->data)
	{
		insert(val, tmp->right);
	}
	else
	{
		insert(val, tmp->left);
	}

	return tmp;
}

bool Tree::insert(int val)
{
	if (find(val)) return false;

	if (root == nullptr)
	{
		root = new Node(val);
		return true;
	}

	Node *t = root;
	while (true)
	{
		if (val == t->data)
		{
			return false;
		}

		if (val < t->data)
		{
			if (t->left == nullptr)
			{
				t->left = new Node(val);
				return true;
			}
			t = t->left;
		}
		else
		{
			if (t->right == nullptr)
			{
				t->right = new Node(val);
				return true;
			}
			t = t->right;
		}
	}
	//return insert(val, root);
}

bool Tree::remove(int val)
{
	if (root != nullptr && root->data == val && root->left == nullptr && root->right == nullptr)
	{
		delete root;
		root = nullptr;
		return true;
	}
	Node *t = root;
	while (true)
	{
		if (t == nullptr)
		{
			return false;
		}
		if (t->data == val)
		{
			Node *ts, *tt;
			Node *ts = t->right;
			if (ts->left == nullptr)
			{
				ts = t;
				tt = t->right;
			}
			else
			{
				while (ts->left->left != nullptr)
				{
					ts = ts->left;
				}
				tt = ts->left;
			}
			t->data = tt->data;
			ts->left = tt->right;
			delete tt;
		}
		if (t->left != nullptr && t->left->data == val)
		{
			Node *tt = t->left;
			t->left = t->left->left != nullptr ? t->left->left : t->left->right;
			delete tt;
			return true;
		}
		if (t->right != nullptr && t->right->data == val)
		{
			Node *tt = t->right;
			t->right = t->right->right != nullptr ? t->right->right : t->right->left;
			delete tt;
			return true;
		}
		t = val < t->data ? t->left : t->right;
	}


	/*if (t->left == nullptr && t->right == nullptr)
	{
		t = nullptr;
	}
	else if (t->left == nullptr || t->right == nullptr)
	{
		if (t->left == nullptr)
		{
			t = t->right;
		}
		else if(t->right == nullptr)
		{
			t = t->left;
		}
	}

	return false;*/
}

bool Tree::findR(int val) const
{
	if (root != nullptr)
		return _findR(root->left, val) || _findR(root->right, val);
	return false;
}

bool Tree::_findR(const Node * n, int val) const
{
	if (n == nullptr) return false;
	else if (n->data == val) return true;

	return _findR(n->left, val) || _findR(n->right, val);
}

int Tree::_childCount(const Node *n) const
{
	int retval = 0;
	if (n->left) retval++;
	if (n->right) retval++;
	return retval;
}
