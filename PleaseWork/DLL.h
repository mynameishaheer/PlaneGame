#pragma once

#include "GameObject.h"
#include "Node.h"

class DLL {
private:
	Node* head;
	Node* tail;

public:
	DLL();

	void Append(GameObject* new_object);
	void Delete();
	GameObject* at(int i);
	int Size();
	void Delete2(int index);
};
