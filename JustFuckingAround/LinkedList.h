#pragma once

class Node {
public:
	Node* next;
	Node* prev;
	int data;
public:
	Node(int data)
	{
		this->data = data;
	}

};

class LinkedList {
private:
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	int* GetAllElements();
	int* GetAllElementsInverse();
	int GetSize();
	void Append(int data);
	void Prepend(int data);
	void DeleteWithValue(int data);
	void UpdateListOnPos(int data, int position);
};