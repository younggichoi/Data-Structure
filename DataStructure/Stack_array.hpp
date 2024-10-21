#pragma once
#include <cassert>

template <typename Type>
class Stack
{
private:
	int stack_size;
	int array_capacity;
	Type* array;
public:
	Stack(int = 10);
	~Stack();
	bool empty() const;
	Type top() const;
	void push(Type const&);
	Type pop();
};

// constructor

template <typename Type>
Stack<Type>::Stack(int cap)
	: stack_size(0), array_capacity(cap)
{
	array = new Type[cap];
}

// destructor

template <typename Type>
Stack<Type>::~Stack()
{
	delete[] array;
}

// member functions of Stack

template <typename Type>
bool Stack<Type>::empty() const
{
	return stack_size == 0;
}

template <typename Type>
Type Stack<Type>::top() const
{
	assert(!empty());
	return array[stack_size - 1];
}

template <typename Type>
Type Stack<Type>::pop()
{
	assert(!empty());
	stack_size--;
	return array[stack_size];
}

template <typename Type>
void Stack<Type>::push(Type const& obj)
{
	assert(stack_size != array_capacity);
	array[stack_size] = obj;
	++stack_size;
}