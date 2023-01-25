#pragma once
class EmployeeList
{
private:

	struct ListNode {

		double value;
		struct ListNode* next;

	};

	ListNode* head;

public:

	EmployeeList()
	{
		head = nullptr;
	}


	~EmployeeList();

	void appendNode(double);
	double calculatePayRoll(int);
	void displayEmployeeInfo(int) const;

};

