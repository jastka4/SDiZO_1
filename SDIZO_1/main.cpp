// SDIZO_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DoublyLinkedList.h"
#include "Array.h"
#include "MaxHeap.h"
#include "RedBlackTree.h"
#include "AVLTree.h"
#include <iostream>

using namespace std;

int main()		//TODO: Add exceptions, List/Array/Tree cout as std::ostream?
				//Array used in MaxHeap?
{
	//Doubly linked list
	/*
	DoublyLinkedList* list = new DoublyLinkedList();
	list->removeAtBeggining();
	list->insertAtBeggining(5);
	list->insertAtBeggining(19);
	list->insertAfter(19, 10);
	list->insertBefore(10, 3);
	list->display();
	list->removeAtBeggining();
	list->removeAtEnd();
	list->remove(19);
	list->display();
	*/

	//Array
	/*
	Array *array = new Array();
	array->removeAtBeggining();
	array->removeAtEnd();
	array->insertAtBeggining(5);
	array->removeAt(3);
	array->insertAtBeggining(19);
	array->insertAt(2, 10);
	array->insertAt(5, 3);
	array->insertAtEnd(4);
	array->display();
	array->removeAtBeggining();
	array->display();
	*/

	//MaxHeap
	/*
	MaxHeap *heap = new MaxHeap();
	heap->pop();
	heap->remove(10);
	heap->push(100);
	heap->push(19);
	heap->push(36);
	heap->push(1);
	heap->push(25);
	heap->push(17);
	heap->push(3);
	heap->push(7);
	heap->push(2);
	heap->find(5);
	heap->display();
	heap->displayTree();
	heap->remove(21);
	heap->pop();
	heap->display();
	*/

	//RedBlackTree
	/*
	RedBlackTree *tree = new RedBlackTree();
	tree->deleteValue(2);
	tree->insertValue(10);
	tree->insertValue(28);
	tree->insertValue(2);
	tree->insertValue(8);
	tree->insertValue(14);
	tree->insertValue(4);
	tree->insertValue(13);
	tree->insertValue(113);
	tree->insertValue(15);
	tree->insertValue(11);
	tree->insertValue(12);
	tree->preorder();
	tree->inorder();
	tree->postorder();
	tree->deleteValue(8);
	tree->preorder();
	tree->displayTree();
	if (tree->findValue(14) == nullptr)
		cout << "empty" << endl;
	*/

	//AVLTree
	/*
	AVLTree *tree = new AVLTree();
	tree->removeValue(2);
	tree->insertValue(10);
	tree->insertValue(28);
	tree->insertValue(2);
	tree->insertValue(8);
	tree->insertValue(14);
	tree->insertValue(1);
	tree->insertValue(12);
	tree->preorder();
	tree->inorder();
	tree->postorder();
	tree->removeValue(8);
	tree->preorder();
	tree->displayTree();
	if (tree->findValue(11) == nullptr)
		cout << "empty" << endl;
	*/

    return 0;
}
