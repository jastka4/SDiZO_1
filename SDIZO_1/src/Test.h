#pragma once
#include "FileNotFoundException.h"
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
	bool getInputFile(std::string mainFolder);
	bool getOutputFile(std::string mainFolder);

	virtual void array() = 0;
	virtual void list() = 0;
	virtual void heap() = 0;
	virtual void RBTree() = 0;
	virtual void AVLTree() = 0;
};
