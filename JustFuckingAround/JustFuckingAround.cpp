// JustFuckingAround.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "BinarySearchTree.h"


using namespace std;


struct MyStruct
{
	static int sort_by;
	int num1;
	int num2;
};
int MyStruct::sort_by = 1;


int main()
{

	BinarySearchTree* bst = new BinarySearchTree;
	bst->Add(100);
	bst->Add(50);
	bst->Add(125);
	bst->Add(112);
	bst->Add(150);
	bst->Add(107);
	bst->Add(124);
	bst->Add(102);
}