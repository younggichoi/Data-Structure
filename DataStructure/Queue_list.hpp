#pragma once
#include "List.hpp"
#include <cassert>

template <typename Type>
class Queue
{
private:
	List<Type> list;
public:
	bool empty() const;
	Type front() const;
	void push(Type const&);
	Type pop();
};

// member function

template <typename Type>
bool Queue<Type>::empty() const
{
	return list.empty();
}

template <typename Type>
Type Queue<Type>::front() const
{
	assert(!empty());
	return list.front();
}

template <typename Type>
void Queue<Type>::push(Type const& obj)
{
	list.push_back(obj);
}

template <typename Type>
Type Queue<Type>::pop()
{
	assert(!empty());
	return list.pop_front();
}
