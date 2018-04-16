#include "AVLTreeNode.h"
#include <iostream>
#include <iomanip>

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
	if (right) right->display(5 + offset);
	std::cout << std::setw(offset) << data << "(" << balance << ")" << std::endl;
	if (left) left->display(5 + offset);
}
