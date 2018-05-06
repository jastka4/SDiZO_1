#include "Test.h"

using namespace std;

bool Test::getInputFile(std::string mainFolder)
{
		system("cls");
		cout << "Name of the file with input data: ";
		cin >> inputData;

		inputFile.open("./Input/" + inputData);

		if (!inputFile.is_open())
			throw FileNotFoundException("The file could not be opened", inputData.c_str());

}

bool Test::getOutputFile(std::string mainFolder)
{
		cout << "Name of the output file: ";
		cin >> outputData;

		outputFile.open("./Output/" + mainFolder + "/" + outputData);

		if (!outputFile.is_open())
			throw FileNotFoundException("The file could not be created", outputData.c_str());
}
