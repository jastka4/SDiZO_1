#include "ManualTest.h"
#include "DoublyLinkedList.h"
#include "Array.h"
#include "MaxHeap.h"
#include "RedBlackTree.h"
#include "AVLTree.h"
#include "Timer.h"
#include <iostream>
#include <conio.h>

using namespace std;

void ManualTest::array()
{
	bool end = false;
	char choice;
	int value,
		position;

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
			system("cls");
			cout << "Enter a value: ";
			cin >> value;
			timer->start();
			array->insertAtBeggining(value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '2':
			system("cls");
			cout << "Enter a value: ";
			cin >> value;
			timer->start();
			array->insertAtEnd(value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '3':
			system("cls");
			cout << "Enter a value: ";
			cin >> value;
			cout << "\nEnter a position: ";
			cin >> position;
			timer->start();
			array->insertAt(position, value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '4':
			system("cls");
			timer->start();
			array->removeAtBeggining();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '5':
			system("cls");
			timer->start();
			array->removeAtEnd();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '6':
			system("cls");
			cout << "\nEnter a position: ";
			cin >> position;
			timer->start();
			array->removeAt(position);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '7':
			system("cls");
			cout << "Enter a value: ";
			cin >> value;
			timer->start();
			array->find(value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '8':
			system("cls");
			timer->start();
			array->display();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
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
	}
}

void ManualTest::list()
{
	bool end = false;
	char choice;
	int value,
		position;

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
			<< "9. Display the array\n"
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
			cout << "Enter a value: ";
			cin >> value;
			timer->start();
			list->insertAtBeggining(value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '2':
			system("cls");
			cout << "Enter a value: ";
			cin >> value;
			timer->start();
			list->insertAtEnd(value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '3':
			system("cls");
			cout << "Enter a value: ";
			cin >> value;
			cout << "\nEnter a position: ";
			cin >> position;
			timer->start();
			list->insertAfter(position, value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '4':
			system("cls");
			cout << "Enter a value: ";
			cin >> value;
			cout << "\nEnter a position: ";
			cin >> position;
			timer->start();
			list->insertBefore(position, value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '5':
			system("cls");
			timer->start();
			list->removeAtBeggining();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '6':
			system("cls");
			timer->start();
			list->removeAtEnd();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '7':
			system("cls");
			cout << "\nEnter a value to remove: ";
			cin >> value;
			timer->start();
			list->remove(value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '8':
			system("cls");
			cout << "Enter a value to find: ";
			cin >> value;
			timer->start();
			list->find(value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '9':
			system("cls");
			timer->start();
			list->display();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
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
	}
}

void ManualTest::heap()
{
	bool end = false;
	char choice;
	int value;

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
			system("cls");
			cout << "Enter a value: ";
			cin >> value;
			timer->start();
			heap->push(value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '2':
			system("cls");
			timer->start();
			heap->pop();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '3':
			system("cls");
			cout << "Enter a value to remove: ";
			cin >> value;
			timer->start();
			heap->remove(value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '4':
			system("cls");
			cout << "Enter a value to find: ";
			cin >> value;
			timer->start();
			heap->find(value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '5':
			system("cls");
			timer->start();
			heap->display();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '6':
			system("cls");
			timer->start();
			heap->displayTree();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
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
	}
}

void ManualTest::RBTree()
{
	bool end = false;
	char choice;
	int value;

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
			system("cls");
			cout << "Enter a value: ";
			cin >> value;
			timer->start();
			tree->insertValue(value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '2':
			system("cls");
			cout << "Enter a value to remove: ";
			cin >> value;
			timer->start();
			tree->deleteValue(value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '3':
			system("cls");
			cout << "Enter a value to find: ";
			cin >> value;
			timer->start();
			tree->findValue(value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '4':
			system("cls");
			timer->start();
			tree->preorder();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '5':
			system("cls");
			timer->start();
			tree->inorder();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '6':
			system("cls");
			timer->start();
			tree->postorder();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '7':
			system("cls");
			timer->start();
			tree->displayTree();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
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
	}
}

void ManualTest::AVLTree()
{
	bool end = false;
	char choice;
	int value;

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
			system("cls");
			cout << "Enter a value: ";
			cin >> value;
			timer->start();
			tree->insertValue(value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '2':
			system("cls");
			cout << "Enter a value to remove: ";
			cin >> value;
			timer->start();
			tree->removeValue(value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '3':
			system("cls");
			cout << "Enter a value to find: ";
			cin >> value;
			timer->start();
			tree->findValue(value);
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '4':
			system("cls");
			timer->start();
			tree->preorder();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '5':
			system("cls");
			timer->start();
			tree->inorder();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '6':
			system("cls");
			timer->start();
			tree->postorder();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
			cout << '\n' << "Press a key to continue..." << endl;
			_getch();
			break;
		case '7':
			system("cls");
			timer->start();
			tree->displayTree();
			timer->stop();
			cout << "Time of execution: " << timer->getTime() << " ns" << endl;
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
	}
}
