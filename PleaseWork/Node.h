#include <stdio.h>
#include "Plane.h"

using namespace std;

class Node {
public:

	//the node now stores gameObject which could either be a cloud or a rabbit
	Plane* plane;

	Node* next;
	Node* prev;

	Node(Plane* new_object);
};