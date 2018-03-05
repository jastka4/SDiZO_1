#include "stdafx.h"
#include "DoublyLinkedNode.h"

DoublyLinkedNode::DoublyLinkedNode(int data)
{
	data = data;
	next = previous = NULL;
}

DoublyLinkedNode::~DoublyLinkedNode()
{
	next = previous = NULL;
	data = 0;
}
