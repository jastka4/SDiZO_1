#pragma once
class AVLTreeNode
{
public:
	int data;
	AVLTreeNode* left;
	AVLTreeNode* right;
	int balance;

	AVLTreeNode();
	AVLTreeNode(int);
	~AVLTreeNode();

	void display(int = 0);
};

