#include "Test.h"

using namespace std;

bool Test::getInputFile()
{
		system("cls");
		cout << "Name of the file with input data: ";
		cin >> inputData;

		inputFile.open("./Input/" + inputData);

		if (!inputFile.is_open())
			throw FileNotFoundException("The file could not be opened", inputData.c_str());
		
		return true;
}

bool Test::getOutputFile(std::string mainFolder)
{
		cout << "Name of the output file: ";
		cin >> outputData;

		outputFile.open("./Output/" + mainFolder + "/" + outputData);

		if (!outputFile.is_open())
			throw FileNotFoundException("The file could not be created", outputData.c_str());

		return true;
}

void Test::getUserInput(int &input, std::string type)
{
	std::cout << "Enter a " + type + ": ";
	std::cin >> input;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		std::cout << "Bad entry. Enter a NUMBER: ";
		std::cin >> input;
	}
}
