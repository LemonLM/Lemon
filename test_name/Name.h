#pragma once

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <Windows.h>
#include <cstring>
#include "Game.h"

class Name
{
public:
	Name(void);
	~Name(void);
	 
	void Login();
	void Intershow();
	void gotoxy(int x,int y);

	void WriteToFile();
	void ReadWord();

	

private:
	char name;
	char passwd;
};

