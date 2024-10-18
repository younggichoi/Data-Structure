#include <iostream>
#include "List.hpp"

int main()
{
	using namespace std;
	List<int> list;
	for (int i = 0; i < 10; i++)
		list.push_back(i);
	list.print();
	for (int i = 44; i > 32; i--)
		list.push_front(i);
	list.print();
	cout << list.pop_front() << endl;
	list.print();
	cout << list.pop_back() << endl;
	list.print();
	return 0;
}