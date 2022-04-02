#include "game.h"

//测试三子棋游戏
void menu()
{
	printf("*****************************\n");
	printf("****   1. play  0. exit  ****\n");
	printf("*****************************\n");
}

//游戏实现
void game()
{
	char ret;
	//数组---存放玩家和电脑走出的棋盘信息
	char board[ROW][COL] = {'a'};//全部空格
	InitBoard(board,ROW,COL);//棋盘初始化,不论之前放的神魔，初始化之后均放的空格
	DisplayBoard(board,ROW,COL);//打印棋盘

	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = Is_Win(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}

		//电脑下棋
		ComputerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret = Is_Win(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
		printf("玩家赢\n");

	else if (ret == '#')
		printf("电脑赢\n");
	else
		printf("平局\n");

}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);//当输入为0时，推出循环，打印退出游戏；当输入非零，进入循环，输入为1，进入游戏，输入不是1，重新输入;
}
int main()
{
	test();
	return 0;
}