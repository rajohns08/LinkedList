#include "LinkedList.h"
#include "LinkedList.cpp"
#include <iostream>

using namespace std;

int main()
{
	LinkedList<int> llobj;
	llobj.appendNode(2);
	llobj.appendNode(5);
	llobj.appendNode(9);
	llobj.displayList();
	cout << endl << endl;

	llobj.insertNode(1);
	llobj.displayList();
	cout << endl << endl;

	llobj.deleteNode(11);
	llobj.displayList();
	cout << endl << endl;

	llobj.~LinkedList();
	llobj.displayList();

	cin.get();
	return 0;
}