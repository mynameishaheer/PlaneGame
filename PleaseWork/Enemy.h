
#pragma once
#include "GameObject.h"

class Enemy :public GameObject {
public:

	Enemy();
	Enemy(int x, int y);
	~Enemy();

	void Move();
	void Hit();
	void updateArt();
};