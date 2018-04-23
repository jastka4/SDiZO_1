#include "Test.h"

using namespace std;

void Test::getInputFile(std::string mainFolder)
{
	do
	{
		system("cls");
		cout << "Name of the file with input data: ";
		cin >> inputData;

		inputFile.open("../SDIZO_1/bin/Input/" + inputData);

		if (!inputFile.is_open())
			cout << "The file: " << inputData << " could not be opened" << endl;
	} while (!inputFile.is_open());
}

void Test::getOutputFile(std::string mainFolder)
{
	do
	{
		cout << "Name of the output file: ";
		cin >> outputData;

		outputFile.open("../SDIZO_1/bin/Output/" + mainFolder + "/" + outputData);

		if (!outputFile.is_open())
			cout << "The file: " << outputData << " could not be opened" << endl;
	} while (!outputFile.is_open());
}
