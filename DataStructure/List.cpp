#include "List.hpp"

template <typename Type>
Node<Type>* List<Type>::front() const
{
	return head;
}

template <typename Type>
Node<Type>* List<Type>::back() const
{
	return tail;
}

template <typename Type>
bool List<Type>::push_front(const Type& t)
{
	head = new Node<type>(t, head);
	count++;
	return true;
}

template <typename Type>
bool List<Type>::push_back(const Type& t)
{
	tail->next_node = new Node<Type>(t);
	tail = tail->next();
	count++;
	return true;
}

// pop_front ...

// pop_back ...