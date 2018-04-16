#include <iostream>
#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
	firstNode = lastNode = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
	DoublyLinkedNode *currentNode;

	while (firstNode)
	{
		currentNode = firstNode->next;
		delete firstNode;
		firstNode = currentNode;
	}

	firstNode = lastNode = nullptr;
}

void DoublyLinkedList::insertAtBeggining(int data)
{
	DoublyLinkedNode* node = new DoublyLinkedNode(data);
	if (firstNode == nullptr)
	{
		firstNode = node;
		lastNode = node;
		node->next = nullptr;
		node->previous = nullptr;	}
	else
		insertBefore(firstNode, data);
}

void DoublyLinkedList::insertAtEnd(int data)
{
	if (lastNode == nullptr)
		insertAtBeggining(data);
	else
		insertAfter(lastNode, data);
}	

void DoublyLinkedList::insertBefore(DoublyLinkedNode *node, int data)
{
	DoublyLinkedNode* newNode = new DoublyLinkedNode(data);
	newNode->next = node;
	if (node->previous == nullptr)
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
	if (node->next == nullptr)
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
	if (firstNode != nullptr)
	{
		DoublyLinkedNode* node = find(data);

		if (node == nullptr)
			std::cout << "Could not find value: " << data << std::endl;
		else
		{
			if (node->previous == nullptr)
				firstNode = node->next;
			else
				node->previous->next = node->next;

			if (node->next == nullptr)
				lastNode = node->previous;
			else
				node->next->previous = node->previous;

			delete node;
		}
	}
}

void DoublyLinkedList::removeAtBeggining()
{
	if (firstNode != nullptr)
	{
		DoublyLinkedNode* currentNode = firstNode;
		firstNode->next->previous = nullptr;
		firstNode = firstNode->next;
		delete currentNode;
	}
}

void DoublyLinkedList::removeAtEnd()
{
	if (firstNode != nullptr)
	{
		DoublyLinkedNode* currentNode = lastNode;
		lastNode->previous->next = nullptr;
		lastNode = lastNode->previous;
		delete currentNode;
	}
}

DoublyLinkedNode* DoublyLinkedList::find(int data)
{
	DoublyLinkedNode *currentNode = firstNode;
	while (currentNode != nullptr)
	{
		if (currentNode->data == data)
			return currentNode;
		else currentNode = currentNode->next;
	}

	return nullptr;
}

void DoublyLinkedList::display()
{
	DoublyLinkedNode *currentNode = firstNode;
	int index = 0;

	while (currentNode != nullptr)
	{
		std::cout << "(Node: " << index++ << " Value: " << currentNode->data << ")";
		if (currentNode != lastNode)
			std::cout << " <-> ";
		currentNode = currentNode->next;
	}
	std::cout << std::endl;
}
