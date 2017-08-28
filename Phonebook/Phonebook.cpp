#include <iostream>
#include <conio.h>
#include <string>
#include "Phonebook.h"

using namespace std;

Phonebook::Phonebook()
{
	this->name;
	this->surname;
	this->phonenumber;
	this->next = NULL;
}

Phonebook::Phonebook(string name, string surname, string phonenumber)
{
	this->name = name;
	this->surname =surname;
	this->phonenumber = phonenumber;
	this->next = NULL;
}

void Phonebook::print() {
	if (this->name.empty()) {
		cout << "Phonebook list is empty" << endl;
		return;
	}
	else
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	cout << "Full name: " << this->name << " " << this->surname << endl;
	cout << "Phonenumber: " << this->phonenumber << endl;
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl << endl;
}