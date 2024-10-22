#include <iostream>
#include "Abstract_Tree.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	using namespace std;
	AbstractTree<char> tree('A');
	AbstractTree<char>* b = tree.attach('B');
	AbstractTree<char>* c = tree.attach('C');
	AbstractTree<char>* d = tree.attach('D');
	AbstractTree<char>* e = b->attach('E');
	AbstractTree<char>* f = b->attach('F');
	AbstractTree<char>* g = d->attach('G');

	print_dfs_tree(&tree);

	return 0;
}