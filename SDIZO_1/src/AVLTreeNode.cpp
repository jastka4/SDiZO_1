#include "AVLTreeNode.h"
#include <iostream>
#include <iomanip>

AVLTreeNode::AVLTreeNode()
{
}

AVLTreeNode::AVLTreeNode(int _data)
{
	data = _data;
	left = right = nullptr;
	balance = 0;
}

AVLTreeNode::~AVLTreeNode()
{
	data = 0;
	left = right = nullptr;
	balance = 0;
}

void AVLTreeNode::display(int offset)
{
	bool isNil = false;

	if (this == this->left && this->left == this->right)
		isNil = true;

	if (isNil)
		return;

	if (right) right->display(5 + offset);
	std::cout << std::setw(offset) << data << "(" << balance << ")" << std::endl;
	if (left) left->display(5 + offset);
}
