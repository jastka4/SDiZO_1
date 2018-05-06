#pragma once
#include "Test.h"
#include <iostream>
#include <fstream>

class AutomatedTest :
	public Test
{
	void getInputOutputFiles(std::string);

public:
	void array();
	void list();
	void heap();
	void RBTree();
	void AVLTree();
};
