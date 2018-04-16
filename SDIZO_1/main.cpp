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

	//RedBlackTree
	/*
	RedBlackTree *tree = new RedBlackTree();
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
	tree->deleteValue(8);
	tree->preorder();
	if (tree->findValue(14) == nullptr)
		cout << "empty" << endl;
	*/

	//AVLTree
	AVLTree *tree = new AVLTree();
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
	
    return 0;
}
