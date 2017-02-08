#include <iostream>
#include <random>
#include <string>
#include <list>
#include <cassert>
#include <vector>
using namespace std;

template <typename T>
class obpool
{
	const static size_t DEFAULT_POOL_SIZE = 100;

	vector<T> pool;
	vector<bool> poolValidity;
	vector<size_t> nextList;

	size_t openHead, closedHead;
	//search pool validity
	size_t nextEmpty() 
	{
		for (int i = 0; i < DEFAULT_POOL_SIZE; i++)
		{
			if (poolValidity[i] == false)
			{
				return i;
			}
		}
		size_t a_size = pool.size;
		pool.resize(pool.size * 2);
		return a_size;
	}
public:
	obpool()
	{
		pool.resize(DEFAULT_POOL_SIZE);
		poolValidity.resize(DEFAULT_POOL_SIZE);

		memset(&pool[0], 0, sizeof(T) * DEFAULT_POOL_SIZE);
		memset(&poolValidity, 0, sizeof(bool) * DEFAULT_POOL_SIZE);
	}
	~obpool() {}

	class handle
	{
		obpool *pool;
		size_t index;

	public:
		handle() : pool(NULL) {}
		handle(obpool * poolPtr, size_t poolIdx) : pool(poolPtr), index(poolIdx) {}

		//access pool value at index
		T& value() 
		{
			return pool->pool[index];
		}

		//pop
		void free()
		{
			pool->pop(index);
		}

		//verify pool value at index
		bool isValid() const
		{
			return pool->isValid(index);
		}

		//return index
		size_t getIndex() const
		{
			return index;
		}

		// Moves the handle to the next valid element in the pool
		handle &operator++()
		{
			for (int i = index; i < pool->poolValidity.size(); i++)
			{
				if (pool->poolValidity[i])
				{
					index = i;
					return *this;
				}
			}
			index = pool->pool.size();
			return *this;
		}

		// Returns a reference to the object in the object pool
		T& operator*()
		{
			return value();
		}

		// Returns a const reference to the object in the object pool
		const T& operator*() const
		{
			return value();
		}

		// Returns a reference to the object in the object pool
		T& operator->()
		{
			return value();
		}

		// Returns a const reference to the object in the object pool
		const T& operator->() const
		{
			return value();
		}

		// Returns true they're pointing to the same slot.
		// Otherwise, returns false.
		bool operator==(const handle& other)
		{
			return other.pool->pool == pool->pool && other.index == index;
		}
		bool operator==(const handle& other)
		{
			return !(other == *this);
		}

	};

	handle push(const T& cpy)
	{
		size_t idx = nextEmpty();
		assert(idx != -1);

		pool[idx] = cpy;
		poolValidity[idx] = true;

		return handle(this, idx);
	}
	void pop(size_t idx)
	{
		poolValidity[idx] = false;
	}

	bool isValid(size_t idx) const
	{
		return poolValidity[idx];
	}

	T& at(size_t idx)
	{
		return pool[idx];
	}

	const T& at(size_t idx) const
	{
		return pool[idx];
	}

	// Returns a handle referring to the first valid slot.
	handle begin() const
	{
		for (int i = 0; i < poolValidity.size(); i++)
		{
			if (poolValidity[i])
			{
				return handle(this, i);
			}
		}
		//nope
	}

	// Returns a handle referring to the slot at the given index
	handle get(size_t idx) const
	{
		return handle(this, idx);
	}

	// Returns a handle referring to the last valid slot.
	handle end() const
	{
		return handle(this, pool.size());
	}

};






template <class T>
class terryQueue
{
private:
	list<T> data;

public:
	T pop()
	{
		T temp = data.front();
		data.pop_front();
		return temp;
	}

	void push(const T& val)
	{
		data.push_back(val);
	}

	T front()
	{
		return data.front();
	}

	void reserve(size_t size)
	{
		return data.resize(size);
	}

	void compact()
	{
		return data.resize(data.size());
	}

	size_t size()
	{
		return data.size();
	}

	bool empty()
	{
		return data.empty();
	}

	void clear()
	{
		return data.clear();
	}
};




template<class T>
class Queue
{
public:
	class Node
	{
	public:
		T data;
		Node *prev, *next;
		Node() : prev(nullptr), next(nullptr) {}
	};
	Node *head, *tail;
	size_t count;

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

	void del_back()
	{

	}


	Queue() : m_pData(nullptr), m_uiSize(0) {};
	Queue(const Queue& a_rPointer);
	~Queue();

	bool Empty() const;
	unsigned int GetSize()const;

	void Push(T& a_rValue);
	void Pop();
	const T& Top();

private:
	Node* m_pData;
	unsigned int m_uiSize;
};


template <class T> class stack
{
	const static int STSIZE = 32;

	T fill[STSIZE];
	
public:
	void init();
	void push(T val);
	T pop();
	T peek();
	size_t size();
	bool empty();
	void clear();
	void print();


};

//initalize stack
template <class T>
void stack<T>::init()
{
	for (int i = 0; i < STSIZE; i++)
	{
		fill[i] = 0;
	}
}

//fill next value in stack
template <class T>
void stack<T>::push(T val)
{
	for (int i = 0; i < STSIZE; i++)
	{
		if (fill[i] != 0)
		{
			if (i == 0)
			{
				return;
			}
			else
			{
				fill[i - 1] = val;
			}	
			return;
		}
		
	}
	fill[STSIZE - 1] = val;
}

//remove and return top value
template <class T>
T stack<T>::pop()
{
	for (int i = 0; i < STSIZE; i++)
	{
		if (fill[i] != 0)
		{
			int tmp = fill[i];
			fill[i] = 0;
			return tmp;
		}

	}
	return 0;
}


