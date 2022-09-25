#include "Bullet.h"

Bullet::Bullet(int x, int y) :GameObject(x, y) {
	type = 'B';
	ascii_art.append(L"    ");
	ascii_art.append(L" || ");
	ascii_art.append(L"    ");
	ascii_art.append(L"    ");
}

Bullet::~Bullet()
{
}

void Bullet::Move()
{
	if (y > 2) { 
		y--;
	}
	else {
		alive = false;
	}
}

void Bullet::Hit() {
	hit == true;
	alive = false;
}


