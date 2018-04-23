#pragma once
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>

class Test
{
protected:
	std::string inputData, outputData;

	std::ofstream outputFile;
	std::ifstream inputFile;

public:
	void getInputFile(std::string mainFolder);
	void getOutputFile(std::string mainFolder);

	virtual void array() = 0;
	virtual void list() = 0;
	virtual void heap() = 0;
	virtual void RBTree() = 0;
	virtual void AVLTree() = 0;
};
