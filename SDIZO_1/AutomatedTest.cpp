#include "AutomatedTest.h"
#include "DoublyLinkedList.h"
#include "Array.h"
#include "MaxHeap.h"
#include "RedBlackTree.h"
#include "AVLTree.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <conio.h>

using namespace std;

void AutomatedTest::getInputOutputFiles(string mainFolder)
{
	do
	{
		system("cls");
		cout << "Name of the file with input data: ";
		cin >> inputData;

		inputFile.open("../SDIZO_1/Input/" + inputData);

		if (!inputFile.is_open())
			cout << "The file: " << inputData << " could not be opened" << endl;
	} while (!inputFile.is_open());

	do
	{
		cout << "Name of the output file: ";
		cin >> outputData;

		outputFile.open("../SDIZO_1/Output/"+ mainFolder + "/" + outputData);

		if (!outputFile.is_open())
			cout << "The file: " << outputData << " could not be opened" << endl;
	} while (!outputFile.is_open());
}

void AutomatedTest::array()
{
	srand(time(nullptr));

	bool end = false,
		 firstLine = true;
	char choice;
	int value,
		position;

	string mainFile = "Array";

	Timer *timer = new Timer();

	Array *array = new Array();

	while (!end)
	{
		system("cls");
		cout << "Choose an array function:\n"
			<< "1. Add to the beggining\n"
			<< "2. Add to the end\n"
			<< "3. Add at a chosen index\n"
			<< "4. Remove first element \n"
			<< "5. Remove last element \n"
			<< "6. Remove chosen element\n"
			<< "7. Find an element\n"
			<< "8. Display the array\n"
			<< "0. Quit\n"
			<< "Your choice: ";

		choice = _getch();

		switch (choice)
		{
		case '0':
			end = true;
			break;
		case 27:
			end = true;
			break;
		case '1':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				array->insertAtBeggining(value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '2':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				array->insertAtEnd(value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '3':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				position = array->getSize() == 0 ? 0 : rand() % array->getSize();
				timer->start();
				array->insertAt(position, value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '4':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				array->removeAtBeggining();
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '5':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				array->removeAtEnd();
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '6':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				array->removeAt(rand() % array->getSize());
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '7':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				array->find(value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '8':
			system("cls");

			timer->start();
			array->display();
			timer->stop();
			cout << "\nTime of execution: " << timer->getTime() << " ns" << endl;

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		default:
			system("cls");
			cout << "No option such as: " << choice << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		}

		inputFile.close();
		outputFile.close();
	}
}

void AutomatedTest::list()
{
	bool end = false,
		 firstLine = true;
	char choice;
	int value,
		position;

	string mainFile = "DLList";


	Timer *timer = new Timer();

	DoublyLinkedList *list = new DoublyLinkedList();

	while (!end)
	{
		system("cls");
		cout << "Choose a list function:\n"
			<< "1. Add to the beggining\n"
			<< "2. Add to the end\n"
			<< "3. Add after a chosen index\n"
			<< "4. Add before a chosen index\n"
			<< "5. Remove first element \n"
			<< "6. Remove last element \n"
			<< "7. Remove chosen element\n"
			<< "8. Find an element\n"
			<< "9. Display the list\n"
			<< "0. Quit\n"
			<< "Your choice: ";

		choice = _getch();

		switch (choice)
		{
		case '0':
			end = true;
			break;
		case 27:
			end = true;
			break;
		case '1':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				list->insertAtBeggining(value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '2':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				list->insertAtEnd(value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '3':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

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

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '4':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

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

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '5':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				list->removeAtBeggining();
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '6':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				list->removeAtEnd();
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '7':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				list->remove(value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '8':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				list->find(value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '9':
			system("cls");

			timer->start();
			list->display();
			timer->stop();
			cout << "\nTime of execution: " << timer->getTime() << " ns" << endl;

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		default:
			system("cls");
			cout << "No option such as: " << choice << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		}

		inputFile.close();
		outputFile.close();
	}
}

void AutomatedTest::heap()
{
	bool end = false;
	char choice;
	int value;

	string mainFile = "MaxHeap";


	Timer *timer = new Timer();

	MaxHeap *heap = new MaxHeap();

	while (!end)
	{
		system("cls");
		cout << "Choose a max heap function:\n"
			<< "1. Push element\n"
			<< "2. Pop element \n"
			<< "3. Remove chosen element\n"
			<< "4. Find an element\n"
			<< "5. Display the heap\n"
			<< "6. Display the heap as a tree\n"
			<< "0. Quit\n"
			<< "Your choice: ";

		choice = _getch();

		switch (choice)
		{
		case '0':
			end = true;
			break;
		case 27:
			end = true;
			break;
		case '1':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				heap->push(value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '2':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				heap->pop();
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '3':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				heap->remove(value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '4':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				heap->find(value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '5':
			system("cls");

			timer->start();
			heap->display();
			timer->stop();
			cout << "\nTime of execution: " << timer->getTime() << " ns" << endl;

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '6':
			system("cls");

			timer->start();
			heap->displayTree();
			timer->stop();
			cout << "\nTime of execution: " << timer->getTime() << " ns" << endl;

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		default:
			system("cls");
			cout << "No option such as: " << choice << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		}

		inputFile.close();
		outputFile.close();
	}
}

void AutomatedTest::RBTree()
{
	bool end = false;
	char choice;
	int value;

	string mainFile = "RBTree";


	Timer *timer = new Timer();

	RedBlackTree *tree = new RedBlackTree();

	while (!end)
	{
		system("cls");
		cout << "Choose a red-black tree function:\n"
			<< "1. Insert element\n"
			<< "2. Remove chosen element\n"
			<< "3. Find an element\n"
			<< "4. Display postorder\n"
			<< "5. Display inorder\n"
			<< "6. Display postorder\n"
			<< "7. Display the tree\n"
			<< "0. Quit\n"
			<< "Your choice: ";

		choice = _getch();

		switch (choice)
		{
		case '0':
			end = true;
			break;
		case 27:
			end = true;
			break;
		case '1':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				tree->insertValue(value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '2':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				tree->deleteValue(value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '3':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				tree->findValue(value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '4':
			system("cls");

			timer->start();
			tree->preorder();
			timer->stop();
			cout << "\nTime of execution: " << timer->getTime() << " ns" << endl;

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '5':
			system("cls");

			timer->start();
			tree->inorder();
			timer->stop();
			cout << "\nTime of execution: " << timer->getTime() << " ns" << endl;

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '6':
			system("cls");

			timer->start();
			tree->postorder();
			timer->stop();
			cout << "\nTime of execution: " << timer->getTime() << " ns" << endl;

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '7':
			system("cls");

			timer->start();
			tree->displayTree();
			timer->stop();
			cout << "\nTime of execution: " << timer->getTime() << " ns" << endl;

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		default:
			system("cls");
			cout << "No option such as: " << choice << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		}

		inputFile.close();
		outputFile.close();
	}
}

void AutomatedTest::AVLTree()
{
	bool end = false;
	char choice;
	int value;
	int i = 0;

	string mainFile = "AVLTree";

	Timer *timer = new Timer();

	::AVLTree *tree = new ::AVLTree();

	while (!end)
	{
		system("cls");
		cout << "Choose an AVL tree function:\n"
			<< "1. Insert element\n"
			<< "2. Remove chosen element\n"
			<< "3. Find an element\n"
			<< "4. Display postorder\n"
			<< "5. Display inorder\n"
			<< "6. Display postorder\n"
			<< "7. Display the tree\n"
			<< "0. Quit\n"
			<< "Your choice: ";

		choice = _getch();

		switch (choice)
		{
		case '0':
			end = true;
			break;
		case 27:
			end = true;
			break;
		case '1':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				tree->insertValue(value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '2':
			getInputOutputFiles(mainFile);
			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				i++;
				timer->start();
				tree->removeValue(value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '3':
			getInputOutputFiles(mainFile);

			system("cls");
			cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				tree->findValue(value);
				timer->stop();
				outputFile << timer->getTime() << endl;
			}

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '4':
			system("cls");

			timer->start();
			tree->preorder();
			timer->stop();
			cout << "\nTime of execution: " << timer->getTime() << " ns" << endl;

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '5':
			system("cls");

			timer->start();
			tree->inorder();
			timer->stop();
			cout << "\nTime of execution: " << timer->getTime() << " ns" << endl;

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '6':
			system("cls");

			timer->start();
			tree->postorder();
			timer->stop();
			cout << "\nTime of execution: " << timer->getTime() << " ns" << endl;

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '7':
			system("cls");

			timer->start();
			tree->displayTree();
			timer->stop();
			cout << "\nTime of execution: " << timer->getTime() << " ns" << endl;

			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		default:
			system("cls");
			cout << "No option such as: " << choice << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		}

		inputFile.close();
		outputFile.close();
	}
}
