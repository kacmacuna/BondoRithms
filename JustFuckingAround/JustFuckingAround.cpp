// JustFuckingAround.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>
#include <cstdlib>


using namespace std;

int main()
{
	int output;

	LinkedList* ll = new LinkedList;
	ll->Append(5);
	ll->Append(6);
	ll->Prepend(4);
	ll->Prepend(3);
	ll->Prepend(2);
	ll->UpdateListOnPos(7, -1);
	ll->GetAllElements();
}
