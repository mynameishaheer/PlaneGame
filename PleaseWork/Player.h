#pragma once

#include <stdlib.h>
#include "GameObject.h"
#include "DLL.h"

class Player : public GameObject {
public:
	float plane_x;
	float plane_y;

	Player();
	Player(int x, int y);
	~Player();

	void Move();
	void Translate(int x_val, int y_val);

};