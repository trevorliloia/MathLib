#pragma once
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
	size_t counter;
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
		counter = 0;
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
		bool operator!=(const handle& other)
		{
			return !(other == *this);
		}

	};

	handle push(const T& cpy)
	{
		size_t idx = nextEmpty();
		assert(idx != -1);
		counter++;
		pool[idx] = cpy;
		poolValidity[idx] = true;

		return handle(this, idx);
	}
	void pop(size_t idx)
	{
		poolValidity[idx] = false;
		counter--;
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
		return end();
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