#pragma once
#include <memory>

using namespace std;

class STreeNode {
public:
	shared_ptr<STreeNode> sLeft;
	shared_ptr<STreeNode> sRight;
	int data;
public:
	STreeNode(int data)
	{
		this->data = data;
	}
};

class SBinarySearchTree {
private:
	void AddElement(shared_ptr<STreeNode> current, int data);
	shared_ptr<STreeNode> FindInBST(shared_ptr<STreeNode> current, int data);
	int* ReadInOrder(shared_ptr<STreeNode> current);
	int* ReadPreOrder(shared_ptr<STreeNode> current);

	shared_ptr<STreeNode> sHead = nullptr;
	int ArrIndex = 0;
	int * bstToArr = new int[Length];
public:
	int Find(int data);
	void Add(int data);
	int* Read();
	bool Delete(int data);
	int Length = 0;
};
