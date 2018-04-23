#include "RedBlackTreeNode.h"
#include <iostream>
#include <iomanip>
#include <windows.h> 

RedBlackTreeNode::RedBlackTreeNode()
{
}

RedBlackTreeNode::RedBlackTreeNode(int _data)
{
	data = _data;
	color = RED;
	left = right = parent = nullptr;
}

RedBlackTreeNode::~RedBlackTreeNode()
{
	color = 0;
	left = right =  parent = nullptr;
}

void RedBlackTreeNode::display(int offset)
{
	bool isNil = false;

	if (this == this->left && this->left == this->right)
		isNil = true;

	if (isNil)
		return;

	if (right) right->display(5 + offset);
	if (color == RED)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << std::setw(offset) << data << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
		std::cout << std::setw(offset) << data << std::endl;

	if (left) left->display(5 + offset);
}