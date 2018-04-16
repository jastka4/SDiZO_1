#include "stdafx.h"
#include "RedBlackTree.h"
#include <iostream>
#include <windows.h> 

RedBlackTree::RedBlackTree()
{
	root = nullptr;
}

RedBlackTree::~RedBlackTree()
{
	deleteNode(root);
	root = nullptr;
}

void RedBlackTree::insertValue(int data)
{
	RedBlackTreeNode *node = new RedBlackTreeNode(data);
	root = insertBST(root, node);
	fixInsertRBTree(node);
}

void RedBlackTree::deleteValue(int data)
{
	RedBlackTreeNode *node = deleteBST(root, data);
	fixDeleteRBTree(node);
}

RedBlackTreeNode * RedBlackTree::findValue(int data)
{
	RedBlackTreeNode* node = root;

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

void RedBlackTree::preorder()
{
	preorderBST(root);
	std::cout << "-------" << std::endl;
}

void RedBlackTree::inorder()
{
	inorderBST(root);
	std::cout << "-------" << std::endl;
}

void RedBlackTree::postorder()
{
	postorderBST(root);
	std::cout << "-------" << std::endl;
}

void RedBlackTree::displayTree()
{
	root->display();
}

void RedBlackTree::deleteNode(RedBlackTreeNode *node)
{
	if (node == nullptr)
		return;
	deleteNode(node->left);
	deleteNode(node->right);
	delete node;
}

void RedBlackTree::rotateLeft(RedBlackTreeNode *node)
{
	RedBlackTreeNode *right_child = node->right;
	node->right = right_child->left;

	if (node->right != nullptr)
		node->right->parent = node;

	right_child->parent = node->parent;

	if (node->parent == nullptr)
		root = right_child;
	else if (node == node->parent->left)
		node->parent->left = right_child;
	else
		node->parent->right = right_child;

	right_child->left = node;
	node->parent = right_child;
}

void RedBlackTree::rotateRight(RedBlackTreeNode *node)
{
	RedBlackTreeNode *left_child = node->left;
	node->left = left_child->right;

	if (node->left != nullptr)
		node->left->parent = node;

	left_child->parent = node->parent;

	if (node->parent == nullptr)
		root = left_child;
	else if (node == node->parent->left)
		node->parent->left = left_child;
	else
		node->parent->right = left_child;

	left_child->right = node;
	node->parent = left_child;
}

void RedBlackTree::fixInsertRBTree(RedBlackTreeNode *node)
{
	RedBlackTreeNode *parent = nullptr;
	RedBlackTreeNode *grandparent = nullptr;
	while (node != root && getColor(node) == RED && getColor(node->parent) == RED)
	{
		parent = node->parent;
		grandparent = parent->parent;
		if (parent == grandparent->left)
		{
			RedBlackTreeNode *uncle = grandparent->right;
			if (getColor(uncle) == RED)
			{
				setColor(uncle, BLACK);
				setColor(parent, BLACK);
				setColor(grandparent, RED);
				node = grandparent;
			}
			else
			{
				if (node == parent->right)
				{
					rotateLeft(parent);
					node = parent;
					parent = node->parent;
				}
				rotateRight(grandparent);
				std::swap(parent->color, grandparent->color);
				node = parent;
			}
		}
		else
		{
			RedBlackTreeNode *uncle = grandparent->left;
			if (getColor(uncle) == RED)
			{
				setColor(uncle, BLACK);
				setColor(parent, BLACK);
				setColor(grandparent, RED);
				node = grandparent;
			}
			else
			{
				if (node == parent->left)
				{
					rotateRight(parent);
					node = parent;
					parent = node->parent;
				}
				rotateLeft(grandparent);
				std::swap(parent->color, grandparent->color);
				node = parent;
			}
		}
	}
	setColor(root, BLACK);
}

void RedBlackTree::fixDeleteRBTree(RedBlackTreeNode *node)
{
	if (node == nullptr)
		return;

	if (node == root)
	{
		root = nullptr;
		return;
	}

	if (getColor(node) == RED || getColor(node->left) == RED || getColor(node->right) == RED)
	{
		RedBlackTreeNode *child = node->left != nullptr ? node->left : node->right;

		if (node == node->parent->left)
		{
			node->parent->left = child;
			if (child != nullptr)
				child->parent = node->parent;
			setColor(child, BLACK);
			delete node;
		}
		else
		{
			node->parent->right = child;
			if (child != nullptr)
				child->parent = node->parent;
			setColor(child, BLACK);
			delete node;
		}
	}
	else
	{
		RedBlackTreeNode *sibling = nullptr;
		RedBlackTreeNode *parent = nullptr;
		RedBlackTreeNode *ptr = node;
		setColor(ptr, DOUBLE_BLACK);
		while (ptr != root && getColor(ptr) == DOUBLE_BLACK)
		{
			parent = ptr->parent;
			if (ptr == parent->left)
			{
				sibling = parent->right;
				if (getColor(sibling) == RED)
				{
					setColor(sibling, BLACK);
					setColor(parent, RED);
					rotateLeft(parent);
				}
				else
				{
					if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK)
					{
						setColor(sibling, RED);
						if (getColor(parent) == RED)
							setColor(parent, BLACK);
						else
							setColor(parent, DOUBLE_BLACK);
						ptr = parent;
					}
					else
					{
						if (getColor(sibling->right) == BLACK)
						{
							setColor(sibling->left, BLACK);
							setColor(sibling, RED);
							rotateRight(sibling);
							sibling = parent->right;
						}
						setColor(sibling, parent->color);
						setColor(parent, BLACK);
						setColor(sibling->right, BLACK);
						rotateLeft(parent);
						break;
					}
				}
			}
			else
			{
				sibling = parent->left;
				if (getColor(sibling) == RED)
				{
					setColor(sibling, BLACK);
					setColor(parent, RED);
					rotateRight(parent);
				}
				else
				{
					if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK)
					{
						setColor(sibling, RED);
						if (getColor(parent) == RED)
							setColor(parent, BLACK);
						else
							setColor(parent, DOUBLE_BLACK);
						ptr = parent;
					}
					else
					{
						if (getColor(sibling->left) == BLACK)
						{
							setColor(sibling->right, BLACK);
							setColor(sibling, RED);
							rotateLeft(sibling);
							sibling = parent->left;
						}
						setColor(sibling, parent->color);
						setColor(parent, BLACK);
						setColor(sibling->left, BLACK);
						rotateRight(parent);
						break;
					}
				}
			}
		}
		if (node == node->parent->left)
			node->parent->left = nullptr;
		else
			node->parent->right = nullptr;
		delete(node);
		setColor(root, BLACK);
	}
}

