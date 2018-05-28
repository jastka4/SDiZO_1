#include "ManualTest.h"
#include "DoublyLinkedList.h"
#include "Array.h"
#include "MaxHeap.h"
#include "RedBlackTree.h"
#include "AVLTree.h"
#include "Timer.h"
#include <iostream>
#include <conio.h>

bool ManualTest::askIfLoadFromFile()
{
	system("cls");

	char choice = 0;

	do
	{
		std::cout << "Load initial values from file(y/n): ";
		choice = _getch();
	} while (choice != 'y' && choice != 'n' && choice != '0' && choice != 27);

	if (choice == 'y')
	{
		getInitialFile();
		return true;
	}

	return false;
}

void ManualTest::getInitialFile()
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
}

void ManualTest::array()
{
	bool end = false,
		loadFromFile = false;
	char choice;
	int value,
		position;

	size_t index = -1;

	Timer *timer = new Timer();

	Array *array = new Array();

	loadFromFile = askIfLoadFromFile();
	if (loadFromFile)
	{
		while (inputFile >> value)
		{
			array->insertAtEnd(value);
		}
	}

	inputFile.close();

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
			
			getUserInput(value, "value");

			timer->start();
			array->insertAtBeggining(value);
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '2':
			system("cls");
			
			getUserInput(value, "value");

			timer->start();
			array->insertAtEnd(value);
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '3':
			system("cls");
			
			getUserInput(value, "value");
			getUserInput(position, "position");
			
			try
			{
				timer->start();
				array->insertAt(position, value);
				timer->stop();
			}
			catch (IndexOutOfBoundsException ex)
			{
				timer->stop();
				std::cout << ex.what() << std::endl;
				array->insertAtEnd(value);
				std::cout << "Inserted at the end of the array" << std::endl;
			}

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '4':
			system("cls");

			try
			{
				timer->start();
				array->removeAtBeggining();
				timer->stop();
			}
			catch (IndexOutOfBoundsException ex)
			{
				timer->stop();
				std::cout << ex.what() << std::endl;
			}

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '5':
			system("cls");

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

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '6':
			system("cls");

			getUserInput(position, "position");

			try
			{
				timer->start();
				array->removeAt(position);
				timer->stop();
			}
			catch (IndexOutOfBoundsException ex)
			{
				timer->stop();
				std::cout << ex.what() << std::endl;
			}

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '7':
			system("cls");
			
			getUserInput(value, "value");
			timer->start();
			index = array->find(value);
			timer->stop();

			if (index != -1)
				std::cout << "Value found at: " << index << std::endl;
			else
				std::cout << "Value not found" << std::endl;

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '8':
			system("cls");
			timer->start();
			array->display();
			timer->stop();
			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
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
	}
}

void ManualTest::list()
{
	bool end = false,
		 loadFromFile = false;
	char choice;
	int value,
		position;

	DoublyLinkedNode* node = nullptr;

	Timer *timer = new Timer();

	DoublyLinkedList *list = new DoublyLinkedList();

	loadFromFile = askIfLoadFromFile();
	if (loadFromFile)
	{
		while (inputFile >> value)
		{
			list->insertAtEnd(value);
		}
	}

	inputFile.close();

	while (!end)
	{
		system("cls");
		std::cout << "Choose a list function:\n"
			<< "1. Add to the beggining\n"
			<< "2. Add to the end\n"
			<< "3. Add after a chosen element\n"
			<< "4. Add before a chosen element\n"
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
			system("cls");
			
			getUserInput(value, "value");

			timer->start();
			list->insertAtBeggining(value);
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '2':
			system("cls");
			
			getUserInput(value, "value");

			timer->start();
			list->insertAtEnd(value);
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '3':
			system("cls");
			
			getUserInput(value, "value");
			getUserInput(position, "position");

			timer->start();
			list->insertAfter(position, value);
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '4':
			system("cls");
			
			getUserInput(value, "value");
			getUserInput(position, "position");

			timer->start();
			list->insertBefore(position, value);
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '5':
			system("cls");

			timer->start();
			list->removeAtBeggining();
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '6':
			system("cls");

			timer->start();
			list->removeAtEnd();
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '7':
			system("cls");

			getUserInput(value, "value");
			timer->start();
			list->remove(value);
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '8':
			system("cls");

			getUserInput(value, "value to find");
			timer->start();
			node = list->find(value);
			timer->stop();

			if (node != nullptr)
				std::cout << "Value found" << std::endl;
			else
				std::cout << "Value not found" << std::endl;

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '9':
			system("cls");

			timer->start();
			list->display();
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
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
	}
}

