#include "stdafx.h"
#include <iostream>
#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
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

	firstNode = lastNode = NULL;
}

void DoublyLinkedList::insertAtBeggining(int data)
{
	DoublyLinkedNode* node = new DoublyLinkedNode(data);
	if (firstNode == NULL)
	{
		firstNode = node;
		lastNode = node;
		node->next = NULL;
		node->previous = NULL;	}
	else
		insertBefore(firstNode, data);
}

void DoublyLinkedList::insertAtEnd(int data)
{
	if (lastNode == NULL)
		insertAtBeggining(data);
	else
		insertAfter(lastNode, data);
}	

void DoublyLinkedList::insertBefore(DoublyLinkedNode *node, int data)
{
	DoublyLinkedNode* newNode = new DoublyLinkedNode(data);
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

void DoublyLinkedList::insertBefore(int nextData, int data)
{
	DoublyLinkedNode* node = find(nextData);
	insertBefore(node, data);
}

void DoublyLinkedList::insertAfter(DoublyLinkedNode *node, int data)
{
	DoublyLinkedNode* newNode = new DoublyLinkedNode(data);
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

void DoublyLinkedList::insertAfter(int previousData, int data)
{
	DoublyLinkedNode* node = find(previousData);
	insertAfter(node, data);
}


void DoublyLinkedList::remove(int data)
{
	if (firstNode != NULL)
	{
		DoublyLinkedNode* node = find(data);

		if (node->previous == NULL)
		firstNode = node->next;
		else
		node->previous->next = node->next;

		if (node->next == NULL)
		lastNode = node->previous;
		else
		node->next->previous = node->previous;
	}
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

DoublyLinkedNode* DoublyLinkedList::find(int data)
{
	DoublyLinkedNode *currentNode = firstNode;
	while (currentNode != NULL)
	{
		if (currentNode->data == data)
			return currentNode;
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
		std::cout << "(Node: " << index++ << " Value: " << currentNode->data << ")";
		if (currentNode != lastNode)
			std::cout << " <-> ";
		currentNode = currentNode->next;
	}
	std::cout << std::endl;
}
