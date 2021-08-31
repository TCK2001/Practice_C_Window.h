#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>
#include <conio.h>

#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45


//콘솔 크기 밑 타이틀 이름 설정 
void setconsoleview()
{
	system("mode con:cols=100 lines=25"); //col=x lines=y
	system("Google dinosaurs game");	
}

//위치 이동 함수 
void gotoxy(int x, int y)
{
	COORD a; //x,y값 저장 
	a.X=2*x;
	a.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a); //표준콘솔출력의 핸들을 반환해줌. GetStdHandle(STD_OUTPUT_HANDLE) 
}

//입력된 키 반환하는 함수 
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
    bool isJumping = false; //처음에는 안뛰고 있으니  false 
    bool isBottom = true;   //땅에 있으니 true 
    const int gravity = 3; //뛰는 간격 
 
    int dinoY = DINO_BOTTOM_Y; //12
    int treeX = TREE_BOTTOM_X; //45
 
    while (true)
    {
        //z키가 눌리거나  공룡이 바닥에 있지 않을시 점프가능
        if (clickkey() == 'z' && isBottom)
        {
            isJumping = true; //뛰고나서 true로 바꾸고 땅에 없으니 false로 바꾸기 
            isBottom = false;
        }
        
        if (isJumping)
        {
            dinoY -= gravity;  //점프중일때 3씩 뺌  
        }
        else
        {
            dinoY += gravity; //점프끝 3씩 더함 
        }
 
        if (dinoY >= DINO_BOTTOM_Y) //12 = 땅 
        {
            dinoY = DINO_BOTTOM_Y; //땅 도착 
            isBottom = true;  
        }
 
        if (dinoY <= 3) //3보다 작거나 같으면  
        {
            isJumping = false; //점프 끝 
        }
 
        treeX -= 2; //나무가 오는 속도 정하기 
        if (treeX <= 0)
        {
            treeX = TREE_BOTTOM_X; //나무 다시 위치에서 출력 
        }
 
        DrawDino(dinoY);    
        DrawTree(treeX);  
        Sleep(80); //속도 정하기 
        system("cls");    //한번 끝날때마다 전에꺼 지우기 
    }
    system("pause");
    return 0;
} 

