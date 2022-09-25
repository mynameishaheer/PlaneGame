#pragma once
#include "Plane.h"

class Bullet : public Plane {
public:

	Bullet();
	Bullet(int x, int y);
	~Bullet();


	void Move();
	void Hit();
};