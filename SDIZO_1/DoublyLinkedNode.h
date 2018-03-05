#pragma once
class DoublyLinkedNode //implement as a structure?
{
public:
	int data;
	DoublyLinkedNode *previous, *next;
	DoublyLinkedNode(int data);
	~DoublyLinkedNode();
};

