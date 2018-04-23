#pragma once
#include "Test.h"
#include "Array.h"
#include "AVLTree.h"
#include "DoublyLinkedList.h"
#include "MaxHeap.h"
#include "RedBlackTree.h"
#include "Timer.h"
#include <iostream>
#include <filesystem>

namespace fs = std::experimental::filesystem::v1;

class FullTest :
	public Test
{
	void array();
	void list();
	void heap();
	void RBTree();
	void AVLTree();

	void getInputFile(std::string);
	void getOutputFile(std::string, std::string);

public:
	void performFullTest();

	friend std::vector<std::string> getAllInputFilesWithoutExtension();
	friend std::string removeExtension(std::string);
};
