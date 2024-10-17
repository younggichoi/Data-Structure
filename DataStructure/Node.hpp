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
	Node* next() const;
};