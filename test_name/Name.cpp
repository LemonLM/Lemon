#include "Name.h"


Name::Name(void)
{

}


Name::~Name(void)
{

}

void Name::Intershow()
{
	cout << "-----------------------------------" << endl;
	cout << "|    �û�����|                    |" << endl;
	cout << "-----------------------------------" << endl;
	cout << "|    ����  ��|                    |" << endl;
	cout << "-----------------------------------" << endl;
	cout << "|    ��¼    |      |     ȡ��    |" << endl;
	cout << "-----------------------------------" << endl;
}

//д���ļ������ļ�������ʱ���Զ�����
void Name::WriteToFile()
{
	ofstream fout("Login.txt");
	if(fout.is_open())
	{
		fout << name << endl;
		fout << passwd << endl;
		fout.close();
	}

}

//��ȡ�ļ��е����ݣ��������Ļ�ϣ�ֻ�ܴ��Ѿ����ڵ��ļ�
void Name::ReadWord()
{
	char buffer[256];
	ifstream fin("Login.txt");
	if(!fin.is_open())
	{
		cout << "Error opening file";
		exit(1);
	}
	while(!fin.eof())//eof():״̬��ʶ������֤���������ļ�βʱ����true
	{
		fin.getline(buffer,100);
		cout << buffer << endl;
	}

}

void Name::gotoxy(int x,int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void Name::Login()
{
	Intershow();
	WriteToFile();
	
	ReadWord();
	gotoxy(15,1);
	//name = cin.get();
	cin >> name;
	
	passwd = cin.get();
	gotoxy(15,3);
	cin >> passwd;

	Name n;
	
	Game g;
	g.startgame();

}