#include "Array.h"
#include <iostream>

Array::Array()
{
	size = 0;
	array = nullptr;
}

Array::~Array()
{
	delete[] array;
	size = 0;
}

void Array::relocate(size_t newSize)
{
	int* temp = new int[newSize];
	if (newSize >= size)
	{
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = array[i];
		}
	}	
	else
	{
		for (size_t i = 0; i < newSize; i++)
		{
			temp[i] = array[i];
		}
	}
	delete array;
	array = temp;
}

void Array::insertAtBeggining(int data)
{
	relocate(size + 1);
	size++;
	for (size_t i = size - 1; i > 0; i--)
	{
		array[i] = array[i - 1];
	}
	array[0] = data;
}

void Array::insertAtEnd(int data)
{
	relocate(size + 1);
	array[++size - 1] = data;
}

void Array::insertAt(size_t index, int data)
{
	if (index >= size)
	{
		std::cout << "Index is bigger than the size. Inserted at the end of the array" << std::endl;
		insertAtEnd(data);
	}
	else
	{
		relocate(size + 1);
		size++;
		for (size_t i = size - 1; i > index; i--)
		{
			array[i] = array[i - 1];
		}
		array[index] = data;
	}
}

void Array::removeAt(size_t index)
{
	if (size == 0)
		std::cout << "Array is empty. Cannot remove element" << std::endl;
	else if (index >= size)
	{
		std::cout << "Index is bigger than the size. Cannot remove element" << std::endl;
	}
	else
	{
		for (size_t i = index; i < size - 1; i++)
		{
			array[i] = array[i + 1];
		}
		relocate(size - 1);
		size--;
	}
}

void Array::removeAtBeggining()
{
	if (size == 0)
		std::cout << "Array is empty. Cannot remove element" << std::endl;
	else
	{
		for (size_t i = 0; i < size - 1; i++)
		{
			array[i] = array[i + 1];
		}
		relocate(size - 1);
		size--;
	}
}

void Array::removeAtEnd()
{
	if (size == 0)
		std::cout << "Array is empty. Cannot remove element" << std::endl;
	else
	{
		array[size - 1] = 0;
		relocate(size - 1);
		size--;
	}
}

size_t Array::find(int data)
{
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] == data)
			return i;
	}
	return -1;
}

void Array::display()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "[Index: " << i << " Value: " << array[i] << "]";
		if (i != size - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}
