#include "List.hpp"

template <typename Type>
class Stack
{
private:
	List<Type> list;
public:
	// default constructor
	bool empty() const;
	Type top() const;
	void push(Type const&);
	Type pop();
};

template <typename Type>
bool Stack<Type>::empty() const
{
	return list.empty();
}

template <typename Type>
Type Stack<Type>::top() const
{
	return list.front()->value();
}

template <typename Type>
void Stack<Type>::push(Type const& t)
{
	list.push_front(t);
}

template <typename Type>
Type Stack<Type>::pop()
{
	return list.pop_front();
}