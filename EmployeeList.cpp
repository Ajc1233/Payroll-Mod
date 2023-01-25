#include <iostream>
#include "EmployeeList.h"

using namespace std;

EmployeeList::~EmployeeList() {};



void EmployeeList::appendNode(double num)
{
	ListNode* newNode;
	ListNode* nodePtr;

	//Allocate a new node and store num there
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	//If there are no nodes in the list make newNode the first node. 
	if (!head)
		head = newNode;
	else
	{
		nodePtr = head;

		//Traverse throught the list until the end is reached and set the new node to that spot
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		nodePtr->next = newNode;

	}
}


//Traverse the list and print the value that was called
void EmployeeList::displayEmployeeInfo(int position) const {
	ListNode* nodePtr;

	nodePtr = head;

	//Use the parameter to traverse the list for the spot that was requested
	while (position != 0) {
		nodePtr = nodePtr->next;
		position--;
	}
	cout << nodePtr->value;
};




//Return the value of the requested list position
double EmployeeList::calculatePayRoll(int position) {
	ListNode* nodePtr;

	nodePtr = head;

	//Use the parameter to traverse the list for the spot that was requested
	while (position != 0) {
		nodePtr = nodePtr->next;
		position--;
	}

	//Return the value of the requested list position
	return nodePtr->value;



};


