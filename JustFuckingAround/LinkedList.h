#pragma once
#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

template<class NodeDataType>
class Node {
public:
	Node* next;
	Node* prev;
	NodeDataType data;
public:
	Node(NodeDataType data)
	{
		this->data = data;
	}

};

template<class LinkedListDataType>
class LinkedList {
private:
	Node<LinkedListDataType>* head = nullptr;
	Node<LinkedListDataType>* tail = nullptr;
public:
	LinkedListDataType* GetAllElements();

	LinkedListDataType* GetAllElementsInverse();
	int GetSize();
	void Append(LinkedListDataType data);
	void Prepend(LinkedListDataType data);
	void DeleteWithValue(LinkedListDataType data);
	void UpdateListOnPos(LinkedListDataType data, int position);

};

template<class LinkedListDataType>
LinkedListDataType* LinkedList<LinkedListDataType>::GetAllElements()
{
	const int ARR_SIZE = GetSize();
	LinkedListDataType* linkedListToArr = new LinkedListDataType[ARR_SIZE];
	Node<LinkedListDataType>* current = head;
	int index = 0;
	do
	{
		linkedListToArr[index] = current->data;
		cout << linkedListToArr[index] << " ";
		current = current->next;
	} while (current != nullptr);
	return linkedListToArr;
}

template<class LinkedListDataType>
LinkedListDataType* LinkedList<LinkedListDataType>::GetAllElementsInverse()
{
	const int ARR_SIZE = GetSize();
	LinkedListDataType* linkedListToArr = new LinkedListDataType[ARR_SIZE];
	Node<LinkedListDataType>* current = tail;
	int index = 0;
	do
	{
		linkedListToArr[index] = current->data;
		cout << linkedListToArr[index] << " ";
		current = current->prev;
	} while (current != nullptr);
	return linkedListToArr;
}

template<class LinkedListDataType>
int LinkedList<LinkedListDataType>::GetSize()
{
	int length = 0;
	Node<LinkedListDataType> *current = head;
	while (current != nullptr)
	{
		current = current->next;
		length++;
	}
	return length;
}

template<class LinkedListDataType>
void LinkedList<LinkedListDataType>::Append(LinkedListDataType data)
{
	if (head == nullptr)
	{
		head = new Node<LinkedListDataType>(data);
		return;
	}
	Node<LinkedListDataType> *current = head;
	while (current->next != nullptr)
	{
		current = current->next;
	}
	current->next = new Node<LinkedListDataType>(data);
	current->next->prev = current;
	tail = current->next;
	return;
}

template<class LinkedListDataType>
void LinkedList<LinkedListDataType>::Prepend(LinkedListDataType data)
{
	Node<LinkedListDataType>* newHead = new Node<LinkedListDataType>(data);
	newHead->next = head;
	head = newHead;
	head->next->prev = head;
}

template<class LinkedListDataType>
void LinkedList<LinkedListDataType>::DeleteWithValue(LinkedListDataType data)
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
	Node<LinkedListDataType>* current = head;
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

template<class LinkedListDataType>
void LinkedList<LinkedListDataType>::UpdateListOnPos(LinkedListDataType data, int position)
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
	Node<LinkedListDataType>* current = head;
	int index = 0;
	while (current->next)
	{
		if (current->next != nullptr && index == position - 1)
		{
			Node<LinkedListDataType>* newNode = new Node<LinkedListDataType>(data);
			newNode->next = current->next;
			current->next = newNode;
		}
		current = current->next;
		index++;
	}
}