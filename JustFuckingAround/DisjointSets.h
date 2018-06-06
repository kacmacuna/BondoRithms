#pragma once
class DSNode
{
public:
	int data;
	int rank;
	DSNode* parent;
public:
	DSNode(int data)
	{
		this->data = data;
	}
	
};

class DisjointSets
{
public:
	DSNode * FindParent(DSNode* current);
	void DSUnion(DSNode* dsNode1, DSNode* dsNode2);
};
