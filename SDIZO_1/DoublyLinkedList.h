#pragma once
#include "DoublyLinkedNode.h"

class DoublyLinkedList
{
	DoublyLinkedNode *firstNode,
		 *lastNode;

	void insertBefore(DoublyLinkedNode*, int);
	void insertAfter(DoublyLinkedNode*, int);
public:
	DoublyLinkedList();
	~DoublyLinkedList();

	void insertBefore(int, int);
	void insertAfter(int, int);
	void insertAtBeggining(int);
	void insertAtEnd(int);
	void remove(int);
	void removeAtBeggining();
	void removeAtEnd();
	DoublyLinkedNode* find(int);
	void display();
};

