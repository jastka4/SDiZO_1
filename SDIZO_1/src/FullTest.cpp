#include "FullTest.h"


std::string removeExtension(std::string filename)
{
	size_t lastindex = filename.find_last_of(".");
	std::string rawfilename = filename.substr(0, lastindex);

	return rawfilename;
}

std::vector<std::string> getAllInputFilesWithoutExtension()
{
	char sep = '/';

	#ifdef _WIN32
	sep = '\\';
	#endif

	std::vector<std::string> files;
	std::string path = "../SDIZO_1/bin/Input";
	for (auto & p : fs::directory_iterator(path))
	{
		auto path = p.path().string();
		size_t i = path.rfind(sep, path.length());

		if (i != std::string::npos) {
			files.push_back(path.substr(i + 1, path.length() - i));
		}
	}

	return files;
}

using namespace std;

void FullTest::getInputFile(string inputData)
{
	inputFile.open("../SDIZO_1/bin/Input/" + inputData);
}

void FullTest::getOutputFile(string mainFolder, string outputData)
{
	outputFile.open("../SDIZO_1/bin/Output/" + mainFolder + "/" + outputData);
}

void FullTest::array()
{
	int value,
		position;

	std::string mainFile = "Array";

	Timer *timer = new Timer();

	Array *array = new Array();

	getOutputFile(mainFile, inputData + "_add_begin.txt");

	while (inputFile >> value)
	{
		timer->start();
		array->insertAtBeggining(value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_find.txt");


	while (inputFile >> value)
	{
		timer->start();
		array->find(value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_remove_begin.txt");

	while (inputFile >> value)
	{
		timer->start();
		array->removeAtBeggining();
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_add_end.txt");

	while (inputFile >> value)
	{
		timer->start();
		array->insertAtEnd(value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_remove_end.txt");

	while (inputFile >> value)
	{
		timer->start();
		array->removeAtEnd();
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_add_random.txt");

	while (inputFile >> value)
	{
		position = array->getSize() == 0 ? 0 : rand() % array->getSize();
		timer->start();
		array->insertAt(position, value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_remove_random.txt");

	while (inputFile >> value)
	{
		timer->start();
		array->removeAt(rand() % array->getSize());
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

}

void FullTest::list()
{
	bool firstLine = true;
	int value,
		position;

	string mainFile = "DLList";

	Timer *timer = new Timer();

	DoublyLinkedList *list = new DoublyLinkedList();

	getOutputFile(mainFile, inputData + "_add_begin.txt");

	while (inputFile >> value)
	{
		timer->start();
		list->insertAtBeggining(value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_remove_begin.txt");

	while (inputFile >> value)
	{
		timer->start();
		list->removeAtBeggining();
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_add_end.txt");

	while (inputFile >> value)
	{
		timer->start();
		list->insertAtEnd(value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_remove_end.txt");

	while (inputFile >> value)
	{
		timer->start();
		list->removeAtEnd();
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_add_after.txt");

	{
		firstLine = true;

		while (inputFile >> value)
		{
			if (firstLine == true)
			{
				inputFile >> position;
				firstLine = false;
			}
			timer->start();
			list->insertAfter(position, value);
			timer->stop();
			outputFile << timer->getTime() << endl;
		}
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_remove_random.txt");

	while (inputFile >> value)
	{
		timer->start();
		list->remove(value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_add_before.txt");

	{
		firstLine = true;

		while (inputFile >> value)
		{
			if (firstLine == true)
			{
				inputFile >> position;
				firstLine = false;
			}
			timer->start();
			list->insertBefore(position, value);
			timer->stop();
			outputFile << timer->getTime() << endl;
		}
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_find.txt");

	while (inputFile >> value)
	{
		timer->start();
		list->find(value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();
}

void FullTest::heap()
{
	int value;

	string mainFile = "MaxHeap";

	Timer *timer = new Timer();

	MaxHeap *heap = new MaxHeap();

	getOutputFile(mainFile, inputData + "_push.txt");

	while (inputFile >> value)
	{
		timer->start();
		heap->push(value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_pop.txt");

	while (inputFile >> value)
	{
		timer->start();
		heap->pop();
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	while (inputFile >> value)
	{
		heap->push(value);
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	getOutputFile(mainFile, inputData + "_find.txt");

	while (inputFile >> value)
	{
		timer->start();
		heap->find(value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_remove_random.txt");

	while (inputFile >> value)
	{
		timer->start();
		heap->remove(value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();
}

void FullTest::RBTree()
{
	int value;

	string mainFile = "RBTree";

	Timer *timer = new Timer();

	RedBlackTree *tree = new RedBlackTree();

	getOutputFile(mainFile, inputData + "_insert.txt");

	while (inputFile >> value)
	{
		timer->start();
		tree->insertValue(value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_find.txt");

	while (inputFile >> value)
	{
		timer->start();
		tree->findValue(value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_remove.txt");

	while (inputFile >> value)
	{
		timer->start();
		tree->deleteValue(value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();
}

void FullTest::AVLTree()
{
	int value;

	string mainFile = "AVLTree";

	Timer *timer = new Timer();

	::AVLTree *tree = new ::AVLTree();

	getOutputFile(mainFile, inputData + "_insert.txt");

	while (inputFile >> value)
	{
		timer->start();
		tree->insertValue(value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_find.txt");

	while (inputFile >> value)
	{
		timer->start();
		tree->findValue(value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();

	getOutputFile(mainFile, inputData + "_remove.txt");

	while (inputFile >> value)
	{
		timer->start();
		tree->removeValue(value);
		timer->stop();
		outputFile << timer->getTime() << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	outputFile.close();
}

void FullTest::performFullTest()
{
	system("cls");
	std::cout << "Fully automated test has been started...\n";

	vector<string> files = getAllInputFilesWithoutExtension();
	for (auto const& file : files)
	{
		getInputFile(file);
		inputData = removeExtension(file);
		cout << "\nAmout of elements " << inputData << ":\n"
			<< "----------------------------\n";
		cout << "\nArray:\n";
		array();
		cout << "\nDoubly-linked list:\n";
		list();
		cout << "\nMax heap:\n";
		heap();
		cout << "\nRed-black tree:\n";
		RBTree();
		cout << "\nAVL tree:\n";
		AVLTree();
		inputFile.close();
	}

	cout << '\n' << "Press a key to continue..." << endl;
}
