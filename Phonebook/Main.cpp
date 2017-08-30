#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "Phonebook.h"

using namespace std;

void displayAll(Phonebook *contact);
void addContact(Phonebook *contact, string name, string surname, string phonenumber);
Phonebook *findContact(Phonebook *contact, string name, string surname);
void deleteContact(Phonebook *contact, string name, string surname);

int main() {
	Phonebook *head = new Phonebook();
	head->next = NULL;

	ofstream fileContacts_out("contacts.txt");
	ifstream fileContacts_in("contacts.txt");
	
	char action;
	string name, surname, phonenumber;

	do {
		cout << "v - view all\t" << "a - add new" << endl << "d - delete\t" << "f - find contact" << endl << "r - read from file\t" << "x - exit" << endl << endl;
		action = _getch();
		switch (action)
		{
		case 'a':
		{
			cout << "Full name: " << endl;
			cin >> name >> surname;
			cout << "Phonenumber: " << endl;
			cin >> phonenumber;
			addContact(head, name, surname, phonenumber);
			fileContacts_out << name << " " << surname << " " << phonenumber << endl;
			break;
		}
		case 'v':
			displayAll(head->next);
			break;
		case 'd':
			cout << "Enter full name: " << endl;
			cin >> name >> surname;
			deleteContact(head, name, surname);    
			break;
		case 'f':
		{
			cout << "Enter full name: " << endl;
			cin >> name >> surname;

			Phonebook *temp = findContact(head->next, name, surname);
			if (temp == NULL) {
				cout << "Contact not found";
			}
			else {
				cout << "Found contact " << temp->name << " " << temp->surname << endl;
				cout << "Phone number " << temp->phonenumber << endl;
				delete temp;
			}
		}
			break;
		case 'r':
		{
			while (fileContacts_in >> name >> surname >> phonenumber) {
				cout << name << " " << surname << " " << phonenumber << endl;
			}
			fileContacts_in.close();
		}
			break;	
		}
		cout << endl;
	} while (action != 'x');

	system("PAUSE");
	fileContacts_out.close();
	fileContacts_in.close();
	return 0;
}

void displayAll(Phonebook *contact) {
	if (contact == NULL) {
		return;
	}

	contact->print();

	if (contact->next != NULL) 
		displayAll(contact->next);
}

void addContact(Phonebook *contact, string name, string surname, string phonenumber) {
	Phonebook *newContact = new Phonebook (name, surname, phonenumber);

	newContact->next = contact->next;
	contact->next = newContact;
}

Phonebook* findContact(Phonebook *contact, string name, string surname) {
	if (contact == NULL) {
		cout << "Contact not found" << endl;
		return NULL;
	}
	
	if (contact->name == name && contact->surname == surname) {
		return contact;
	}
	
	return findContact(contact->next, name, surname);	
}

void deleteContact(Phonebook *contact, string name, string surname) {
	if (contact->next == NULL)
		return;

	Phonebook *temp;

	if (contact->next->name == name && contact->next->surname == surname) {
		temp = contact->next;
		contact->next = contact->next->next;
		delete  temp;
		cout << "Contact deleted" << endl;
		return;
	}		

	deleteContact(contact->next, name, surname);
}