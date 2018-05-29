#pragma once

class TreeNode {
public:
	TreeNode * left = nullptr;
	TreeNode * right = nullptr;
	int data;
public:
	TreeNode(int data)
	{
		this->data = data;
	}
};

class BinarySearchTree {
private:
	void AddElement(TreeNode * current, int data);
	TreeNode* FindInBST(TreeNode * current, int data);
	TreeNode * head = nullptr;

	int* ReadPreOrder(TreeNode * current);
	int* ReadInOrder(TreeNode * current);
	int ArrIndex = 0;
	int * bstToArr = new int[Length];
	
public:
	void Add(int data);
	int Find(int data);
	void Delete(int data);
	int* Read();
	int Length = 0;
};