void ManualTest::heap()
{
	bool end = false,
		loadFromFile = false;
	char choice;
	int value;

	size_t index = -1;

	Timer *timer = new Timer();

	MaxHeap *heap = new MaxHeap();

	loadFromFile = askIfLoadFromFile();
	if (loadFromFile)
	{
		while (inputFile >> value)
		{
			heap->push(value);
		}
	}

	inputFile.close();

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
			system("cls");
			
			getUserInput(value, "value");

			timer->start();
			heap->push(value);
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '2':
			system("cls");

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

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '3':
			system("cls");

			getUserInput(value, "value to remove");

			timer->start();
			heap->remove(value);
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '4':
			system("cls");
			getUserInput(value, "value to find");

			timer->start();
			index = heap->find(value);
			timer->stop();

			if (index != -1)
				std::cout << "Value found at: " << index << std::endl;
			else
				std::cout << "Value not found" << std::endl;

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '5':
			system("cls");

			timer->start();
			heap->display();
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '6':
			system("cls");

			timer->start();
			heap->displayTree();
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
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
	}
}

void ManualTest::RBTree()
{
	bool end = false,
		loadFromFile = false;
	char choice;
	int value;

	RedBlackTreeNode* node = nullptr;

	Timer *timer = new Timer();

	RedBlackTree *tree = new RedBlackTree();

	loadFromFile = askIfLoadFromFile();
	if (loadFromFile)
	{
		while (inputFile >> value)
		{
			tree->insertValue(value);
		}
	}

	inputFile.close();

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
			system("cls");
			
			getUserInput(value, "value");

			timer->start();
			tree->insertValue(value);
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '2':
			system("cls");

			getUserInput(value, "value to remove");

			timer->start();
			tree->deleteValue(value);
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '3':
			system("cls");

			getUserInput(value, "value to find");

			timer->start();
			node = tree->findValue(value);
			timer->stop();

			if (node != nullptr)
				std::cout << "Value found" << std::endl;
			else
				std::cout << "Value not found" << std::endl;

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '4':
			system("cls");

			timer->start();
			tree->preorder();
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '5':
			system("cls");

			timer->start();
			tree->inorder();
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '6':
			system("cls");

			timer->start();
			tree->postorder();
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '7':
			system("cls");

			timer->start();
			tree->displayTree();
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
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
	}
}

void ManualTest::AVLTree()
{
	bool end = false,
		loadFromFile = false;
	char choice;
	int value;

	AVLTreeNode* node = nullptr;

	Timer *timer = new Timer();

	::AVLTree *tree = new ::AVLTree();

	loadFromFile = askIfLoadFromFile();
	if (loadFromFile)
	{
		while (inputFile >> value)
		{
			tree->insertValue(value);
		}
	}

	inputFile.close();

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
			system("cls");
			
			getUserInput(value, "value");

			timer->start();
			tree->insertValue(value);
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '2':
			system("cls");

			getUserInput(value, "value to remove");

			timer->start();
			tree->removeValue(value);
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '3':
			system("cls");

			getUserInput(value, "value to find");

			timer->start();
			node = tree->findValue(value);
			timer->stop();

			if (node != nullptr)
				std::cout << "Value found" << std::endl;
			else
				std::cout << "Value not found" << std::endl;

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '4':
			system("cls");

			timer->start();
			tree->preorder();
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '5':
			system("cls");

			timer->start();
			tree->inorder();
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '6':
			system("cls");

			timer->start();
			tree->postorder();
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		case '7':
			system("cls");

			timer->start();
			tree->displayTree();
			timer->stop();

			std::cout << "Time of execution: " << timer->getTime() << " ns" << std::endl;
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
	}
}
