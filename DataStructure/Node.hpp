#pragma once

template <typename Type>
class Node
{
private:
	Type node_value;
	Node* next_node;
public:
	Node(const Type & = Type(), Node* = nullptr);
	Type value() const;
	Node*& next();
};

// member function

template <typename Type>
Node<Type>::Node(const Type& t, Node* n)
	: node_value(t), next_node(n) {}

template<typename Type>
Type Node<Type>::value() const
{
	return node_value;
}

template <typename Type>
Node<Type>*& Node<Type>::next()
{
	return next_node;
}