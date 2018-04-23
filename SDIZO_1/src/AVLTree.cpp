#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree()
{
	nil = new AVLTreeNode();
	nil->left = nil;
	nil->right = nil;
	root = nil;
	nil->balance = 0;
}

AVLTree::~AVLTree()
{
	deleteNode(root);
	root = nullptr;
	delete nil;
	nil = nullptr;
}

void AVLTree::insertValue(int data)
{
	insertValue(data, root);
}

void AVLTree::removeValue(int data)
{
	removeValue(data, root);
}

void AVLTree::deleteNode(AVLTreeNode *&node)
{
	if (node == nil)
		return;

	deleteNode(node->left);
	deleteNode(node->right);
	delete node;
	node = nil;
}

void AVLTree::rotateRight(AVLTreeNode *&node)
{
	AVLTreeNode *x = node;
	AVLTreeNode *y = node->left;

	x->left = y->right;
	y->right = x;
	node = y;

	x->balance += 1;
	if (y->balance < 0) x->balance += -y->balance;

	y->balance += 1;
	if (x->balance > 0) y->balance += x->balance;
}

void AVLTree::rotateLeft(AVLTreeNode *&node)
{
	AVLTreeNode *x = node;
	AVLTreeNode *y = node->right;

	x->right = y->left;
	y->left = x;
	node = y;

	x->balance -= 1;
	if (y->balance > 0) x->balance -= y->balance;

	y->balance -= 1;
	if (x->balance < 0) y->balance -= -x->balance;
}

bool AVLTree::incrementBalance(AVLTreeNode *&node)
{
	node->balance++;

	if (node->balance == 0)
		return false;

	if (node->balance == 1)
		return true;

	if (node->balance == 2)
	{
		if (node->right->balance == -1)
			rotateRight(node->right);

		rotateLeft(node);

		return false;
	}

	return true;
}

bool AVLTree::decrementBalance(AVLTreeNode *&node)
{
	node->balance--;

	if (node->balance == 0)
		return false;

	if (node->balance == -1)
		return true;

	if (node->balance == -2)
	{
		if (node->left->balance == 1)
			rotateLeft(node->left);

		rotateRight(node);

		return false;
	}

	return true;
}

bool AVLTree::insertValue(int data, AVLTreeNode *&node)
{
	if(node == nil)
	{
		node = new AVLTreeNode(data);
		node->left = nil;
		node->right = nil;
		return true;
	}
	else if (data > node->data)
	{
		return insertValue(data, node->right) && incrementBalance(node);
	}
	else if (data < node->data)
	{
		return insertValue(data, node->left) && decrementBalance(node);
	}

	return false; // no need to add already existing node
}

int AVLTree::getMin(AVLTreeNode *node)
{
	return node->left == nil ? node->data : getMin(node->left);
}

bool AVLTree::removeValue(int data, AVLTreeNode *&node)
{
	if (node == nil)
		return false;
	else if (node->data < data)
		return removeValue(data, node->right) && decrementBalance(node);
	else if (node->data > data)
		return removeValue(data, node->left) && incrementBalance(node);
	else // if (node->value == item)
	{
		if (node->left == nil && node->right == nil)
			deleteNode(node);
		else if (node->left != nil && node->right != nil)
		{
			// NOTE: "node" is reference to pointer, that can be
			//  changed during new remove. It is necessary to
			//  create another local pointer that cannot be changed
			//  form outside, to point current node.
			AVLTreeNode *currentNode = node;
			int minNodeValue = getMin(node->right);

			bool changedHeight = removeValue(minNodeValue, node);
			currentNode->data = minNodeValue;

			return changedHeight;
		}
		else
		{
			AVLTreeNode *nodeToRemove = node;

			if (node->left == nil)
			{
				node = nodeToRemove->right;
				nodeToRemove->right = nil;
			}
			else
			{
				node = nodeToRemove->left;
				nodeToRemove->left = nil;
			}

			deleteNode(nodeToRemove);
		}

		return true;
	}
}

AVLTreeNode * AVLTree::findValue(int data)
{
	AVLTreeNode* node = root;

	while (node)
	{
		if (node->data > data)
		{
			node = node->left;
		}
		else if (node->data < data)
		{
			node = node->right;
		}
		else
		{
			return node;
		}
	}

	return nullptr;
}

void AVLTree::preorderBST(AVLTreeNode *node)
{
	if (node == nil)
		return;

	std::cout << node->data << std::endl;
	preorderBST(node->left);
	preorderBST(node->right);
}

void AVLTree::inorderBST(AVLTreeNode *node)
{
	if (node == nil)
		return;

	inorderBST(node->left);
	std::cout << node->data << std::endl;
	inorderBST(node->right);
}

void AVLTree::postorderBST(AVLTreeNode *node)
{
	if (node == nil)
		return;

	postorderBST(node->left);
	postorderBST(node->right);
	std::cout << node->data << std::endl;
}

void AVLTree::preorder()
{
	preorderBST(root);
}

void AVLTree::inorder()
{
	AVLTree(root);
}

void AVLTree::postorder()
{
	postorderBST(root);
}

void AVLTree::displayTree()
{
	if (root != nil)
	root->display();
}
