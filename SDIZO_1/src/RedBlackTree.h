#pragma once
#include "RedBlackTreeNode.h"

class RedBlackTree
{
	RedBlackTreeNode* root;
	RedBlackTreeNode* nil;

	void rotateLeft(RedBlackTreeNode*);
	void rotateRight(RedBlackTreeNode*);
	void fixInsertRBTree(RedBlackTreeNode*);
	void fixDeleteRBTree(RedBlackTreeNode*);
	void preorderBST(RedBlackTreeNode*);
	void inorderBST(RedBlackTreeNode*);
	void postorderBST(RedBlackTreeNode*);
	int getColor(RedBlackTreeNode*);
	void setColor(RedBlackTreeNode*, int);
	RedBlackTreeNode *minValueNode(RedBlackTreeNode*);
	RedBlackTreeNode* insertBST(RedBlackTreeNode*, RedBlackTreeNode*);
	RedBlackTreeNode* deleteBST(RedBlackTreeNode*, int);
	void deleteNode(RedBlackTreeNode*);

public:
	RedBlackTree();
	~RedBlackTree();

	void insertValue(int);
	void deleteValue(int);
	RedBlackTreeNode* findValue(int);
	void preorder();
	void inorder();
	void postorder();
	void displayTree();
};
