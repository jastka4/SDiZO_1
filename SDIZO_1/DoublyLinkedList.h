#pragma once
#include "DoublyLinkedNode.h"

class DoublyLinkedList
{
	int size;
	DoublyLinkedNode *firstNode,
					 *lastNode;

public:
	DoublyLinkedList();
	~DoublyLinkedList();

	void insertAtBeggining(DoublyLinkedNode*);
	void insertAtEnd(DoublyLinkedNode*);
	void insertBefore(DoublyLinkedNode*, DoublyLinkedNode*);
	void insertAfter(DoublyLinkedNode*, DoublyLinkedNode*);
	void remove(DoublyLinkedNode*);
	void removeAtBeggining();
	void removeAtEnd();
	DoublyLinkedNode* find(DoublyLinkedNode*);
	void display();
};

