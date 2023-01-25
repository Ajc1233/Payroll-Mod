// This program uses two parallel arrays: one for hours
// worked and one for pay rate.
#include <iostream>
#include <iomanip>
#include <list>
#include "EmployeeList.h"
using namespace std;

int main()
{
	char addNewEmployee = 'Y';
	int employeeNum;

	EmployeeList employeeID;// Number of employees
	EmployeeList hoursWorked;// Holds hours worked
	EmployeeList payRate;// Holds pay rates



	//Ask the user to enter the ID for each employee they want
	int count = 0;
	while (true) {

		cout << "Enter an employee ID number: ";
		cin >> employeeNum;
		employeeID.appendNode(employeeNum);
		count++;

		cout << "Would you like to continue? (Y/N)";
		cin >> addNewEmployee;

		addNewEmployee = toupper(addNewEmployee);

		if (addNewEmployee == 'Y')
			continue;
		else
			break;
	}


	//set total number of employees to count to be used in the while loop below
	int totalEmployee = count;


	//Ask the user for the hours and pay of each employee they entered
	double hours, pay;
	count = 0;
	while (totalEmployee != count) {


		cout << "\nEnter the hours worked by employee #" << count + 1 << " and their hourly pay rate.\n";
		cout << "\tHours worked: ";
		cin >> hours;
		cout << "\tPay rate: $";
		cin >> pay;
		hoursWorked.appendNode(hours);
		payRate.appendNode(pay);
		count++;


	}


	cout << "\n-----------------------" << endl;
	cout << "Employee\t Wages" << endl;
	cout << "-----------------------" << endl;
	cin.ignore();
	double hoursFromList, payFromList, weeklyPay;
	count = 0;
	while (totalEmployee != count) {

		//Get the value of hours and pay from the respective list, assign them to a variable
		//And then multiply both to get the weekly pay of that employee
		hoursFromList = hoursWorked.calculatePayRoll(count);
		payFromList = payRate.calculatePayRoll(count);
		weeklyPay = hoursFromList * payFromList;

		cout << "\nEmployee #"; employeeID.displayEmployeeInfo(count);
		printf("\t$%.2f", weeklyPay);
		cout << "\n\nPress any key to continue" << endl;
		cin.get();
		count++;

	}


}