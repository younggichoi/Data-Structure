#pragma once
#include "List.hpp"
#include <iostream>
#include <string>

template <typename Type>
class AbstractTree
{
private:
	Type value;
	AbstractTree* parent;
	List<AbstractTree*> children;
	
public:
	AbstractTree(Type const& = Type(), AbstractTree* = nullptr);

	Type get_value() const;
	AbstractTree<Type>* get_parent() const;
	int get_degree() const;
	bool is_root() const;
	bool is_leaf() const;
	AbstractTree<Type>* get_child(int n) const;
	AbstractTree<Type>* attach(Type const& obj);

	// void attach_subtree(AbstractTree*);
	// void detach_from_parent();

	int size() const;
	int height() const;
};

// constructor

template <typename Type>
AbstractTree<Type>::AbstractTree(Type const& obj, AbstractTree* p)
	: value(obj), parent(p) {}

template <typename Type>
Type AbstractTree<Type>::get_value() const
{
	return value;
}

template <typename Type>
AbstractTree<Type>* AbstractTree<Type>::get_parent() const
{
	return parent;
}

template <typename Type>
bool AbstractTree<Type>::is_root() const
{
	return parent == nullptr;
}

template <typename Type>
int AbstractTree<Type>::get_degree() const
{
	return children.size();
}

template <typename Type>
bool AbstractTree<Type>::is_leaf() const
{
	return get_degree() == 0;
}

template <typename Type>
AbstractTree<Type>* AbstractTree<Type>::get_child(int n) const
{
	if (n < 0 || n >= get_degree())
		return nullptr;
	
	auto it = children.front();
	for (int i = 0; i < n; i++)
		it = it->next();
	return it->value();
}

template <typename Type>
AbstractTree<Type>* AbstractTree<Type>::attach(Type const& obj)
{
	auto child = new AbstractTree(obj, this);
	children.push_back(child);
	return child;
}

template <typename Type>
int AbstractTree<Type>::size() const
{
	int tree_size = 1;
	auto child = children.front();
	while (child->next())
	{
		tree_size += (*child)->size();
		child = child->next();
	}
	return tree_size;
}

template <typename Type>
int AbstractTree<Type>::height() const
{
	int tree_height = 0;
	auto child = child.front();
	while (child->next())
		tree_height = std::max(tree_height, 1 + (*child)->height());
	return tree_height;
}

// DFS function

template <typename Type>
void print_dfs_tree(AbstractTree<Type>* tree, int depth = 0)
{
	std::cout << std::string(depth * 4, ' ') << "<" << tree->get_value() << ">" << std::endl;

	for (int i = 0; i < tree->get_degree(); i++)
	{
		auto ctree = tree->get_child(i);
		print_dfs_tree(ctree, depth + 1);
	}

	std::cout << std::string(depth*4, ' ') << "</" << tree->get_value() << ">" << std::endl;
}