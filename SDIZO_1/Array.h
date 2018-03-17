#pragma once
class Array
{
	size_t size;
	int *array;
	void relocate(size_t);
public:
	Array();
	~Array();

	void insertAtBeggining(int);
	void insertAtEnd(int);
	void insertAt(size_t, int);
	void removeAt(size_t);
	void removeAtBeggining();
	void removeAtEnd();
	size_t find(int);
	void display();
};

