#include "Game.h"


Game::Game(void)
{
	
}


Game::~Game(void)
{
}

//定义位置，跟踪蛇的位置
void Game::gotoxy(int x,int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

//定义显示颜色
void Game::color(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

//初始化，apple数组表示随机种子的位置（食物位置）
void Game::init(int apple[2])
{
	int i,j;
	int wall[N+2][N+2] = {{0}};//搭建外围墙
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			wall[i][j] = 1;
		}
	}
	color(11);
	for(i = 0;i < N+2;i++)
	{
		for(j = 0;j < N+2; j++)
		{
			if(wall[i][j])
			{
				cout << "@";
			}
			else
			{
				cout << "O";
			}
		}
		cout << endl;
	}
	//定义文字显示的位置和颜色
	gotoxy(N+3,8);
	color(20);
	cout << "按W S A D移动方向"<< endl;
	gotoxy(N+3,9);
	color(20);
	cout << "按任意键暂停" << endl;
	gotoxy(N+3,10);
	color(20);
	cout << "得分;" << endl;
	//定义随机种子的形式和位置
	apple[0] = rand() % N+2;
	apple[1] = rand() % N+9;
	gotoxy(apple[0],apple[1]);
	color(12);
	cout << "$" << endl; 
}

void Game::startgame()
{
	int i;
	int** snake = NULL;//蛇
	int apple[2];
	int score = 0;
	int tail[2];
	int len = 3;
	char ch = 'p';
	srand((unsigned)time(NULL));
	gotoxy(0,8);
	init(apple);
	snake = (int**)realloc(snake,sizeof(int*)*len);
	for(i = 0;i < len;i++)
	{
		snake[i] = (int*)malloc(sizeof(int)*2);
	}
	for(i = 0;i<len;i++)
	{
		snake[i][0] = N/2;
		snake[i][1] = N/2 + i;
		gotoxy(snake[i][0],snake[i][1]);
		color(14);
		cout << "*" << endl;
	}
	while(1)
	{
		tail[0] = snake[len-1][0];
		tail[1] = snake[len-1][1];
		gotoxy(tail[0],tail[1]);
		color(11);
		cout << "@" << endl;
		for(i = len-1;i>0;i--)
		{
			snake[i][0] = snake[i-1][0];
			snake[i][1] = snake[i-1][1];
			gotoxy(snake[i][0],snake[i][1]);
			color(14);
			cout << "*" << endl;
		}
		if(_kbhit())//定义按键值，实现其功能
		{
			gotoxy(0,N+10);
			ch = _getche();
		}
		switch(ch)
		{
		case 'w':snake[0][1]--;break;
		case 's':snake[0][1]++;break;
		case 'a':snake[0][0]--;break;
		case 'd':snake[0][0]++;break;
		default:break;
		}
		gotoxy(snake[0][0],snake[0][1]);
		color(14);
		cout << "*" << endl;
		Sleep(abs(200-0.5*score));
		if(snake[0][0] == apple[0] && snake[0][1] == apple[1])
		{
			score++;
			len++;
			snake = (int**)realloc(snake,sizeof(int*)*len);
			snake[len-1] = (int*)malloc(sizeof(int)*2);
			apple[0] = rand() % N+2;
			apple[1] = rand() % N+9;
			gotoxy(apple[0],apple[1]);
			color(12);
			cout << "$" << endl;
			gotoxy(N + 8,10);
			color(20);
			cout << score << endl;
		}
		//if(snake[0][1] == 0 || snake[0][1] == N || snake[0][0] == 0 || snake[0][0] == N)
		if(snake[0][0] == 1 || snake[0][1] == 9 || snake[0][0] == N || snake[0][1] == N+8)
		{
			gotoxy(N/2,N/2+8);
			color(30);
			cout << "失败" << endl;
			for(i = 0;i<len;i++)
			{
				free(snake[i]);
				Sleep(INFINITE);
				exit(1);
			}
		}

	}
}