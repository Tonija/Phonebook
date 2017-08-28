#include <iostream>
#include <conio.h>
#include <string>
#include "Phonebook.h"

using namespace std;

void displayAll(Phonebook *contact);
void addContact(Phonebook *contact, string name, string surname, string phonenumber);
Phonebook *findContact(Phonebook *contact, string name, string surname);
void deleteContact(Phonebook *contact, string name, string surname);

int main() {
	Phonebook contact;
	char action;
	string name, surname;

	do {
		cout << "v - view all" << endl << "a - add new" << endl << "d - delete" << endl << "f - find contact" << endl << "x - exit" << endl << endl;
		action = _getch();
		switch (action)
		{
		case 'a':
			addContact(&contact, contact.name, contact.surname, contact.phonenumber);
			break;
		case 'v':
			displayAll(&contact);
			break;
		case 'd':
			//contact.findContact();
			cout << "Enter full name: " << endl;
			cin >> name >> surname;
			deleteContact(&contact, name, surname);
			break;
		case 'f':
			cout << "Enter full name: " << endl;
			cin >> name >> surname;
			findContact(&contact, name, surname);
			break;
		}
		cout << endl;
	} while (action != 'x');

	system("PAUSE");
	return 0;
}

void displayAll(Phonebook *contact) {
	contact->print();
	if (contact->next != NULL) 
		displayAll(contact->next);
}

void addContact(Phonebook *contact, string name, string surname, string phonenumber) {
	
	cout << "Full name: " << endl;
	cin >> contact->name >> contact->surname;
	cout << "Phonenumber: " << endl;
	cin >> contact->phonenumber;

	Phonebook *newContact = new Phonebook (contact->name, contact->surname, contact->phonenumber);

	newContact->next = contact->next;
	contact->next = newContact;
}

Phonebook* findContact(Phonebook *contact, string name, string surname) {
	
	if (contact->next == NULL)
		return NULL;
	if (contact->name == name && contact->surname == surname) {
		contact->print();
		return contact;
	}
	else
		cout << "contact not found" << endl;

	return (contact->next);	
}

void deleteContact(Phonebook *contact, string name, string surname) {

	Phonebook *temp;

	if (contact->next == NULL)
		return;
	if (contact->next->name == name && contact->next->surname == surname) {
		temp = contact->next;
		contact->next = contact->next->next;
		delete  temp;
		cout << "Contact deleted" << endl;
		return;
	}		
	if (contact->next != NULL)
		deleteContact(contact->next, name, surname);
}