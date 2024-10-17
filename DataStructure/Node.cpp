#include "Node.hpp"

template <typename Type>
Node<Type>::Node(const Type& t, Node* n)
	: node_value(t), next_node(n) {}

template<typename Type>
Type Node<Type>::value() const
{
	return node_value;
}

template <typename Type>
Node<Type>* Node<Type>::next() const
{
	return next_node;
}