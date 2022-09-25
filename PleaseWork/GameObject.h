#pragma once
//Header file for the parent class Game Object

#pragma once

#include <iostream>
#include <stdlib.h>

using namespace std;

class GameObject {
public:
	//these following attributes are shared by each child
	int x;
	int y;
	wstring ascii_art;
	bool alive;
	bool hit;
	char type;

	GameObject();
	GameObject(int x, int y);
	virtual ~GameObject(); //virtual destructor to automatically call child destructor when this is called in the Delete() function

	//virtual function
	wstring virtual Art();
	//pure virtual function
	void virtual Move() = 0;
	void virtual Translate(int x_val, int y_val);

	void virtual Hit();
	bool Alive();
};