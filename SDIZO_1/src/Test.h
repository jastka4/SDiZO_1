#pragma once
#include "FileNotFoundException.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <windows.h>
#include <conio.h>

class Test
{
protected:
	std::string inputData, outputData;

	std::ofstream outputFile;
	std::ifstream inputFile;

	bool getInputFile();
	bool getOutputFile(std::string);

public:
	void getUserInput(int&, std::string);
	void getInputOutputFiles(std::string);

	virtual void array() = 0;
	virtual void list() = 0;
	virtual void heap() = 0;
	virtual void RBTree() = 0;
	virtual void AVLTree() = 0;
};
