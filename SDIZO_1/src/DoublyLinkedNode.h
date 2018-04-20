#pragma once

class DoublyLinkedNode
{
public:
	int data;
	DoublyLinkedNode *previous, *next;
	DoublyLinkedNode(int);
	~DoublyLinkedNode();
};
