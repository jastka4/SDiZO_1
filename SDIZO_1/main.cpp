// SDIZO_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DoublyLinkedList.h"
#include "Array.h"
#include "MaxHeap.h"

int main()
{
	//Doubly linked list
	/*
	DoublyLinkedList* list = new DoublyLinkedList();
	list->insertAtBeggining(5);
	list->insertAtBeggining(19);
	list->insertAfter(19, 10);
	list->insertBefore(10, 3);
	list->display();
	list->removeAtBeggining();
	list->display();
	*/

	//Array
	/*
	Array *array = new Array();
	array->insertAtBeggining(5);
	array->insertAtBeggining(19);
	array->insertAt(2, 10);
	array->insertAt(5, 3);
	array->display();
	array->removeAtBeggining();
	array->display();
	*/

	//MaxHeap
	/*
	MaxHeap *heap = new MaxHeap();
	heap->insertKey(100);
	heap->insertKey(19);
	heap->insertKey(36);
	heap->insertKey(1);
	heap->insertKey(25);
	heap->insertKey(17);
	heap->insertKey(3);
	heap->insertKey(7);
	heap->insertKey(2);
	heap->find(5);
	heap->display();
	heap->deleteKey(21);
	heap->extractMax();
	heap->display();
	*/
	
    return 0;
}

