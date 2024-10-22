#include <iostream>
#include "Abstract_Tree.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	using namespace std;

	int const n = 20;
	int parent_array[n] = { 0,0,0,0,0,2,2,2,3,3,4,4,4,4,5,5,10,12,12,15 };

	AbstractTree<int>* root_node = nullptr;
	AbstractTree<int>** array = new AbstractTree<int>*[n];

	for (int i = 0; i < n; ++i)
		array[i] = new AbstractTree<int>(i);

	for (int i = 0; i < n; i++)
	{
		if (parent_array[i] == i)
			root_node = array[i];
		else
			array[parent_array[i]]->attach_subtree(array[i]);
	}

	print_dfs_tree(root_node);

	return 0;
}