#pragma once

#include <stdlib.h>
#include "Plane.h"
#include "DLL.h"

class Player : public Plane {
public:
	int plane_x;
	int plane_y;

	Player();
	Player(int x, int y);
	~Player();

	void Move();
	void Translate(int x_val, int y_val);

};