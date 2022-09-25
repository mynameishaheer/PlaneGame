#include <stdio.h>
#include"Node.h";
using namespace std;

Node::Node(GameObject* new_object) {
	this->plane = new_object;
	this->next = this->prev = nullptr;
}