void RedBlackTree::preorderBST(RedBlackTreeNode *node)
{
	if (node == nullptr)
		return;

	if (node->color == RED)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << node->data << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
		std::cout << node->data << std::endl;
	preorderBST(node->left);
	preorderBST(node->right);
}

void RedBlackTree::inorderBST(RedBlackTreeNode *node)
{
	if (node == nullptr)
		return;

	inorderBST(node->left);
	if (node->color == RED)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << node->data << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
		std::cout << node->data << std::endl;

	inorderBST(node->right);
}

void RedBlackTree::postorderBST(RedBlackTreeNode *node)
{
	if (node == nullptr)
		return;

	postorderBST(node->left);
	postorderBST(node->right);
	if (node->color == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << node->data << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else
		std::cout << node->data << std::endl;

}


int RedBlackTree::getColor(RedBlackTreeNode *node)
{
	if (node == nullptr)
		return BLACK;

	return node->color;
}

void RedBlackTree::setColor(RedBlackTreeNode *node, int color)
{
	if (node == nullptr)
		return;

	node->color = color;
}

RedBlackTreeNode * RedBlackTree::minValueNode(RedBlackTreeNode *node)
{
	RedBlackTreeNode *temp = node;

	while (temp->left != nullptr)
		temp = temp->left;

	return temp;
}

RedBlackTreeNode * RedBlackTree::insertBST(RedBlackTreeNode *root, RedBlackTreeNode *node)
{
	if (root == nullptr)
		return node;

	if (node->data < root->data)
	{
		root->left = insertBST(root->left, node);
		root->left->parent = root;
	}
	else if (node->data > root->data)
	{
		root->right = insertBST(root->right, node);
		root->right->parent = root;
	}

	return root;
}

RedBlackTreeNode * RedBlackTree::deleteBST(RedBlackTreeNode *root, int data)
{
	if (root == nullptr || root->left == nullptr || root->right == nullptr)
		return root;

	if (data < root->data)
		return deleteBST(root->left, data);

	if (data > root->data)
		return deleteBST(root->right, data);

	RedBlackTreeNode *temp = minValueNode(root->right);
	root->data = temp->data;
	return deleteBST(root->right, temp->data);
}
