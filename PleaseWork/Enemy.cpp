#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(int x, int y) : Plane(x, y) {
	ascii_art.clear();
	ascii_art.append(L"|  |");
	ascii_art.append(L"\\  /");
	ascii_art.append(L" || ");
	ascii_art.append(L" \\/ ");

}

Enemy::~Enemy() {}

void Enemy::updateArt() {
	if (this->hit == true) {
		ascii_art.clear();
		ascii_art.append(L"\\||/");
		ascii_art.append(L"----");
		ascii_art.append(L"----");
		ascii_art.append(L"/||\\");
	}
	else {
		ascii_art.clear();
		ascii_art.append(L"|  |");
		ascii_art.append(L"\\  /");
		ascii_art.append(L" || ");
		ascii_art.append(L" \\/ ");
	}
}

void Enemy::Move() {

	if (y < 27) {
		y++;
	}
	else {
		alive = false;
	}
}

void Enemy::Hit() {

	hit = true;
	updateArt();

}