#include "stdafx.h"
#include "DoublyLinkedNode.h"

DoublyLinkedNode::DoublyLinkedNode(int _data)
{
	data = _data;
	next = previous = NULL;
}

DoublyLinkedNode::~DoublyLinkedNode()
{
	next = previous = NULL;
	data = 0;
}
