#include "Game.h"


Game::Game(void)
{
	
}


Game::~Game(void)
{
}

//����λ�ã������ߵ�λ��
void Game::gotoxy(int x,int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

//������ʾ��ɫ
void Game::color(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

//��ʼ����apple�����ʾ������ӵ�λ�ã�ʳ��λ�ã�
void Game::init(int apple[2])
{
	int i,j;
	int wall[N+2][N+2] = {{0}};//���Χǽ
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
	//����������ʾ��λ�ú���ɫ
	gotoxy(N+3,8);
	color(20);
	cout << "��W S A D�ƶ�����"<< endl;
	gotoxy(N+3,9);
	color(20);
	cout << "���������ͣ" << endl;
	gotoxy(N+3,10);
	color(20);
	cout << "�÷�;" << endl;
	//����������ӵ���ʽ��λ��
	apple[0] = rand() % N+2;
	apple[1] = rand() % N+9;
	gotoxy(apple[0],apple[1]);
	color(12);
	cout << "$" << endl; 
}

void Game::startgame()
{
	int i;
	int** snake = NULL;//��
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
		if(_kbhit())//���尴��ֵ��ʵ���书��
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
			cout << "ʧ��" << endl;
			for(i = 0;i<len;i++)
			{
				free(snake[i]);
				Sleep(INFINITE);
				exit(1);
			}
		}

	}
}