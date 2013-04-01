#include "LinkedList.h"
#include <iostream>

using namespace std;

template <class T>
void LinkedList<T>::appendNode(T val)											// Append a node to the end of the list
{
	ListNode *newNode = new ListNode;											// Allocate memory for the new node
	ListNode *nodePtr;															// Create a nodePtr for traversing the list

	newNode->value = val;														// Set the newNode's value and next pointer
	newNode->next = NULL;														// Points to NULL because this node will be at the end of the list

	if (head == NULL)															// If there are no elements in the list, make the newNode the first element
	{
		head = newNode;
	}
	else
	{
		nodePtr = head;															// Set nodePtr to head to start traversing from the beginning

		while (nodePtr->next)													// While there is another node in the list, increment nodePtr 
		{
			nodePtr = nodePtr->next;											
		}

		nodePtr->next = newNode;												// Once there is not another node in the list, update the last node's next pointer to point to the new node
	}
}

template <class T>
void LinkedList<T>::insertNode(T val)											// Insert a node into the list already in sorted order
{
	ListNode *newNode = new ListNode;											// Allocate memory for the new node
	ListNode *nodePtr = head;													// nodePtr is use for traversing, so initialize at beginning of list
	ListNode *previousNode = NULL;												// Need a previousNode value to keep next pointers situated correctly

	newNode->value = val;														// Store val in the new node's value

	if (head == NULL)															// If the list is currently empty, make the new node the first node
	{
		head = newNode;
		newNode->next = NULL;
	}
	else
	{
		while ( (nodePtr != NULL) && (nodePtr->value < val) )					// Cycle through until you reach the end or you reach a node with a greater value than the one you are inserting
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (val < head->value)													// If you need to insert the node into the first position
		{
			head = newNode;														// Make head the new node
			newNode->next = nodePtr;											// Make the new node's next pointer point to the old head
		}
		else
		{
			previousNode->next = newNode;										// If you are inserting somewhere besides the first spot, you need to make the 
			newNode->next = nodePtr;											// previous node point to the new node, and the new node point to the next node
		}

	}
}

template <class T>
void LinkedList<T>::deleteNode(T val)											// Delete a node from the list
{
	ListNode *nodePtr = head;													// nodePtr used to traverse the list. Initialize to the first element.
	ListNode *previousNode = NULL;												// Need to keep track of previous node to keep next pointers in order

	if (head == NULL)															// If the list is empty, you can't delete anything
	{
		cout << "This list is already empty" << endl;
	}

	else 
	{
		while ( (nodePtr != NULL) && (nodePtr->value != val) )					// Cycle through the list until you reach the end or you discover the correct value to delete
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		if (previousNode == NULL)												// If you are deleting the first value in the list (the head), save head's
		{																		// next pointer before you delete head. Then update head.
			nodePtr = head->next;
			delete head;
			head = nodePtr;
		}
		else if (nodePtr != NULL)												// Make sure you actually found a value before trying to delete, since the loop could stop as a result of reaching the end of the list instead of finding the correct value
		{
			previousNode->next = nodePtr->next;									// The previous node's next pointer will need to skip over the current node we are about to delete
			delete nodePtr;														// Delete the node as requested
		}
		else
		{
			cout << "That value does not exist in the list" << endl;			// If you exited the while loop becuase you reached the end of the list and the value wasn't found
		}
	}
}

template <class T>
void LinkedList<T>::displayList() const											// Display the entire list
{
	ListNode *nodePtr = head;													// Used for traversing the list, so initialize to first value in the list

	if (head == NULL)															// If there are no elements to display, tell the user
	{
		cout << "This list is empty" << endl;
	}
	while (nodePtr != NULL)														// Cycle through the list, displaying every value
	{
		cout << nodePtr->value << endl;
		nodePtr = nodePtr->next;
	}
}

template <class T>
LinkedList<T>::~LinkedList()													// Destroy the linked list
{
	ListNode *nodePtr = head;													// Used for traversing the list, so initialize to the first value
	ListNode *nextNode;															// We need to store the informtion of the next node so we can delete the current node and keep moving

	if (head == NULL)															// If the list is already empty
	{
		cout << "The list is already empty" << endl;
	}
	else
	{
		while (nodePtr != NULL)													// Traverse through the list until you reach the end
		{
			nextNode = nodePtr->next;											// Store the next node's value in nextNode
			delete nodePtr;														// Delete the current node
			nodePtr = nextNode;													// Increment nodePtr
		}
	}
}