#include "Enemy2.h"

Enemy2::Enemy2()
{
}

Enemy2::Enemy2(int x, int y) : GameObject(x, y) {
	type = 'E';
	ascii_art.clear();
	ascii_art.append(L"\\  /");
	ascii_art.append(L"\\  /");
	ascii_art.append(L"|  |");
	ascii_art.append(L" \\/ ");

}

Enemy2::~Enemy2() {}

void Enemy2::updateArt() {
	if (this->hit == true) {
		ascii_art.clear();
		ascii_art.append(L"\\||/");
		ascii_art.append(L"----");
		ascii_art.append(L"----");
		ascii_art.append(L"/||\\");
	}
	else {
		ascii_art.clear();
		ascii_art.append(L"\\  /");
		ascii_art.append(L"\\  /");
		ascii_art.append(L"|  |");
		ascii_art.append(L" \\/ ");
	}
}

void Enemy2::Move() {

	y++;
	if (y > 27) {
		alive = false;
	}
}

void Enemy2::Hit() {

	hit = true;
	updateArt();

}