#pragma once
#include "GameObject.h"

class Bullet : public GameObject {
public:

	Bullet();
	Bullet(int x, int y);
	~Bullet();


	void Move();
	void Hit();
};