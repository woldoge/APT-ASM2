#pragma once
#include <string>
#include <iostream>
using namespace std;

class Item {
protected:
	string ID;
	string title;
	string loan_type;
	int copies;
	double fee;
public:
	Item() {}
	Item(string ID);
	~Item() {}
	// gettors
	string get_ID() { return this->ID; }
	string get_title() { return this->title; }
	string get_loan_type() { return this->loan_type; }
	int get_copies() { return this->copies; }
	double get_fee() { return this->fee; }
	// setors
	void set_ID(string ID) { this->ID = ID; }
	void set_title(string title) { this->title = title; }
	void set_loan_type(string loan_type) { this->loan_type= loan_type; }
	void set_copies(int copies) { this->copies = copies; }
	void set_fee(double fee) { this->fee = fee; }
	virtual void set_genre(string genre) {}
	// handling functions
	void add_copies(int num) { this->copies += num; }
	// virtual functions
	virtual void display();
};

class Record :public Item {
private:
	string genre;
public:
	Record() {}
	Record(string ID, string title, string loan_type, int copies, double fee, string genre);
	~Record() {}
	// getors
	string get_genre() { return this->genre; }
	// setors
	void set_genre(string genre) { this->genre = genre;}
	// Handling functions
	void display();
};

class DVD :public Item {
private:
	string genre;
public:
	DVD(){}
	DVD(string ID, string title, string loan_type, int copies, double fee, string genre);
	~DVD() {}
	// getors
	string get_genre() { return this->genre; }
	// setors
	void set_genre(string genre) { this->genre = genre; }
	void display();
};

class Game :public Item {
public:
	Game(){}
	Game(string ID, string title, string loan_type, int copies, double fee);
	~Game() {}
};