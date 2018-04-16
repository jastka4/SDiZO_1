#pragma once
#include "AVLTreeNode.h"

class AVLTree
{
	AVLTreeNode *root;

	void preorderBST(AVLTreeNode*);
	void inorderBST(AVLTreeNode*);
	void postorderBST(AVLTreeNode*);
	void deleteNode(AVLTreeNode*&);
	void rotateRight(AVLTreeNode*&);
	void rotateLeft(AVLTreeNode*&);
	bool incrementBalance(AVLTreeNode*&);
	bool decrementBalance(AVLTreeNode*&);
	bool insertValue(int, AVLTreeNode*&);
	bool removeValue(int, AVLTreeNode*&);
	int getMax(AVLTreeNode*);
	int getMin(AVLTreeNode*);
public:
	AVLTree();
	~AVLTree();

	void insertValue(int);
	void removeValue(int);
	AVLTreeNode* findValue(int);
	void preorder();
	void inorder();
	void postorder();
	void displayTree();
};
