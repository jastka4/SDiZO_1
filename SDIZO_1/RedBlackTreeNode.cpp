#include "stdafx.h"
#include "RedBlackTreeNode.h"


RedBlackTreeNode::RedBlackTreeNode(int _data)
{
	data = _data;
	color = RED;
	left = right = parent = nullptr;
}


RedBlackTreeNode::~RedBlackTreeNode()
{
	data = 0;
	color = 0;
	left = right = parent = nullptr;
}