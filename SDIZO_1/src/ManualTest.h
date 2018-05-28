#pragma once
#include "Test.h"

class ManualTest :
	public Test
{
	bool askIfLoadFromFile();
	void getInitialFile();
public:
	void array();
	void list();
	void heap();
	void RBTree();
	void AVLTree();
};
