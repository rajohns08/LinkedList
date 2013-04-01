#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>											// Include for NULL

template <class T>											// Template class for a linked list that holds just one number per node
class LinkedList
{
private:
	struct ListNode											// The structure for each node. Each node holds just one number, and the pointer to next node
	{
		T value;
		ListNode *next;
	};

	ListNode *head;											// The head of the list

public:
	LinkedList()
		{ head = NULL; }									// Initialize the head to NULL when the object is created

	void appendNode(T val);									// Appending a value to the end of the list
	void insertNode(T val);									// Inserting a value into the list
	void deleteNode(T val);									// Deleting a node based on what value the node holds
	void displayList() const;								// Display the entire list

	~LinkedList();											// Destroy the list
};

#endif 
