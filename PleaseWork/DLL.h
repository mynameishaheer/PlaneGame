#pragma once

#include "Plane.h"
#include "Node.h"

class DLL {
private:
	Node* head;
	Node* tail;

public:
	DLL();

	void Append(Plane* new_object);
	void Delete();
	Plane* at(int i);
	int Size();
	void Delete2(int index);
};
