#pragma once
using namespace std;

class Phonebook
{
public:
	Phonebook();
	Phonebook(string name, string surname, string phonenumber);
	void print();
	string name, surname, phonenumber;
	Phonebook *next;
};