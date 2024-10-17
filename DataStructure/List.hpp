#pragma once
#include "Node.hpp"

template<typename Type>
class List
{
private:
	Node<Type>* head;
	Node<Type>* tail;
	int count;
public:
	// default constructor
	Node<Type>* front() const;
	Node<Type>* back() const;
	bool push_front(const Type&);
	bool push_back(const Type&);
	Type pop_front();
	Type pop_back();
};