#include <iostream>
#include "Tree.h"
#include <ctime>

using namespace std;

int main()
{

	// binary tree

	Tree<int> tree;
	cout << "Empty:\t" << tree.isEmpty() << endl;
	cout << "Size:\t" << tree.getSize() << endl;
	srand(unsigned(time(0)));
	size_t amount = 9;
	for (size_t i = 0; i < amount; i++)
	{
		int data = rand() % 5;
		cout << "Add node:\t" << data << endl;
		tree.add(data);
	}
	cout << "Empty:\t" << tree.isEmpty() << endl;
	cout << "Size:\t" << tree.getSize() << endl;

	tree.print();


	cout << "Max:\t" << tree.max() << endl;
	cout << "Min:\t" << tree.min() << endl;
	tree.print();


	return 0;
}