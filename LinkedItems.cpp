#include <iostream>
#include <string>
#include "LinkedItems.h"

using namespace std;

void LinkedItems::append(Item* data)
{
	if (this->head == NULL) { // If the list is empty
		this->head = new item_node(data);
		return;
	}
	item_node *currentPtr = this->head;
	while (currentPtr->getNext() != NULL) // Scanning through the lsit of data from head to tail
		currentPtr = currentPtr->getNext();
	currentPtr->setNext(new item_node(data));
	return;
}

void LinkedItems::insertHead(Item* data)
{
	item_node* temp = this->head;
	this->head = new item_node(data);
	this->head->setNext(temp);
	return;
}

void LinkedItems::removeHead()
{
	item_node *currentPtr = head->getNext();
	delete head;
	head = currentPtr;
}


void LinkedItems::removeNode(Item* data)
{
	item_node *currentPtr = this->head;
	if (currentPtr->getData() == data) // If data matched at the head
		this->removeHead();
	else
	{
		while ((currentPtr->getNext()->getData() != data) && (currentPtr->getNext()->getNext() != NULL)) { // Loop through the datas until get to the matched data or the tail
			currentPtr = currentPtr->getNext();
		}
		if (currentPtr->getNext()->getData() != data) // When the tail data is not matched
			cout << "Account not found" << endl;
		else
		{
			if (currentPtr->getNext()->getNext() == NULL) // When the next node is not tail
				this->removeNode(currentPtr->getData());
			else // When the next node is tail
			{
				item_node *tempPtr = currentPtr->getNext();
				currentPtr->setNext(tempPtr->getNext());
				delete tempPtr;
			}
		}
	}
}

Item* LinkedItems::get_by_ID(string ID) {
	item_node *currentPtr = this->head;
	while ((currentPtr->getData()->get_ID() != ID) && (currentPtr->getNext() != NULL)) { // Loop through the datas until get to the matched data or the tail
		currentPtr = currentPtr->getNext();
	}
	if (currentPtr->getData()->get_ID() != ID) { // When the tail data is not matched
		cout << "ID not found" << endl;
		return NULL;
	}
	else {
		return currentPtr->getData();
	}
}

void LinkedItems::deleteList()
{
	item_node *currentPtr = head;
	while (currentPtr != NULL) // Scanning through list from head to tail, delete each head and make the next item node become the head
	{
		currentPtr = currentPtr->getNext();
		delete head;
		head = currentPtr;
	}
	return;
}

void LinkedItems::display_IDs() {
	item_node* currentPtr = this->head;
	if (currentPtr == NULL){ // If the list is NULL
		cout << "None";
	}
	while (currentPtr != NULL) { // Scanning through the list from head to tail
		cout <<'[' << currentPtr->getData()->get_ID() << "] ";
		currentPtr = currentPtr->getNext(); // Moving to the next node
	}
	return;
}

void LinkedItems::display_items()
{
	item_node* currentPtr = this->head;
	while (currentPtr != NULL) { // Scanning through the list from head to tail
		currentPtr->getData()->display();
		cout << endl;
		currentPtr = currentPtr->getNext();
	}
	return;
}
