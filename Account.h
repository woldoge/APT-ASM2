#pragma once
#include <string>
#include <iostream>
#include "LinkedItems.h"

using namespace std;

class Account { // This is an abstract class
protected:
	string ID;
	string name;
	string address;
	string phone;
	int rental_num;
	LinkedItems* rental_list = new LinkedItems();
public:
	// virtual functions
	virtual void __borrow(Item item) = 0;
	virtual void __return(Item item) = 0;
	virtual void display();
	// getors
	string get_ID() { return this->ID; }
	string get_name() { return this->name; }
	string get_address() { return this->address; }
	string get_phone() { return this->phone; }
	int get_rental_num() { return this->rental_num; }
	LinkedItems* get_rental_list() { return this->rental_list; }
	// setors
	void set_ID(string ID) { this->ID = ID; }
	void set_name(string name) { this->name = name; }
	void set_address(string address) { this->address = address; }
	void set_phone(string phone) { this->phone = phone; }
	void set_rental_num(int rental_num) { this->rental_num = rental_num; }
	// Handling functions
	void add_rent(Item* item);
};

class VIPAccount :public Account {
private:
	int points;
public:
	VIPAccount() {}
	VIPAccount(string ID, string name, string address, string phone, int rental_num);
	~VIPAccount() {}
	// Handling functions
	void __borrow(Item item);
	void __return(Item item);
	void display();
};

class RegularAccount :public Account {
public:
	RegularAccount() {}
	RegularAccount(string ID, string name, string address, string phone, int rental_num);
	~RegularAccount() {}
	// Handling functions
	void __borrow(Item item);
	void __return(Item item);
	void display();
};

class GuestAccount :public Account {
private:
	const int max_rent = 2;
public:
	GuestAccount() {}
	GuestAccount(string ID, string name, string address, string phone, int rental_num);
	~GuestAccount() {}
	void __borrow(Item item);
	void __return(Item item);
	void display();
};