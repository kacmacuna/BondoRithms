#include "stdafx.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <memory>
#include <algorithm>


vector<shared_ptr<shared_ptr<TreeNode>>> BinarySearchTree::Read()
{
	bstToArr = new int[Length];
	bstToVector.clear();
	bstToVector.reserve(Length);
	ArrIndex = 0;

	return ReadInOrder(sHead);
}


bool compareByData(const std::shared_ptr<shared_ptr<TreeNode>>& a, const std::shared_ptr<shared_ptr<TreeNode>>& b)
{
	return (*a)->data < (*b)->data;
}

bool BinarySearchTree::Delete(int data)
{
	shared_ptr<shared_ptr<TreeNode>> currentPtr = Find(data);
	if (!currentPtr)
		return false;
	shared_ptr<TreeNode> currentNode = *currentPtr;

	/*Is Leaf*/
	if (!currentNode->sLeft && !currentNode->sRight)
	{
		cout << "Doesnt Have Any Fucking Child";
		*currentPtr = nullptr;
		return true;
	}
	/*Has Only Left Child*/
	if (!currentNode->sRight)
	{
		cout << "HasOnlyLeftChild" << endl;
		*currentPtr = *(currentNode->sLeft);
		return true;
	}
	/*Has Only Right Child*/
	if (!currentNode->sLeft)
	{
		cout << "HasOnlyRightChild" << endl;
		*currentPtr = *(currentNode->sRight);
		return true;
	}
	/*Has Both Child*/
	/*So Find Smallest Number In Right Sub-Tree And Swap*/

	ArrIndex = 0;
	bstToVector.clear();
	bstToVector.reserve(Length);
	vector<shared_ptr<shared_ptr<TreeNode>>> subTreeMembers = ReadInOrder(currentNode->sRight);
	sort(subTreeMembers.begin(), subTreeMembers.end(), compareByData);

	int newValue = (*(subTreeMembers[0]))->data;
	cout << newValue;
	Delete(newValue);

	currentNode->data = newValue;

	return true;
}

vector<shared_ptr<shared_ptr<TreeNode>>> BinarySearchTree::ReadInOrder(shared_ptr<shared_ptr<TreeNode>> current)
{

	shared_ptr<TreeNode> currentNode = *current;


	if ((currentNode->sLeft))
	{
		if (*(currentNode->sLeft))
			ReadInOrder(currentNode->sLeft);
	}
	cout << ArrIndex << " : " << currentNode->data << " " << currentNode->height << endl;
	bstToArr[ArrIndex] = currentNode->data;
	bstToVector.push_back(current);
	ArrIndex++;
	if ((currentNode->sRight))
	{
		if (*(currentNode->sRight))
			ReadInOrder(currentNode->sRight);
	}
	return bstToVector;
}


shared_ptr<shared_ptr<TreeNode>> BinarySearchTree::Find(int data)
{
	return FindInBST(sHead, data) ? FindInBST(sHead, data) : nullptr;
}



shared_ptr<shared_ptr<TreeNode>> BinarySearchTree::FindInBST(shared_ptr<shared_ptr<TreeNode>> current, int data)
{
	shared_ptr<TreeNode> currentNode = *current;
	/*If Match Has Been Found Return IT*/
	if (data == currentNode->data || data == currentNode->data) {
		return current;
	}

	if (data <= currentNode->data && currentNode->sLeft != nullptr)
	{
		return FindInBST(currentNode->sLeft, data);
	}
	if (data > currentNode->data && currentNode->sRight != nullptr)
	{
		return FindInBST(currentNode->sRight, data);
	}
	return nullptr;
}


void BinarySearchTree::Add(int data)
{
	Length++;
	heightOfCurrentTree = 2;
	if (!sHead)
	{
		sHead = make_shared<shared_ptr<TreeNode>>(make_shared<TreeNode>(data));
		(*sHead)->height = 1;
		return;
	}
	AddElement(sHead, data);
}

void BinarySearchTree::AddElement(shared_ptr<shared_ptr<TreeNode>> current, int data)
{
	shared_ptr<TreeNode> currentNode = *current;
	/*Add Element If Left Child Is Empty*/
	if (data <= currentNode->data && currentNode->sLeft == nullptr)
	{
		currentNode->sLeft = make_shared<shared_ptr<TreeNode>>(make_shared<TreeNode>(data));
		(*(currentNode->sLeft))->height = heightOfCurrentTree;
	}
	/*If Left Child Pos Already Is Occupied Use Recursion */
	else if (data <= currentNode->data && currentNode->sLeft != nullptr)
	{
		heightOfCurrentTree++;
		AddElement(currentNode->sLeft, data);
	}
	/*Add Element If Right Child Is Empty*/
	if (data > currentNode->data && currentNode->sRight == nullptr)
	{
		currentNode->sRight = make_shared<shared_ptr<TreeNode>>(make_shared<TreeNode>(data));
		(*(currentNode->sRight))->height = heightOfCurrentTree;
	}
	/*If Right Child Pos Already Is Occupied Use Recursion */
	else if (data > currentNode->data && currentNode->sRight != nullptr)
	{
		heightOfCurrentTree++;
		AddElement(currentNode->sRight, data);
	}

}