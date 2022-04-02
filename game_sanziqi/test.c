#include "game.h"

//������������Ϸ
void menu()
{
	printf("*****************************\n");
	printf("****   1. play  0. exit  ****\n");
	printf("*****************************\n");
}

//��Ϸʵ��
void game()
{
	char ret;
	//����---�����Һ͵����߳���������Ϣ
	char board[ROW][COL] = {'a'};//ȫ���ո�
	InitBoard(board,ROW,COL);//���̳�ʼ��,����֮ǰ�ŵ���ħ����ʼ��֮����ŵĿո�
	DisplayBoard(board,ROW,COL);//��ӡ����

	//����
	while (1)
	{
		//�������
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = Is_Win(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}

		//��������
		ComputerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = Is_Win(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
		printf("���Ӯ\n");

	else if (ret == '#')
		printf("����Ӯ\n");
	else
		printf("ƽ��\n");

}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);//������Ϊ0ʱ���Ƴ�ѭ������ӡ�˳���Ϸ����������㣬����ѭ��������Ϊ1��������Ϸ�����벻��1����������;
}
int main()
{
	test();
	return 0;
}