#include <iostream>
#include "List.hpp"

int main()
{
	using namespace std;
	List<int> list;
	list.push_back(22);
	list.push_front(4);
	list.push_front(5);
	list.push_front(6);
	list.push_back(2);
	list.push_back(0);
	list.push_back(-3);
	list.print();
	return 0;
}