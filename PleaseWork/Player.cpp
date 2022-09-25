#include "Player.h"

Player::Player()
{
}

Player::Player(int x, int y) :Plane(x, y)
{

	this->plane_x = x;
	this->plane_y = y;

	ascii_art.append(L" /\\ ");
	ascii_art.append(L" || ");
	ascii_art.append(L"/  \\");
	ascii_art.append(L"|  |");
	//ascii_art.append(L"1234");
	//ascii_art.append(L"5678");
	//ascii_art.append(L"9012");z
	//ascii_art.append(L"3456");
}

Player::~Player()
{
}

void Player::Move()
{
	this->x += (int)this->plane_x;
	this->y += (int)this->plane_y;
	
	if (x < 0) {
		x = 0;
	}
	else if (x > 116) {
		x = 116;
	}

	if (y < 2) {
		y = 0;
	}
	else if (y > 27) {
		y = 27;
	}

	plane_x *= 0.6;
	plane_y *= 0.6;


	/*if (x >= 0 && y >= 2) {
		this->x += this->plane_x;
		this->y += this->plane_y;
	}

	else {
		alive = false;
	}*/
}

void Player::Translate(int x_val, int y_val) {

	this->plane_x = x_val;
	this->plane_y = y_val;
}
