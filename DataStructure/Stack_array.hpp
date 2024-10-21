#pragma once

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