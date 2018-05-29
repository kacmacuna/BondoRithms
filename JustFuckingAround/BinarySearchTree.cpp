#include "stdafx.h"
#include "BinarySearchTree.h"
#include <iostream>

using namespace std;


void BinarySearchTree::Add(int data)
{
	Length++;
	if (!head) 
	{
		head = new TreeNode(data);
		return;
	}
	AddElement(head, data);
}

void BinarySearchTree::AddElement(TreeNode * current, int data)
{
	/*Add Element If Left Child Is Empty*/
	if (data <= current->data && current->left == nullptr)
	{
		current->left = new TreeNode(data);
	}
	/*If Left Child Pos Already Is Occupied Use Recursion */
	else if (data <= current->data && current->left != nullptr)
	{
		AddElement(current->left, data);
	}
	/*Add Element If Right Child Is Empty*/
	if (data > current->data && current->right == nullptr)
	{
		current->right = new TreeNode(data);\
	}
	/*If Right Child Pos Already Is Occupied Use Recursion */
	else if (data > current->data && current->right != nullptr)
	{
		AddElement(current->right, data);
	}
		
}


int BinarySearchTree::Find(int data)
{
	return FindInBST(head, data)? FindInBST(head, data)->data:0;
}

int * BinarySearchTree::Read()
{
	bstToArr = new int[Length];
	preOrderIndex = 0;

	return ReadPreOrder(head);
}
int * BinarySearchTree::ReadPreOrder(TreeNode * current)
{
	bstToArr[preOrderIndex] = current->data;
	preOrderIndex++;
	if (current->left)
		ReadPreOrder(current->left);
	if (current->right)
		ReadPreOrder(current->right);
	return bstToArr;
}

TreeNode* BinarySearchTree::FindInBST(TreeNode * current, int data)
{
	/*If Match Has Been Found Return 1*/
	if (data == current->left->data || data == current->right->data) {
		return current;
	}

	if (data <= current->data && current->left != nullptr)
	{
		return FindInBST(current->left, data);
	}
	if (data > current->data && current->right != nullptr)
	{
		return FindInBST(current->right, data);
	}
	return nullptr;
}

void BinarySearchTree::Delete(int data)
{
	TreeNode* currentNode = FindInBST(head, data);
	TreeNode* currentChildNode;
	if (currentNode->left->data == data)
	{
		currentChildNode = currentNode->left;
		currentNode->left = currentChildNode->left ? currentChildNode->left : currentChildNode->right;
	}
	else currentChildNode = currentNode->right;
}

