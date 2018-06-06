#include "stdafx.h"
#include "DisjointSets.h"

DSNode * DisjointSets::FindParent(DSNode * current)
{
	DSNode* parent = current->parent;
	if (parent)
	{
		parent = FindParent(parent);
	}
	else
		return current;
}

void DisjointSets::DSUnion(DSNode * dsNode1, DSNode * dsNode2)
{
	/*Get Highest Point In Tree*/
	dsNode1 = FindParent(dsNode1);
	dsNode2 = FindParent(dsNode2);


	/*Compare Rank Of Nodes*/
	if (dsNode1->rank >= dsNode2->rank)
	{
		dsNode2->parent = dsNode1;
		dsNode1->rank = dsNode2->rank + 1;
		dsNode2->rank = 0;

	}
	else
	{
		dsNode1->parent = dsNode2;
		dsNode2->rank = dsNode1->rank + 1;
		dsNode1->rank = 0;
	}
}