//return top value
template <class T>
T stack<T>::peek()
{
	for (int i = 0; i < STSIZE; i++)
	{
		if (fill[i] != 0)
		{
			return fill[i];
		}

	}
	return 0;
}


//return size of stack
template <class T>
size_t stack<T>::size()
{
	int x = 0;
	for (int i = 0; i < STSIZE; i++)
	{
		if (fill[i] != 0)
		{
			x++;
		}

	}
	return x;
}

//return true for empty stack, false if stack has elements
template <class T>
bool stack<T>::empty()
{
	for (int i = 0; i < STSIZE; i++)
	{
		if (fill[i] != 0)
		{
			return false;
		}

	}
	return true;
}

//!NUKE STACK!
template <class T>
void stack<T>::clear()
{
	for (int i = 0; i < STSIZE; i++)
	{
		fill[i] = 0;
	}
}


//prints stack values to console
template <class T>
void stack<T>::print()
{
	for (int i = 0; i < STSIZE; i++)
	{
		cout << fill[i] << ",";
	}
	cout << endl;
}

int knuth(unsigned int value)
{
	return value * INT_MAX >> (2 ^ 32);
}

class hashtable
{
	const static int TBSIZE = 128;

	class pair
	{
	public:
		int key;
		int value;
		bool set = false;
	};

	pair things[TBSIZE];

	int getIndex(int key) { return knuth(key) % TBSIZE; }

public:
	void set(int key, int value);
	int get(int key);
	int count();
	bool empty();
	void clearAll();
	void clearThis(int key);

	bool isSet(int key);
};

void hashtable::set(int key, int value)
{
	int hash = (knuth(key) % TBSIZE);
	things[hash].value = value;
	things[hash].key = key;
	things[hash].set = true;
	cout << "hash " << things[hash].key << " set to value of " << things[hash].value << endl;

}

int hashtable::get(int key)
{
	int hash = (knuth(key) % TBSIZE);
	cout << "hash " << things[hash].key << " has value of " << things[hash].value << endl;
	return things[hash].value;
}

int hashtable::count()
{
	int countSize = 0;
	for (int i = 0; i < TBSIZE; i++)
	{
		if (things[i].set)
		{
			countSize++;
		}
		
	}
	cout << "table has " << countSize << " set elements" << endl;
	return countSize;
}

bool hashtable::empty()
{
	if (count() > 0)
	{
		cout << "table has elements" << endl;
		return false;
	}
	else
		cout << "table has no elements" << endl;
		return true;
}

void hashtable::clearAll()
{
	for (int i = 0; i < TBSIZE; i++)
	{
		things[i].key = 0;
		things[i].value = 0;
		things[i].set = false;
	}
}

void hashtable::clearThis(int key)
{
	int hash = (knuth(key) % TBSIZE);
	things[hash].key = 0;
	things[hash].value = 0;
	things[hash].set = false;
}

bool hashtable::isSet(int key)
{
	int hash = (knuth(key) % TBSIZE);
	string set;
	if (things[hash].set)
	{
		set = "set";
	}
	else
	{
		set = "not set"; 
	}
		
	cout << "hash " << things[hash].key << " is " << set << endl;
	return things[hash].set;
}



void printData(const int *data, size_t length)
{
	for (int i = 0; i < length; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

void randFill(int *data, size_t length)
{
	for (int i = 0; i < length; i++)
	{
		data[i] = rand() % INT_MAX;
	}
}

void bubbleSort(int *data, size_t length)
{
	int swap = 0;
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length-i-1; ++j)
		{
			int t = data[j];
			data[j] = data[j + 1];
			data[j + 1] = t;
		}
	}
}

void insertionSort(int *data, size_t length)
{
	for (int i = 0; i < length; ++i)
	{
		int j = i;
		while (j > 0 && data[j - 1] > data[j])
		{
			int t = data[j];
			data[j] = data[j + 1];
			data[j + 1] = t;
			--j;
		}
	}
}

void quicksort(int *data, int left, int right)
{
	int i, j;
	i = left;
	j = right;
	int tmp;
	int pivot = data[((left + right) / 2)];

	while (i <= j)
	{
		while (data[i] < pivot)
		{
			i++;
		}
		while (data[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j)
	{
		quicksort(data, left, j);
	}
	if (i < right)
	{
		quicksort(data, i, right);
	}
}

void main()
{
	const int length = 255000;
	int data[length];
	//randFill(data, length);
	//printData(data, length);
	//quicksort(data, 0, length-1);
	//printData(data, length);

	/*hashtable hashT;
	hashT.set(365, 12);
	hashT.get(365);

	hashT.set(1111, 11);
	hashT.get(1111);

	hashT.set(666, 10);
	hashT.get(666);

	hashT.set(9876, 9);
	hashT.get(9876);

	hashT.count();

	hashT.isSet(365);

	hashT.clearThis(365);

	hashT.isSet(365);

	hashT.empty();

	hashT.clearAll();

	hashT.empty();*/

	stack<int> numbers;
	numbers.init();

	numbers.push(1);
	numbers.push(2);
	numbers.push(3);
	numbers.push(4);
	numbers.push(5);
	numbers.push(6);
	numbers.push(7);
	numbers.push(8);
	numbers.push(9);

	numbers.print();

	cout << numbers.peek() << endl;
	cout << numbers.pop() << endl;
	cout << numbers.peek() << endl;

	cout << numbers.size() << endl;

	cout << numbers.empty() << endl;
	numbers.clear();
	cout << numbers.empty() << endl;
	system("pause");
}


