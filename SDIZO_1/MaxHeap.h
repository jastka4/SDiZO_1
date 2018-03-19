#pragma once
class MaxHeap
{
	int *heap;
	size_t capacity;
	size_t size;

	size_t getParent(size_t);
	size_t getLeftChild(size_t);
	size_t getRightChild(size_t);
	void relocate(size_t);
	void swap(int*, int*);

public:
	MaxHeap();
	~MaxHeap();

	int getMax();
	void insertKey(int);
	void increaseKey(size_t, int);
	int extractMax();
	void deleteKey(int);
	void heapify(size_t);
	size_t find(int);
	void display();
};

