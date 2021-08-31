#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>
#include <conio.h>

#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45


//�ܼ� ũ�� �� Ÿ��Ʋ �̸� ���� 
void setconsoleview()
{
	system("mode con:cols=100 lines=25"); //col=x lines=y
	system("Google dinosaurs game");	
}

//��ġ �̵� �Լ� 
void gotoxy(int x, int y)
{
	COORD a; //x,y�� ���� 
	a.X=2*x;
	a.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a); //ǥ���ܼ������ �ڵ��� ��ȯ����. GetStdHandle(STD_OUTPUT_HANDLE) 
}

//�Էµ� Ű ��ȯ�ϴ� �Լ� 
int clickkey()
{
	if(_kbhit()!=0)
	{
		return _getch();
	}
	return 0;
}

void DrawDino(int dinoY)
{
    gotoxy(0, dinoY);
    static bool legFlag = true;
    printf("        ####### \n");
    printf("       ## ######\n");
    printf("      ##########\n");
    printf("#      ####     \n");
    printf("##     ######## \n");
    printf("###   #####     \n");
    printf(" ## ########### \n");
    printf(" ###########    \n");
    printf("  ##########    \n");
    printf("   #########    \n");
    printf("    ########    \n");
    printf("     ######     \n");
    if (legFlag)
    {
        printf("     #    ###    \n");
        printf("     ##          ");
        legFlag = false;
    }
    else
    {
        printf("     ###  #     \n");
        printf("          ##    ");
        legFlag = true;
    }
}

void DrawTree(int treex)
{
	gotoxy(treex, TREE_BOTTOM_Y);
    printf("$$$$");
    gotoxy(treex, TREE_BOTTOM_Y + 1);
    printf(" $$ ");
    gotoxy(treex, TREE_BOTTOM_Y + 2);
    printf(" $$ ");
    gotoxy(treex, TREE_BOTTOM_Y + 3);
    printf(" $$ ");
    gotoxy(treex, TREE_BOTTOM_Y + 4);
    printf(" $$ ");

}

int main()
{
	setconsoleview();
	bool isJumping = false; //ó������ �ȶٰ� ������  false 
    bool isBottom = true;   //���� ������ true 
    const int gravity = 3; //�ٴ� ���� 
 
    int dinoY = DINO_BOTTOM_Y; //12
    int treeX = TREE_BOTTOM_X; //45
 
    while (true)
    {
        //zŰ�� �����ų�  ������ �ٴڿ� ���� ������ ��������
        if (clickkey() == 'z' && isBottom)
        {
            isJumping = true; //�ٰ��� true�� �ٲٰ� ���� ������ false�� �ٲٱ� 
            isBottom = false;
        }
        
        if (isJumping)
        {
            dinoY -= gravity;  //�������϶� 3�� ��  
        }
        else
        {
            dinoY += gravity; //������ 3�� ���� 
        }
 
        if (dinoY >= DINO_BOTTOM_Y) //12 = �� 
        {
            dinoY = DINO_BOTTOM_Y; //�� ���� 
            isBottom = true;  
        }
 
        if (dinoY <= 3) //3���� �۰ų� ������  
        {
            isJumping = false; //���� �� 
        }
 
        treeX -= 2; //������ ���� �ӵ� ���ϱ� 
        if (treeX <= 0)
        {
            treeX = TREE_BOTTOM_X; //���� �ٽ� ��ġ���� ��� 
        }
 
        DrawDino(dinoY);    
        DrawTree(treeX);  
        Sleep(80); //�ӵ� ���ϱ� 
        system("cls");    //�ѹ� ���������� ������ ����� 
    }
    system("pause");
    return 0;
} 

