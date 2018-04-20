#include "DoublyLinkedNode.h"
#include <iostream>

DoublyLinkedNode::DoublyLinkedNode(int _data)
{
	data = _data;
	next = previous = nullptr;
}

DoublyLinkedNode::~DoublyLinkedNode()
{
	next = previous = nullptr;
	data = 0;
}
