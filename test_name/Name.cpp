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
	cout << "|    用户名：|                    |" << endl;
	cout << "-----------------------------------" << endl;
	cout << "|    密码  ：|                    |" << endl;
	cout << "-----------------------------------" << endl;
	cout << "|    登录    |      |     取消    |" << endl;
	cout << "-----------------------------------" << endl;
}

//写入文件，当文件不存在时，自动创建
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

//读取文件中的内容，输出到屏幕上，只能打开已经存在的文件
void Name::ReadWord()
{
	char buffer[256];
	ifstream fin("Login.txt");
	if(!fin.is_open())
	{
		cout << "Error opening file";
		exit(1);
	}
	while(!fin.eof())//eof():状态标识符的验证，当到达文件尾时返回true
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