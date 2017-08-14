#pragma once
#include <iostream>
using namespace std;
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define N 21

class Game
{
public:
	Game(void);
	~Game(void);

	void gotoxy(int x,int y);
	void color(int a);
	void init(int apple[2]);
	void startgame();
};

