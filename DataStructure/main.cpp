#include <iostream>
#include "Stack_array.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	using namespace std;
	srand(time(0));
	Stack<int> stack(1000);
	int temp;
	for (int i = 0; i < 1000; i++)
	{
		temp = rand();
		stack.push(temp);
		assert(temp == stack.top());
	}
	for (int i = 0; i < 1000; i++)
	{
		temp = stack.top();
		assert(temp == stack.pop());
	}
	cout << "All test pass!" << endl;
	return 0;
}