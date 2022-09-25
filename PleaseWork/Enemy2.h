
#pragma once
#include "GameObject.h"

class Enemy2 :public GameObject {
public:

	Enemy2();
	Enemy2(int x, int y);
	~Enemy2();

	void Move();
	void Hit();
	void updateArt();
};