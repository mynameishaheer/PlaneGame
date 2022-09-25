#pragma once
//Header file for the parent class Game Object

#pragma once

#include <iostream>
#include <stdlib.h>

using namespace std;

class Plane {
public:
	//these following attributes are shared by each child
	int x;
	int y;
	wstring ascii_art;
	bool alive;
	bool hit;

	Plane();
	Plane(int x, int y);
	virtual ~Plane(); //virtual destructor to automatically call child destructor when this is called in the Delete() function

	//virtual function
	wstring virtual Art();
	//pure virtual function
	void virtual Move() = 0;
	void virtual Translate(int x_val, int y_val);

	void virtual Hit();
	bool Alive();
};