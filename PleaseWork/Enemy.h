
#pragma once
#include "Plane.h"

class Enemy :public Plane {
public:

	Enemy();
	Enemy(int x, int y);
	~Enemy();

	void Move();
	void Hit();
	void updateArt();
};