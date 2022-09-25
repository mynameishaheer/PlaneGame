#include <iostream>
#include <Windows.h>
#include <thread>
#include <vector>
#include <stdlib.h> 
#include "DLL.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemy2.h"
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

	GameObject* player = new Player(60, 20);
	bool power_up = false;

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
			int rand_enemy = rand() % 2;
			if (rand_enemy == 0) {
				int random = (rand() % 80) + 20;
				GameObject* enemy = new Enemy2(random, 0);
				enemy_list.Append(enemy);
			}
			else {
				int random = (rand() % 80) + 20;
				GameObject* enemy = new Enemy(random, 0);
				enemy_list.Append(enemy);
			}
		}

		if (power_up == true) {
			if (nSpeedCount % 5 == 0)
			{
				GameObject* bullet = new Bullet(player->x, player->y - 4);
				bullet_list.Append(bullet);
			}
		}
		else {
			if (nSpeedCount % 15 == 0)
			{
				GameObject* bullet = new Bullet(player->x, player->y - 4);
				bullet_list.Append(bullet);

			}
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
				screen[2] = L'S';
				screen[3] = L'C';
				screen[4] = L'O';
				screen[5] = L'R';
				screen[6] = L'E';
				screen[7] = L':';

				screen[9] = '0' + tens;
				screen[10] = '0' + ones;
				if (power_up == true) {
					screen[122] = L'U';
					screen[123] = L'P';
					screen[124] = L'G';
					screen[125] = L'R';
					screen[126] = L'A';
					screen[127] = L'D';
					screen[128] = L'E';
				}
				else {
					screen[122] = L'N';
					screen[123] = L'O';
					screen[124] = L'R';
					screen[125] = L'M';
					screen[126] = L'A';
					screen[127] = L'L';
				}
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
				GameObject* enemy = enemy_list.at(ind);


				//MOVE
				if (enemy->hit == false) {
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
				if (player->x > enemy->x + 3 || enemy->x > player->x + 3) {
					screen[45] = L' ';
				}
				else if (player->y > enemy->y + 3 || enemy->y > player->y + 3) {
					screen[45] = L' ';
				}
				else {
					if (enemy->hit == false) {
						game_running = false;
					}
				}
			}

			////////////ENEMY////////////

			////////////BULLET////////////
			for (int i = 0; i < bCount; i++) {

				GameObject* bull = bullet_list.at(i);

				//MOVE
				if (bull->hit == false) {
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
			}
			////////////BULLET////////////


			int ESize = enemy_list.Size();
			int BSize = bullet_list.Size();
			for (int i = 0; i < BSize; i++) {
				GameObject* bullet = bullet_list.at(i);
				for (int j = 0; j < ESize; j++) {
					GameObject* enemy = enemy_list.at(j);
					if (enemy->type == 'e') {
						if (bullet->x >= enemy->x + 3 || enemy->x >= bullet->x + 3) {
							screen[60] = L' ';
						}
						else if (bullet->y >= enemy->y + 3 || enemy->y >= bullet->y + 3) {
							screen[60] = L' ';
						}
						else {
							if (enemy->hit == false) {
								ones++;
								bullet->Hit();
								enemy->Hit();
								int power_spawn = rand() % 10;
								if (power_spawn == 1 || power_spawn == 2 || power_spawn == 0) {
									power_up = true;

								}
								else {
									power_up = false;
								}
							}
						}
					}
					else if (enemy->type = 'E') {
						if (enemy->type == 'e') {
							if (bullet->x >= enemy->x + 6 || enemy->x >= bullet->x + 6) {
								screen[60] = L' ';
							}
							else if (bullet->y >= enemy->y + 6 || enemy->y >= bullet->y + 6) {
								screen[60] = L' ';
							}
							else {
								if (enemy->hit == false) {
									int direction = rand() % 2;
									int move = rand() % 6;
									if (direction == 0) {
										enemy->x += move;
									}
									else {
										enemy->x -= move;
									}
									//ones++;
									//bullet->Hit();
									//enemy->Hit();
									/*int power_spawn = rand() % 10;
									if (power_spawn == 1 || power_spawn == 2 || power_spawn == 0) {
										power_up = true;

									}
									else {
										power_up = false;
									}*/
								}
							}
						}
					}
				}

			}
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
		if (enemy_list.Size() > 1) {
			enemy_list.Delete();
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
