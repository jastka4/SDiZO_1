#include "stdafx.h"
#include "MaxHeap.h"
#include <iostream>

MaxHeap::MaxHeap() //find(int value)
{
	size = 0;
	heap = new int[size];
}

MaxHeap::~MaxHeap()
{
	delete[] heap;
	size = 0;
}

size_t MaxHeap::getParent(size_t index)
{
	return (index - 1) / 2;
}

size_t MaxHeap::getLeftChild(size_t index)
{
	return (2 * index + 1);
}

size_t MaxHeap::getRightChild(size_t index)
{
	return (2 * index + 2);
}

void MaxHeap::relocate(size_t newSize)
{
	int* temp = new int[newSize];
	if (newSize >= size)
	{
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = heap[i];
		}
	}
	else
	{
		for (size_t i = 0; i < newSize; i++)
		{
			temp[i] = heap[i];
		}
	}
	heap = temp;
}

void MaxHeap::swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int MaxHeap::getMax()
{
	return heap[0];
}

void MaxHeap::insertKey(int key)
{
	relocate(size + 1);
	size++;
	int i = size - 1;
	heap[i] = key;

	while (i != 0 && heap[getParent(i)] < heap[i])
	{
		swap(&heap[i], &heap[getParent(i)]);
		i = getParent(i);
	}
}

void MaxHeap::increaseKey(size_t index, int newValue)
{
	heap[index] = newValue;
	while (index != 0 && heap[getParent(index)] < heap[index])
	{
		swap(&heap[index], &heap[getParent(index)]);
		index = getParent(index);
	}
}

int MaxHeap::extractMax()
{
	if (size <= 0)
		std::cout << "Heap is empty";
	else if (size == 1)
	{
		size--;
		return heap[0];
	}

	int root = heap[0];
	heap[0] = heap[size - 1];
	relocate(size - 1);
	size--;
	heapify(0);

	return root;
}

void MaxHeap::deleteKey(int value) //TODO: find element by value 
{
	size_t key = find(value);
	if (key == -1)
	{
		std::cout << "Value not found" << std::endl;
		return;
	}

	increaseKey(key, INT_MAX);
	extractMax();
}

void MaxHeap::heapify(size_t index)
{
	size_t leftChild = getLeftChild(index);
	size_t rightChild = getRightChild(index);
	size_t biggest = index;

	if (leftChild < size && heap[leftChild] > heap[biggest])
		biggest = leftChild;
	if (rightChild < size && heap[rightChild] > heap[biggest])
		biggest = rightChild;
	if (biggest != index)
	{
		swap(&heap[index], &heap[biggest]);
		heapify(biggest);
	}
}

size_t MaxHeap::find(int value)
{
	for (size_t i = 0; i < size; i++)
	{
		if (heap[i] == value)
			return i;
	}

	return -1;
}

void MaxHeap::display()
{
	for (size_t i = 0, lvl = 1; i < size; i++)
	{
		if (i + 1 == lvl)
		{
			lvl *= 2;
			std::cout << std::endl;
		}

		std::cout << heap[i] << " ";
	}

	std::cout << std::endl;
}
