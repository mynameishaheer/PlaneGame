#include <iostream>
#include <Windows.h>
#include <thread>
#include <vector>
#include <stdlib.h> 
#include "DLL.h"
#include "Plane.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

using namespace std;

const int nScreenWidth = 120;
const int nScreenHeight = 40;


int main()
{
#include <stdlib.h> 
	bool game_running = true;

	//creating a doubly linkedlist
	DLL enemy_list;
	DLL bullet_list;

	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];

	for (int i = 0; i < nScreenWidth * nScreenHeight; i++)
		screen[i] = L' ';
	screen[nScreenWidth * nScreenHeight - 1] = '\0';

	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	bool bKey[6];

	long int nSpeedCount = 0;
	int ones = 0;
	int tens = 0;

	Plane* player = new Player(60, 20);

	//game loop
	while (game_running)
	{
		//INPUT
		for (int k = 0; k < 6; k++)
			bKey[k] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28\x26\x20\x1B"[k]))) != 0;
		//MOVE
		if (bKey[0])//Right
		{
			screen[0] = L'R';
			player->Translate(4, 0);
		}
		if (bKey[1])//Left
		{
			screen[0] = L'L';
			player->Translate(-4, 0);

		}
		if (bKey[2])//Down
		{
			screen[0] = L'D';
			player->Translate(0, 4);
		}
		if (bKey[3])//Up
		{
			screen[0] = L'U';
			player->Translate(0, -4);
		}
		if (bKey[5])//Escape
		{
			game_running = false;
		}

		this_thread::sleep_for(50ms);
		nSpeedCount++;

		if (nSpeedCount % 50 == 0)
		{
			int random = rand() % 110;
			Plane* enemy = new Enemy(random, 0);
			enemy_list.Append(enemy);
		}

		if (nSpeedCount % 15 == 0)
		{
			Plane* bullet = new Bullet(player->x, player->y - 4);
			bullet_list.Append(bullet);

		}


		//RENDER
		if (nSpeedCount % 2 == 0)
		{
			int size = enemy_list.Size();
			int bCount = bullet_list.Size();


			////////////PLAYER////////////
			//CLEAN	
			for (int i = 0; i < (nScreenWidth * nScreenHeight); i++) {
				screen[i] = L' ';
				if (ones > 9) {
					tens++;
					ones = 0;
				}
				screen[9] = '0' + tens;
				screen[10] = '0' + ones;
			}

			player->Move();
			//RENDER
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (player->Alive() == true) {
						screen[player->x + i + (player->y + j) * nScreenWidth] = player->Art()[i + j * 4];
					}
				}
			}
			////////////PLAYER///////////

			////////////ENEMY////////////
			for (int ind = 0; ind < size; ind++)
			{
				Plane* enemy = enemy_list.at(ind);


				//MOVE
				if (enemy->alive == true) {
					enemy->Move();
				}

				//RENDER
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (enemy->Alive() == true || enemy->hit == false) {
							screen[enemy->x + i + (enemy->y + j) * nScreenWidth] = enemy->Art()[i + j * 4];
						}
					}
				}

				for (int a = 0; a < bCount; a++) {
					bool flag = false;
					Plane* bull = bullet_list.at(a);
					if (enemy->hit == false) {
						if (bull->x+1 > enemy->x + 3 || enemy->x > bull->x + 2) {
							screen[60] = L' ';
						}
						else if (bull->y + 1 > enemy->y + 3 || enemy->y > bull->y + 2) {
							screen[60] = L' ';
						}
						else {
							screen[90] = L'B';
							ones++;
							flag = true;
							bull->Hit();
						}
						if (player->x > enemy->x + 3 || enemy->x > player->x + 3) {
							screen[45] = L' ';
						}
						else if (player->y > enemy->y + 3 || enemy->y > player->y + 3) {
							screen[45] = L' ';
						}
						else {
							screen[45] = L'P';
						}
					}
					else {
						enemy->Hit();
					}
				}

				//COLLIDE
				//enemy and player collision detection

				//if (player->x > enemy->x + 3 || enemy->x > player->x + 3) {
				//	screen[45] = L' ';
				//}
				//else if (player->y > enemy->y + 3 || enemy->y > player->y + 3) {
				//	screen[45] = L' ';
				//}
				//else {
				//	screen[45] = L'P';
				//}
			}

			////////////ENEMY////////////

			////////////BULLET////////////
			for (int i = 0; i < bCount; i++) {

				Plane* bull = bullet_list.at(i);

				//MOVE
				if (bull->alive == true) {
					bull->Move();
				}
				//RENDER
				for (int a = 0; a < 4; a++) {
					for (int b = 0; b < 4; b++) {
						if (bull->Alive() == true) {
							screen[bull->x + a + (bull->y + b) * nScreenWidth] = bull->Art()[a + b * 4];
						}
					}
				}

				//COLLIDE
				//for (int j = 0; j < size; j++) {
				//	Plane* enemy = enemy_list.at(j);

				//	//enemy and bullet collision
				//	if (enemy->hit == false) {
				//		if (bull->x > enemy->x + 3 || enemy->x > bull->x + 3) {
				//			screen[60] = L' ';
				//		}
				//		else if (bull->y > enemy->y + 3 || enemy->y > bull->y + 3) {
				//			screen[60] = L' ';
				//		}
				//		else {
				//			ones++;
				//			bull->Hit();
				//			enemy->Hit();
				//		}
				//	}
				//}
			}
			////////////BULLET////////////
		}


		//CLEANUP

		for (int i = 0; i < enemy_list.Size(); i++)
		{
			if (enemy_list.at(i)->Alive() == false)
			{
				delete enemy_list.at(i); //deallocate memory taken by cloud object
				enemy_list.Delete2(i);     // deallocate memory taken by node object
			}

		}
		for (int i = 0; i < bullet_list.Size(); i++) {
			if (bullet_list.at(i)->Alive() == false)
			{
				delete bullet_list.at(i); //deallocate memory taken by cloud object
				bullet_list.Delete2(i);     // deallocate memory taken by node object
			}
		}
		//Writing output to console
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
	}

	return 0;
}
