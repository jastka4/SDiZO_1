#pragma once
#include <iostream>
#include <fstream>
#include "Test.h"

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
