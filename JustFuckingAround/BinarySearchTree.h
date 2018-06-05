#pragma once
#include <memory>
#include <vector>

using namespace std;
class TreeNode {
public:
	shared_ptr<shared_ptr<TreeNode>> sLeft;
	shared_ptr<shared_ptr<TreeNode>> sRight;
	int data;
	int height;
public:
	TreeNode(int data)
	{
		this->data = data;
	}
};

class BinarySearchTree {
private:
	void AddElement(shared_ptr<shared_ptr<TreeNode>> current, int data);
	shared_ptr<shared_ptr<TreeNode>> FindInBST(shared_ptr<shared_ptr<TreeNode>> current, int data);
	vector<shared_ptr<shared_ptr<TreeNode>>> ReadInOrder(shared_ptr<shared_ptr<TreeNode>> current);

	shared_ptr<shared_ptr<TreeNode>> sHead = nullptr;
	int ArrIndex = 0;
	int heightOfCurrentTree = 2;
	int * bstToArr = new int[Length];
	vector<shared_ptr<shared_ptr<TreeNode>>> bstToVector;
public:

	shared_ptr<shared_ptr<TreeNode>> Find(int data);
	void Add(int data);
	vector<shared_ptr<shared_ptr<TreeNode>>> Read();
	bool Delete(int data);
	int Length = 0;
};