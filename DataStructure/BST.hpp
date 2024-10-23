#pragma once
#include <cassert>

// BinaryNode structure

template <typename T>
struct BinaryNode
{
	T value;
	BinaryNode* left;
	BinaryNode* right;

	BinaryNode<T>(const T& value, BinaryNode<T>* left, BinaryNode<T>* right)
		: value(value), left(left), right(right) {}

	BinaryNode<T>(T &&value, BinaryNode<T>* left, BinaryNode<T>* right)
		: value{std::move(value)}, left(left), right(right) {}
};

// BST class

template <typename T>
class BST
{
private:
	BinaryNode<T>* root;
public:
	BST() : root(nullptr) {}

	const T& findMin() const;
	const T& findMax() const;

	bool find(const T& x) const;
	void insert(const T& x);
	void remove(const T& x);
};

// BST member functons

template <typename T>
const T& BST<T>::findMin() const
{
	assert(root);
	return findMin(root)->value;
}

template <typename T>
BinaryNode<T>* findMin(BinaryNode<T>* t)
{
	if (t == nullptr)
		return nullptr;
	if (t->left == nullptr)
		return t;
	return findMin(t->left);
}

template <typename T>
const T& BST<T>::findMax() const
{
	assert(root);
	return findMax(root)->value;
}

template <typename T>
BinaryNode<T>* findMax(BinaryNode<T>* t)
{
	if (t != nullptr)
		while (t->right != nullptr)
			t = t->right;
	return t;
}

template <typename T>
bool BST<T>::find(const T& x) const
{
	return find(x, root);
}

template <typename T>
bool find(const T& x, BinaryNode<T>* t)
{
	if (t == nullptr)
		return false;
	else if (x < t->value)
		return find(x, t->left);
	else if (t->value < x)
		return find(x, t->right);
	else
		return true;
}

template <typename T>
void BST<T>::insert(const T& x)
{
	insert(x, root);
}

template <typename T>
void insert(const T& x, BinaryNode<T>*& t)
{
	if (t == nullptr)
		t = new BinaryNode<T>(x, nullptr, nullptr);
	else if (x < t->value)
		insert(x, t->left);
	else if (t->value < x)
		insert(x, t->right);
	else
		assert(false);
}

template <typename T>
void BST<T>::remove(const T& x)
{
	remove(x, root);
}

template <typename T>
void remove(const T& x, BinaryNode<T>*& t)
{
	if (t == nullptr)
		return;
	if (x < t->value)
		remove(x, t->left);
	else if (t->value < x)
		remove(x, t->right);
	else
	{
		assert(x == t->value);
		if (t->left == nullptr && t->right == nullptr)
			delete t;
		else if (t->left != nullptr && t->right != nullptr)
		{
			t->value = findMin(t->right)->value;
			remove(t->value, t->right);
		}
		else
		{
			BinaryNode<T>* child;
			if (t->left != nullptr)
				child = t->left;
			else
			{
				assert(t->right != nullptr);
				child = t->right;
			}
			t->value = child->value;
			t->left = child->left;
			t->right = child->right;
			delete child;
		}
	}
}