#pragma once
#include <iostream>
#include <fstream>

class AutomatedTest
{
	std::string inputData, outputData;

	std::ofstream outputFile;
	std::ifstream inputFile;

	void getInputOutputFiles(std::string);
public:
	void array();
	void list();
	void heap();
	void RBTree();
	void AVLTree();
};

