#include <stdio.h>
#include "DLL.h"

using namespace std;

///<change summary>
/// No changes have been made to this file other than replacing Cloud* with GameObject* where needed
///</change summary>

//constructor to initialize the head and tail as null pointers
//because the linked list does not contain any node yet
DLL::DLL() {
	this->head = this->tail = nullptr;
}

/* function to add an element in the linked list */
//if there are 0 elements it adds a new element--> head/tail point to this element
//if there are 1 or more elements it adds a new element to the tail of the linked list adn updates the tail pointer
void DLL::Append(GameObject* new_plane) {
	if (head == nullptr) {
		head = new Node(new_plane);
		tail = head;
	}
	else {
		Node* temp = new Node(new_plane);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		temp = nullptr;
	}
}

//function to delete an element in the linked list
//if there is just 1 element then it deletes that element
//if there are 2 or more elements it deletes the element from the head of the linked list
void DLL::Delete() {
	if (head != nullptr) {
		if (head == tail) {
			delete head;
			head = tail = nullptr;
		}
		else {
			Node* temp;
			temp = head;
			head = head->next;
			head->prev = nullptr;
			delete temp;
			temp = nullptr;
		}
	}
}

void DLL::Delete2(int index) {
	int i = 0;
	Node* temp = head;
	while (temp != nullptr) {
		//if no node exists
		if (temp->next == nullptr && temp->prev == nullptr) {
			head = tail = nullptr;
		}
		//if node is at the head
		else if (temp->prev == nullptr) {
			head = temp->next;
			head->prev = nullptr;
		}
		//if node is at the tail
		else if (temp->next = nullptr) {
			tail = temp->prev;
			temp->next = nullptr;
		}
		//if node is in the middle
		else {
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
		delete temp;
		temp = nullptr;
		i++;
	}
}


//function to return an element at any given location i
GameObject* DLL::at(int i) {
	int index = 0;

	Node* temp = head;

	while (temp != nullptr) {
		if (index == i) {
			return temp->plane;
		}
		else {
			index++;
			temp = temp->next;
		}
	}
	temp = nullptr;
}


//function to return the size of the linked list
int DLL::Size() {
	int count = 0;

	Node* temp = head;

	while (temp != nullptr) {
		temp = temp->next;
		count++;
	}

	temp = nullptr;

	return count;
}