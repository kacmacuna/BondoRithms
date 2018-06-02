#include "stdafx.h"
#include "SBinarySearchTree.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <memory>

using namespace std;

void SBinarySearchTree::AddElement(shared_ptr<STreeNode> current, int data)
{
	/*Add Element If Left Child Is Empty*/
	if (data <= current->data && current->sLeft == nullptr)
	{
		current->sLeft = make_shared<STreeNode>(data);
	}
	/*If Left Child Pos Already Is Occupied Use Recursion */
	else if (data <= current->data && current->sLeft != nullptr)
	{
		AddElement(current->sLeft, data);
	}
	/*Add Element If Right Child Is Empty*/
	if (data > current->data && current->sRight == nullptr)
	{
		current->sRight = make_shared<STreeNode>(data);
	}
	/*If Right Child Pos Already Is Occupied Use Recursion */
	else if (data > current->data && current->sRight != nullptr)
	{
		AddElement(current->sRight, data);
	}
}

shared_ptr<STreeNode> SBinarySearchTree::FindInBST(shared_ptr<STreeNode> current, int data)
{
	/*If Match Has Been Found Return IT*/
	if (data == current->data || data == current->data) {
		return current;
	}

	if (data <= current->data && current->sLeft != nullptr)
	{
		return FindInBST(current->sLeft, data);
	}
	if (data > current->data && current->sRight != nullptr)
	{
		return FindInBST(current->sRight, data);
	}
	return nullptr;
}

int SBinarySearchTree::Find(int data)
{
	return FindInBST(sHead, data) ? FindInBST(sHead, data)->data : 0;
}

void SBinarySearchTree::Add(int data)
{
	Length++;
	if (!sHead)
	{
		
		sHead = make_shared<STreeNode>(data);
		return;
	}
	AddElement(sHead, data);
}

int * SBinarySearchTree::ReadInOrder(shared_ptr<STreeNode> current)
{
	if (current->sLeft)
		ReadInOrder(current->sLeft);
	bstToArr[ArrIndex] = current->data;
	ArrIndex++;
	cout << current.use_count() << " ";
	if (current->sRight)
		ReadInOrder(current->sRight);
	return bstToArr;
}

int * SBinarySearchTree::ReadPreOrder(shared_ptr<STreeNode> current)
{
	bstToArr[ArrIndex] = current->data;
	ArrIndex++;
	cout << current->data << " ";
	if (current->sLeft && current->sLeft != 0)
		ReadPreOrder(current->sLeft);
	if (current->sRight  && current->sRight != 0)
		ReadPreOrder(current->sRight);
	return bstToArr;
}

int * SBinarySearchTree::Read()
{
	bstToArr = new int[Length];
	ArrIndex = 0;

	return ReadInOrder(sHead);
}

bool SBinarySearchTree::Delete(int data)
{
	shared_ptr<STreeNode> current = FindInBST(sHead, data);
	current.reset();
	cout << current.use_count() << endl;
	return false;
}
