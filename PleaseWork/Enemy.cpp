#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(int x, int y) : GameObject(x, y) {
	type ='e';
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

	y++;
	if (y > 27) {
		alive = false;
	}
}

void Enemy::Hit() {

	hit = true;
	updateArt();

}