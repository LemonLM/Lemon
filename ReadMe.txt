C++小游戏——贪吃蛇（字符界面版）

1、登录界面
Class Name

所用方法：
void gotoxy(int x,int y);//定义登录界面位置
void Intershow();//绘制登录界面
void Login();//显示登录及跳转


2、游戏界面
Class Game

所用方法：
void gotoxy(int x,int y);//定义游戏界面位置
void color(int a);//改变输出颜色
void init(int apple[2]);//绘制游戏界面
void startgame();//开始游戏，判断游戏规则和输赢