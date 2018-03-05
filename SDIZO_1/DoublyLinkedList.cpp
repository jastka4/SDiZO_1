#include "stdafx.h"
#include <iostream>
#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
	size = 0;
	firstNode = lastNode = NULL;
}

DoublyLinkedList::~DoublyLinkedList()
{
	DoublyLinkedNode *currentNode;

	while (firstNode)
	{
		currentNode = firstNode->next;
		delete currentNode;
		firstNode = currentNode;
	}

	size = 0;
}

void DoublyLinkedList::insertAtBeggining(DoublyLinkedNode *node)
{
	if (firstNode == NULL)
	{
		firstNode = node;
		lastNode = node;
		node->next = NULL;
		node->previous = NULL;
	}
	else
		insertBefore(firstNode, node);
}

void DoublyLinkedList::insertAtEnd(DoublyLinkedNode *node)
{
	if (lastNode == NULL)
		insertAtBeggining(node);
	else
		insertAfter(lastNode, node);
}	

void DoublyLinkedList::insertBefore(DoublyLinkedNode *node, DoublyLinkedNode *newNode)
{
	newNode->next = node;
	if (node->previous == NULL)
		firstNode = newNode;
	else
	{
		newNode->previous = node->previous;
		node->previous->next = newNode;
	}
	node->previous = newNode;
}

void DoublyLinkedList::insertAfter(DoublyLinkedNode *node, DoublyLinkedNode *newNode)
{
	newNode->previous = node;
	if (node->next == NULL)
		lastNode = newNode;
	else
	{
		newNode->next = node->next;
		node->next->previous = newNode;
	}
	node->next = newNode;
}

void DoublyLinkedList::remove(DoublyLinkedNode *node)
{
	if (node->previous == NULL)
		firstNode = node->next;
	else
		node->previous->next = node->next;

	if (node->next == NULL)
		lastNode = node->previous;
	else
		node->next->previous = node->previous;
}

void DoublyLinkedList::removeAtBeggining()
{
	firstNode->next->previous = NULL;
	firstNode = firstNode->next;
}

void DoublyLinkedList::removeAtEnd()
{
	lastNode->previous->next = NULL;
	lastNode = lastNode->previous;
}

DoublyLinkedNode* DoublyLinkedList::find(DoublyLinkedNode *node)
{
	DoublyLinkedNode *currentNode = firstNode;
	while (currentNode != NULL)
	{
		if (currentNode == node)
			return node;
		else currentNode = currentNode->next;
	}

	return NULL;
}

void DoublyLinkedList::display()
{
	DoublyLinkedNode *currentNode = firstNode;
	int index = 0;

	while (currentNode != NULL)
	{
		std::cout << index++ << ". " << currentNode->data << std::endl;
		currentNode = currentNode->next;
	}
}
