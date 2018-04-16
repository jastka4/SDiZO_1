#pragma once

enum Color { RED, BLACK, DOUBLE_BLACK };

class RedBlackTreeNode
{
public:
	int data;
	int color;
	RedBlackTreeNode *left,
					 *right,
					 *parent;

	RedBlackTreeNode(int);
	~RedBlackTreeNode();
	void display(int = 0);
};

