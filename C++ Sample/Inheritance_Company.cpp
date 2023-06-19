#include <iostream>
#include <string>

#define HUMAN_RESOURCE "HR"
#define FINANCE "Finance"
#define SUPPORT "Support"

using namespace std;

class Company {
	string name;
	int empID;
	string dept;
	public:
		Company() { cout << "Company (Base Class) constructor called" << endl; }
		~Company() { cout << "Company (Base Class) destructor called" << endl; }
		virtual string getDepartment() { cout << "Company Class: getDepartment() called!" << endl; return "Company"; }
		void setEmployeeDetails(string str, int id, string dept)
		{
			this->empID = id;
			this->name = str;
			this->dept = dept;
		}
		void displayEmpDetails() 
		{ 
			cout << "Name: " << name << "\nID: " << empID << "\nDept: " << dept << endl; 
		}
};

class HumanResource : public Company {
public:
	HumanResource() { cout << "HumanResource constructor called" << endl; }
	~HumanResource() { cout << "HumanResource destructor called" << endl; }
	string getDepartment() { cout << "Humen Resource Department!\n"; return HUMAN_RESOURCE; }

};

class Finance : public Company {
public:
	Finance() { cout << "Finance constructor called" << endl; }
	~Finance() { cout << "Finance destructor called" << endl; }
	string getDepartment() { cout << "Finance Department!\n"; return FINANCE; }

};

class Support : public Company {
public:
	Support() { cout << "Support constructor called" << endl; }
	~Support() { cout << "Support destructor called" << endl; }
	string getDepartment() { cout << "Support Department!\n"; return SUPPORT; }

};

int main()
{
	Company* basePtr;
	HumanResource *hrObj = new HumanResource();
	string dept;

	dept = hrObj->getDepartment();
	delete hrObj;

	basePtr = new HumanResource();
	dept = basePtr->getDepartment();
	basePtr->setEmployeeDetails("Aditi", 1, dept);
	basePtr->displayEmpDetails();

	basePtr = new Finance();
	dept = basePtr->getDepartment();
	basePtr->setEmployeeDetails("Aditya", 2, dept);
	basePtr->displayEmpDetails();

	basePtr = new Support();
	dept = basePtr->getDepartment();
	basePtr->setEmployeeDetails("Anup", 3, dept);
	basePtr->displayEmpDetails();
	
	delete basePtr;
	return 0;
}
