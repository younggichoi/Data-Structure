#pragma once
#include "Node.hpp"
#include <cassert>
#include <iostream>

template<typename Type>
class List
{
private:
	Node<Type>* head;
	Node<Type>* tail;
	int count;
public:
	// default constructor
	~List();
	bool empty() const;
	Node<Type>* front() const;
	Node<Type>* back() const;
	bool push_front(const Type&);
	bool push_back(const Type&);
	Type pop_front();
	Type pop_back();
	void print() const;
};

// member function

template <typename Type>
List<Type>::~List()
{
	Node<Type>* temp_ptr;
	for (int i = 0; i < count; i++)
	{
		temp_ptr = head;
		head = head->next();
		delete temp_ptr;
	}
}

template <typename Type>
bool List<Type>::empty() const
{
	return count == 0;
}

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
	head = new Node<Type>(t, head);
	count++;
	if (tail == nullptr)
		tail = head;
	return true;
}

template <typename Type>
bool List<Type>::push_back(const Type& t)
{
	if (tail == nullptr)
	{
		tail = new Node<Type>(t);
		head = tail;
	}
	else
	{
		Node<Type>* temp_ptr = new Node<Type>(t);
		tail->next() = temp_ptr;
		tail = tail->next();
	}
	count++;
	return true;
}

template <typename Type>
Type List<Type>::pop_front()
{
	assert(empty());
	Type temp = head->value();
	Node<Type>* temp_ptr = head->next();
	delete head;
	head = temp_ptr;
	count--;
	return temp;
}

template <typename Type>
Type List<Type>::pop_back()
{
	assert(empty());
	Type temp = tail->value();
	Node<Type>* temp_ptr = head;
	while (temp_ptr->next() != tail)
		temp_ptr = temp_ptr->next();
	tail = temp_ptr;
	delete tail->next();
	tail->next() = nullptr;
	count--;
	return temp;
}

template <typename Type>
void List<Type>::print() const
{
	Node<Type>* temp_ptr = head;
	while (temp_ptr)
	{
		std::cout << temp_ptr->value() << " --> ";
		temp_ptr = temp_ptr->next();
	}
}