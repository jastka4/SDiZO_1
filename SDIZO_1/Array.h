#pragma once
class Array
{
	size_t size;
	int *array;
	void relocate(size_t);
public:
	Array();
	~Array();

	void insertAt(size_t, int);
	void insertAtBeggining(int);
	void insertAtEnd(int);
	void removeAt(size_t);
	void removeAtBeggining();
	void removeAtEnd();
	size_t find(int);
	void display();

	size_t getSize();
};
