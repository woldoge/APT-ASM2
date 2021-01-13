#include "Control.h"
using namespace std;

Control::Control(string customers_file, string  items_file) {
	this->is_running = true;
	this->customers_file = customers_file;
	this->items_file = items_file;
}
void Control::__init__() {
	c_list = new LinkedAccounts;
	i_list = new LinkedItems;
	ifstream c_file = ifstream(customers_file, ios::in);
	ifstream i_file = ifstream(items_file, ios::in);
	string line;
	string data;
	// Handling error
	if (!c_file.is_open() || !i_file.is_open()) {
		cout << "Can't open file" << endl;
		return;
	}
	// When file is successfully opened
	// Handling local variables
	Account *current_account = NULL;
	Item* current_item = NULL;
	int pos = 0;
	// Getting c_file updated
	while (getline(c_file, line)) { // reading line by line
		if (line[0] == 'C') { // if line is customer's info data
			if (line.find(",VIP") != string::npos) { // if line contains VIP account
				current_account = new VIPAccount();
			}
			else if (line.find(",Regular") != string::npos) { // if line contains Regular account
				current_account = new RegularAccount();
			}
			else if (line.find(",Guest") != string::npos) { // if line contains Guest account
				current_account = new  GuestAccount();
			}
			c_list->append(current_account);
			for (int i = 0; i < 5; i++) { // Setting 5 pieces of data to the current account
				data = line.substr(pos, line.find(',', pos) - pos);
				switch (i)
				{
				case 0: // ID
					current_account->set_ID(data);
					break;
				case 1: // name
					current_account->set_name(data);
					break;
				case 2: // address
					current_account->set_address(data);
					break;
				case 3: // phone
					current_account->set_phone(data);
					break;
				case 4: // rental_num
					current_account->set_rental_num(atoi(data.c_str()));
					break;
				}
				pos += line.find(',', pos) + 1 - pos; // Moving the position to the next data
			}
			pos = 0;
		}
		else if (line[0] == 'I') { // add item to rental_list of current account if line is customer's rental data
			current_account->add_rent(new Item(line));
		}
	}
	while (getline(i_file, line)) { // reading line by line
		if (line[0] == 'I') { // if line contains item data
			if (line.find(",Game") != string::npos) { // if line contains VIP account
				current_item = new Game();
			}
			else if (line.find(",Record") != string::npos) { // if line contains Regular account
				current_item = new Record();
			}
			else if (line.find(",DVD") != string::npos) { // if line contains Guest account
				current_item = new DVD();
			}
			i_list->append(current_item);
			for (int i = 0; i < 7; i++) { // Setting 7 pieces of data to the current account
				if (line.find(",Game") != string::npos && i == 6) { // Ignore the 7 piece if line is a game's data
					continue;
				}
				data = line.substr(pos, line.find(',', pos) - pos);
				switch (i)
				{
				case 0: // ID
					current_item->set_ID(data);
					break;
				case 1: // title
					current_item->set_title(data);
					break;
				case 2: // ignore the type of item
					break;
				case 3: // loan_type
					current_item->set_loan_type(data);
					break;
				case 4: // copies
					current_item->set_copies(atoi(data.c_str()));
					break;
				case 5: // fee
					current_item->set_fee(stod(data));
				case 6: // genre (when item is not game)
					current_item->set_genre(data);
				}
				pos += line.find(',', pos) + 1 - pos; // Moving the position to the next data
			}
			pos = 0;
		}
	}
	// Closing files
	c_file.close();
	i_file.close();
	// Display
	cout << "--------Welcome to Genie video store.--------" << endl << endl;
	cout << "- DIO: I am DIO BRANDO, as your assistant." << endl << endl;
	cout << "- DIO: So you are approaching our store." << endl << endl;
	// Initiate __main__
	Control::__main__();
}

void Control::__main__()
{
	while (this->is_running) {
		menu();
	}
}


void Control::menu() {
	cout << "Enter an option below as your command." << endl;
	cout << "1. Add a new item, update or delete an existing item" << endl;
	cout << "2. Add new customer or update an existing customer" << endl;
	cout << "3. Promote an existing customer" << endl;
	cout << "4. Rent an item" << endl;
	cout << "5. Return an item" << endl;
	cout << "6. Display all items" << endl;
	cout << "7. Display out - of - stock items" << endl;
	cout << "8. Display all customers" << endl;
	cout << "9. Display group of customers" << endl;
	cout << "10. Search items or customers" << endl;
	cout << "0. Exit" << endl;
	cout << "Your choice: ";
	string select;
	cin >> select;
	cout << endl;
	for (int i = 0; i < select.length(); i++) {
		if ('0' > select[i] || '9' < select[i]) {
			cout << "- DIO: Wrong input format, please enter a valid one" << endl << endl;
			return;
		}
	}
	switch (stoi(select))
	{
	case 0:
		Control::exit();
		break;
	case 1:
		cout << "Under maintainance" << endl << endl;
	case 2:
		cout << "Under maintainance" << endl << endl;
	case 3:
		cout << "Under maintainance" << endl << endl;
	case 4:
		cout << "Under maintainance" << endl << endl;
	case 5:
		cout << "Under maintainance" << endl << endl;
	case 6:
		i_list->display_items();
	case 7:
		cout << "Under maintainance" << endl << endl;
	case 8:
		c_list->display_accounts();
	case 9:
		cout << "Under maintainance" << endl << endl;
	case 10: 
		cout << "Under maintainance" << endl << endl;
	default:
		cout << "- DIO: Wrong input number, please enter a valid one" << endl << endl;
		break;
	}
}

void Control::exit()
{
	this->is_running = false;
	// Dealocate
	this->c_list->deleteList();
	this->i_list->deleteList();
	cout << "Thank you" << endl;
}

