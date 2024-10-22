#pragma once
#include <cassert>

template <typename Type>
class Queue
{
private:
	int queue_size;
	int ifront;
	int iback;
	int array_capacity;
	Type* array;
public:
	Queue(int = 10);
	~Queue();
	bool empty() const;
	Type front() const;
	void push(Type const&);
	Type pop();
};

// constructor

template <typename Type>
Queue<Type>::Queue(int n)
	: queue_size(0), iback(-1), ifront(0), array_capacity(std::max(1, n)), array(new Type[array_capacity]) {}

template <typename Type>
Queue<Type>::~Queue()
{
	delete[] array;
}

template <typename Type>
bool Queue<Type>::empty() const
{
	return queue_size == 0;
}

template <typename Type>
Type Queue<Type>::front() const
{
	assert(!empty());
	return array[ifront];
}

template <typename Type>
void Queue<Type>::push(Type const& obj)
{
	assert(queue_size != array_capacity);
	++iback;
	if (iback == array_capacity)
		iback = 0;
	array[iback] = obj;
	++queue_size;
}

template <typename Type>
Type Queue<Type>::pop()
{
	assert(!empty());
	--queue_size;
	++ifront;
	if (ifront == array_capacity)
	{
		ifront = 0;
		return array[array_capacity - 1];
	}
	return array[ifront - 1];
}