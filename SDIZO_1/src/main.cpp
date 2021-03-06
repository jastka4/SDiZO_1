// main.cpp : Defines the entry point for the console application.

#include "ManualTest.h"
#include "AutomatedTest.h"
#include "FullTest.h"
#include <iostream>
#include <conio.h>

int main()
{
	ManualTest manualTest;
	AutomatedTest automatedTest;
	FullTest fullTest;
	
	bool end = false;
	char choice,
		 test;

	while (!end)
	{
		system("cls");
		std::cout << "Choose a data structure:\n"
			<< "1. Array\n"
			<< "2. Doubly-linked list\n"
			<< "3. Binary max heap\n"
			<< "4. Red-black tree\n"
			<< "5. AVL tree\n"
			<< "0. Quit\n"
			<< "Your choice: ";

		choice = _getch();

		if (choice != '0' && choice != 27 && choice != 'a')
		{
			do
			{
				std::cout << "\nAutomate the test(y/n): ";
				test = _getch();
			}
			while (test != 'y' && test != 'n');
		}

		switch (choice)
		{
		case '0':
			end = true;
			break;
		case 27:
			end = true;
			break;
		case '1':
			if (test == 'y')
				automatedTest.array();
			manualTest.array();
			break;
		case '2':
			if (test == 'y')
				automatedTest.list();
			manualTest.list();
			break;
		case '3':
			if (test == 'y')
				automatedTest.heap();
			manualTest.heap();
			break;
		case '4':
			if (test == 'y')
				automatedTest.RBTree();
			manualTest.RBTree();
			break;
		case '5':
			if (test == 'y')
				automatedTest.AVLTree();
			manualTest.AVLTree();
			break;
		default:
			system("cls");
			std::cout << "No option such as: " << choice << std::endl;
			std::cout << '\n' << "Press a key to continue..." << std::endl;
			_getch();
			break;
		}
	}

    return 0;
}
