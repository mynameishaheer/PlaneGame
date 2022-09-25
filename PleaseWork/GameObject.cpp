#include "GameObject.h"


GameObject::GameObject() {};

//the parent constructor initializes values such as x, y and alive which have a common functionality in all its children
//NOTE: ascii_art is not being initialized here because its value varies from child to child
GameObject::GameObject(int x, int y) {
	alive = true;

	this->x = x;
	this->y = y;
	this->hit = false;
}

//this function is a virtual function
//it is not being overwritten in Cloud
//it is being overwritten in Rabbit
wstring GameObject::Art() {
	return ascii_art;
}

void GameObject::Translate(int x_val, int y_val)
{
}

//this fucntion is common between both children hence is not virtual
bool GameObject::Alive() {
	return alive;
}

void GameObject::Hit() {

}

//virtual destructor which will destroy any object that has been created using its pointer
//uncomment the printf() statement to verify that the parent object and the child object are both being properly deleted
GameObject::~GameObject() {
	//printf("GameObject Destroyed");
}




