#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

VIPAccount::VIPAccount(string ID, string name, string address, string phone, int rental_num) {
	this->ID = ID;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->rental_num = rental_num;
}
void VIPAccount::__borrow(Item item) {}
void VIPAccount::__return(Item item) {}

void VIPAccount::display()
{
	cout << "[VIP] ";
	Account::display();
}

RegularAccount::RegularAccount(string ID, string name, string address, string phone, int rental_num) {
	this->ID = ID;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->rental_num = rental_num;
}
void RegularAccount::__borrow(Item item) {}
void RegularAccount::__return(Item item) {}

void RegularAccount::display()
{
	cout << "[REG] ";
	Account::display();
}

GuestAccount::GuestAccount(string ID, string name, string address, string phone, int rental_num) {
	this->ID = ID;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->rental_num = rental_num;
}
void GuestAccount::__borrow(Item item) {}
void GuestAccount::__return(Item item) {}

void GuestAccount::display()
{
	cout << "[GUE] ";
	Account::display();
}


void Account::display()
{
	cout << "ID: " << this->ID << " | Name: " << this->name << endl;
	cout << "Address: " << this->address << endl;
	cout << "Phone number: " << this->phone << endl;
	cout << "Number of rented items: " << rental_num << endl;
	cout << "Renting items: ";
	this->rental_list->display_IDs();
}

void Account::add_rent(Item* item) {
	this->rental_list->append(item);
}