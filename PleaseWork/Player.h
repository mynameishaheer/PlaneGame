#pragma once

#include <stdlib.h>
#include "Plane.h"
#include "DLL.h"

class Player : public Plane {
public:
	float plane_x;
	float plane_y;

	Player();
	Player(int x, int y);
	~Player();

	void Move();
	void Translate(int x_val, int y_val);

};