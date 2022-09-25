#include <stdio.h>
#include "GameObject.h"

using namespace std;

class Node {
public:

	//the node now stores gameObject which could either be a cloud or a rabbit
	GameObject* plane;

	Node* next;
	Node* prev;

	Node(GameObject* new_object);
};