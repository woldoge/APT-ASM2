#include "Item.h"
#include <string>
#include <iostream>

Item::Item(string ID) {
	this->ID = ID;
}

void Item::display()
{
	cout << "ID: " << this->ID << " | Title: " << this->title << endl;
	cout << "Loan type: " << this->loan_type << endl;
	cout << "In-stock copies: " << this->copies << endl;
	cout << "Rental fee: " << this->fee << endl;
}


Record::Record(string ID, string title, string loan_type, int copies, double fee, string genre) {
	this->ID = ID;
	this->title = title;
	this->loan_type = loan_type;
	this->copies = copies;
	this->fee = fee;
	this->genre = genre;
}

void Record::display()
{
	Item::display();
	cout << "Genre: " << this->genre << endl;
}

DVD::DVD(string ID, string title, string loan_type, int copies, double fee, string genre) {
	this->ID = ID;
	this->title = title;
	this->loan_type = loan_type;
	this->copies = copies;
	this->fee = fee;
	this->genre = genre;
}

void DVD::display()
{
	Item::display();
	cout << "Genre: " << this->genre << endl;
}

Game::Game(string ID, string title, string loan_type, int copies, double fee) {
	this->ID = ID;
	this->title = title;
	this->loan_type = loan_type;
	this->copies = copies;
	this->fee = fee;
}