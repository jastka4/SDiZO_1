#include "AutomatedTest.h"
#include "DoublyLinkedList.h"
#include "Array.h"
#include "MaxHeap.h"
#include "RedBlackTree.h"
#include "AVLTree.h"
#include "Timer.h"
#include <iostream>
#include <conio.h>

void AutomatedTest::getInputOutputFiles(std::string mainFolder)
{
	bool success = false;

	do
	{
		try
		{
			success = getInputFile();
		}
		catch (FileNotFoundException ex)
		{
			std::cout << ex.what() << ". Filename: " << ex.getFile() << std::endl;
			std::cout << "Press a key to try again..." << std::endl;
			_getch();

			if (GetAsyncKeyState(VK_ESCAPE))
				return;
		}
	} while (!success);

	do
	{
		try
		{
			success = getOutputFile(mainFolder);
		}
		catch (FileNotFoundException ex)
		{
			std::cout << ex.what() << ". Filename: " << ex.getFile() << std::endl;
			std::cout << "Press a key to try again..." << std::endl;

			_getch();

			if (GetAsyncKeyState(VK_ESCAPE))
				return;
		}
	} while (!success);
}

void AutomatedTest::array()
{
	bool end = false;
	char choice;
	int value,
		position;

	std::string mainFile = "Array";

	Timer *timer = new Timer();

	Array *array = new Array();

	while (!end)
	{
		system("cls");
		std::cout << "Choose an array function:\n"
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
			system("cls");

			getInputOutputFiles(mainFile);

			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				array->insertAtBeggining(value);
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '2':
			system("cls");

			getInputOutputFiles(mainFile);

			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				array->insertAtEnd(value);
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '3':
			system("cls");

			getInputOutputFiles(mainFile);

			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				try
				{
					position = array->getSize() == 0 ? 0 : rand() % array->getSize();
					timer->start();
					array->insertAt(position, value);
					timer->stop();
				}
				catch (IndexOutOfBoundsException ex)
				{
					timer->stop();
					array->insertAtEnd(value);
				}

				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '4':
			system("cls");

			getInputOutputFiles(mainFile);

			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				try
				{
					timer->start();
					array->removeAtBeggining();
					timer->stop();
				}
				catch (IndexOutOfBoundsException ex)
				{
					timer->stop();
				}

				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '5':
			system("cls");

			getInputOutputFiles(mainFile);

			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				try
				{
					timer->start();
					array->removeAtEnd();
					timer->stop();
				}
				catch (IndexOutOfBoundsException ex)
				{
					timer->stop();
					std::cout << ex.what() << std::endl;
				}

				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '6':
			system("cls");

			getInputOutputFiles(mainFile);

			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				try
				{
					timer->start();
					array->removeAt(rand() % array->getSize());
					timer->stop();
				}
				catch (IndexOutOfBoundsException ex)
				{
					timer->stop();
					std::cout << ex.what() << std::endl;
				}

				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '7':
			system("cls");

			getInputOutputFiles(mainFile);

			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				array->find(value);
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '8':
			system("cls");

			timer->start();
			array->display();
			timer->stop();
			std::cout << "\nTime of execution: " << timer->getTime() << " ns" << std::endl;

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		default:
			system("cls");
			std::cout << "No option such as: " << choice << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
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

	std::string mainFile = "DLList";

	Timer *timer = new Timer();

	DoublyLinkedList *list = new DoublyLinkedList();

	while (!end)
	{
		system("cls");
		std::cout << "Choose a list function:\n"
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
			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				list->insertAtBeggining(value);
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '2':
			getInputOutputFiles(mainFile);

			system("cls");
			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				list->insertAtEnd(value);
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '3':
			getInputOutputFiles(mainFile);

			system("cls");
			std::cout << "Automated test has been started...";

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
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '4':
			getInputOutputFiles(mainFile);

			system("cls");
			std::cout << "Automated test has been started...";

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
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '5':
			getInputOutputFiles(mainFile);

			system("cls");
			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				list->removeAtBeggining();
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '6':
			getInputOutputFiles(mainFile);

			system("cls");
			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				list->removeAtEnd();
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '7':
			getInputOutputFiles(mainFile);

			system("cls");
			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				list->remove(value);
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '8':
			getInputOutputFiles(mainFile);

			system("cls");
			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				list->find(value);
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '9':
			system("cls");

			timer->start();
			list->display();
			timer->stop();
			std::cout << "\nTime of execution: " << timer->getTime() << " ns" << std::endl;

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		default:
			system("cls");
			std::cout << "No option such as: " << choice << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
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

	std::string mainFile = "MaxHeap";

	Timer *timer = new Timer();

	MaxHeap *heap = new MaxHeap();

	while (!end)
	{
		system("cls");
		std::cout << "Choose a max heap function:\n"
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
			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				heap->push(value);
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '2':
			getInputOutputFiles(mainFile);

			system("cls");
			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				try
				{
					timer->start();
					heap->pop();
					timer->stop();
				}
				catch (IndexOutOfBoundsException ex)
				{
					timer->stop();
					std::cout << ex.what() << std::endl;
				}

				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '3':
			getInputOutputFiles(mainFile);

			system("cls");
			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				heap->remove(value);
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '4':
			getInputOutputFiles(mainFile);

			system("cls");
			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				heap->find(value);
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '5':
			system("cls");

			timer->start();
			heap->display();
			timer->stop();
			std::cout << "\nTime of execution: " << timer->getTime() << " ns" << std::endl;

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '6':
			system("cls");

			timer->start();
			heap->displayTree();
			timer->stop();
			std::cout << "\nTime of execution: " << timer->getTime() << " ns" << std::endl;

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		default:
			system("cls");
			std::cout << "No option such as: " << choice << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
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

	std::string mainFile = "RBTree";

	Timer *timer = new Timer();

	RedBlackTree *tree = new RedBlackTree();

	while (!end)
	{
		system("cls");
		std::cout << "Choose a red-black tree function:\n"
			<< "1. Insert element\n"
			<< "2. Remove chosen element\n"
			<< "3. Find an element\n"
			<< "4. Display preorder\n"
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
			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				tree->insertValue(value);
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '2':
			getInputOutputFiles(mainFile);

			system("cls");
			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				tree->deleteValue(value);
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '3':
			getInputOutputFiles(mainFile);

			system("cls");
			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				tree->findValue(value);
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '4':
			system("cls");

			timer->start();
			tree->preorder();
			timer->stop();
			std::cout << "\nTime of execution: " << timer->getTime() << " ns" << std::endl;

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '5':
			system("cls");

			timer->start();
			tree->inorder();
			timer->stop();
			std::cout << "\nTime of execution: " << timer->getTime() << " ns" << std::endl;

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '6':
			system("cls");

			timer->start();
			tree->postorder();
			timer->stop();
			std::cout << "\nTime of execution: " << timer->getTime() << " ns" << std::endl;

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '7':
			system("cls");

			timer->start();
			tree->displayTree();
			timer->stop();
			std::cout << "\nTime of execution: " << timer->getTime() << " ns" << std::endl;

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		default:
			system("cls");
			std::cout << "No option such as: " << choice << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
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

	std::string mainFile = "AVLTree";

	Timer *timer = new Timer();

	::AVLTree *tree = new ::AVLTree();

	while (!end)
	{
		system("cls");
		std::cout << "Choose an AVL tree function:\n"
			<< "1. Insert element\n"
			<< "2. Remove chosen element\n"
			<< "3. Find an element\n"
			<< "4. Display preorder\n"
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
			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				tree->insertValue(value);
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '2':
			getInputOutputFiles(mainFile);
			system("cls");
			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				tree->removeValue(value);
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '3':
			getInputOutputFiles(mainFile);

			system("cls");
			std::cout << "Automated test has been started...";

			while (inputFile >> value)
			{
				timer->start();
				tree->findValue(value);
				timer->stop();
				outputFile << timer->getTime() << std::endl;
			}

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '4':
			system("cls");

			timer->start();
			tree->preorder();
			timer->stop();
			std::cout << "\nTime of execution: " << timer->getTime() << " ns" << std::endl;

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '5':
			system("cls");

			timer->start();
			tree->inorder();
			timer->stop();
			std::cout << "\nTime of execution: " << timer->getTime() << " ns" << std::endl;

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '6':
			system("cls");

			timer->start();
			tree->postorder();
			timer->stop();
			std::cout << "\nTime of execution: " << timer->getTime() << " ns" << std::endl;

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '7':
			system("cls");

			timer->start();
			tree->displayTree();
			timer->stop();
			std::cout << "\nTime of execution: " << timer->getTime() << " ns" << std::endl;

			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		default:
			system("cls");
			std::cout << "No option such as: " << choice << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		}

		inputFile.close();
		outputFile.close();
	}
}
