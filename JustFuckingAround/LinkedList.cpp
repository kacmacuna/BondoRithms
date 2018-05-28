#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int* LinkedList::GetAllElements()
{
	const int ARR_SIZE = GetSize();
	int* linkedListToArr = new int[ARR_SIZE];
	Node* current = head;
	int index = 0;
	do 
	{
		linkedListToArr[index] = current->data;
		cout << linkedListToArr[index] << " ";
		current = current->next;
	} while (current != nullptr);
	return linkedListToArr;
}

int* LinkedList::GetAllElementsInverse()
{
	const int ARR_SIZE = GetSize();
	int* linkedListToArr = new int[ARR_SIZE];
	Node* current = tail;
	int index = 0;
	do
	{
		linkedListToArr[index] = current->data;
		cout << linkedListToArr[index] << " ";
		current = current->prev;
	} while (current != nullptr);
	return linkedListToArr;
}

int LinkedList::GetSize()
{
	int length = 0;
	Node *current = head;
	while (current != nullptr)
	{
		current = current->next;
		length++;
	}
	return length;
}

void LinkedList::Append(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
		return;
	}
	Node *current = head;
	while (current->next != nullptr)
	{
		current = current->next;
	}
	current->next = new Node(data);
	current->next->prev = current;
	tail = current->next;
	return;
}

void LinkedList::Prepend(int data)
{
	Node* newHead = new Node(data);
	newHead->next = head;
	head = newHead;
	head->next->prev = head;
}

void LinkedList::DeleteWithValue(int data)
{
	if (!head || !tail)
		return;
	if (head->data == data)
	{
		head = head->next;
		head->prev = nullptr;
	}

	else if (tail->data == data)
	{
		tail = tail->prev;
		tail->next = nullptr;
	};
	Node* current = head;
	while (current->next)
	{

		if (current->next->data == data)
		{
			current->next = current->next->next;
			current->next->prev = current;
			return;
		}
		current = current->next;
	}
}

void LinkedList::UpdateListOnPos(int data, int position)
{
	if (!head || !tail || position > GetSize() || position < 0)
		return;
	if (position == 0)
	{
		Prepend(data);
		return;
	}	
	if (position == GetSize())
	{
		Append(data);
		return;
	}
	Node* current = head;
	int index = 0;
	while (current->next)
	{
		if (current->next != nullptr && index == position-1)
		{
			Node* newNode = new Node(data);
			newNode->next = current->next;
			current->next = newNode;
		}
		current = current->next;
		index++;
	}
}
