#include <Windows.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include<MMsystem.h>
#include<process.h>
#pragma comment(lib,"winmm.lib") 

#define COL                   GetStdHandle(STD_OUTPUT_HANDLE)        // 콘솔창의 핸들정보 받기

#define BLACK                SetConsoleTextAttribute(COL, 0x0000);        // 검정색
#define DARK_BLUE         SetConsoleTextAttribute(COL, 0x0001);        // 파란색
#define GREEN                SetConsoleTextAttribute(COL, 0x0002);        // 녹색
#define BLUE_GREEN        SetConsoleTextAttribute(COL, 0x0003);        // 청녹색
#define BLOOD               SetConsoleTextAttribute(COL, 0x0004);        // 검붉은색
#define PURPLE               SetConsoleTextAttribute(COL, 0x0005);        // 보라색
#define GOLD                 SetConsoleTextAttribute(COL, 0x0006);        // 금색
#define ORIGINAL            SetConsoleTextAttribute(COL, 0x0007);        // 밝은 회색 (ORIGINAL CONSOLE COLOR)
#define GRAY                 SetConsoleTextAttribute(COL, 0x0008);        // 회색
#define BLUE                  SetConsoleTextAttribute(COL, 0x0009);        // 파란색
#define HIGH_GREEN       SetConsoleTextAttribute(COL, 0x000a);        // 연두색
#define SKY_BLUE           SetConsoleTextAttribute(COL, 0x000b);        // 하늘색
#define RED                   SetConsoleTextAttribute(COL, 0x000c);        // 빨간색
#define PLUM                SetConsoleTextAttribute(COL, 0x000d);        // 자주색
#define YELLOW             SetConsoleTextAttribute(COL, 0x000e);        // 노란색
#define WHITE                SetConsoleTextAttribute(COL, 0x000f);        // 흰색

#define LEFT   75      // 좌측방향키
#define RIGHT  77      // 우측방향키
#define DOWN   80      // 아래방향


#define wait 300		//0.3초 
#define bling 490		//0.49초

char IceCream[6][17] =
{ "      ++++      ",
"  ++++    ++++  ",
"++            ++",
"++            ++",
"  ++++    ++++  ",
"     ++++++     " };
char IceCream1[6][17] =
{ "      ++++      ",
"  ++++++++++++  ",
"++++++++++++++++",
"++++++++++++++++",
"  ++++++++++++  ",
"     ++++++     " };
int Color[3];
int sign[3] = { 0 };
int LIFE = 10;
int SCORE = 0;
char question[5][10] = { "printf", "scanf", "while", "for", "system" };  // 문제, 더 추가할 수 있음
char a[22][45] = {
	"                           ",                    // 화면에 출력될 문자열들. 이곳에 문제도 같이 출력된다
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           ",
	"                           " };
int color[22] = { 0 };                                   // 색상 지정. 
char ip[50];                               // 입력받을 문자
int life_p;
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void side()
{
	int i;
	WHITE;
	for (i = 0; i<23; i++) {
		gotoxy(11, i); printf("■");
		gotoxy(61, i); printf("■");
	}
	gotoxy(11, 22); printf("■■■■■■■■■■■■■■■■■■■■■■■■■");

}

void Icecream_down()
{
	WHITE;
	gotoxy(64, 18); printf("   @@@@@@@@@@ \n");
	gotoxy(64, 19); printf("    @@@@@@@@  \n");
	gotoxy(64, 20); printf("     @@@@@@   \n");
	gotoxy(64, 21); printf("      @@@@    \n");
	gotoxy(64, 22); printf("       @@     \n");
}

void Icecream_RED(int num)
{
	int i;
	RED;
	for (i = 0; i<6; i++){
		gotoxy(64, 6 * num + i);
		puts(IceCream[i]);
	}
	Color[num] = 1;
}

void Icecream_BLUE(int num)
{
	int i;
	BLUE;
	for (i = 0; i<6; i++)
	{
		gotoxy(64, 6 * num + i);
		puts(IceCream[i]);
	}
	Color[num] = 2;
}
void Icecream_YELLOW(int num)
{
	int i;
	YELLOW;
	for (i = 0; i<6; i++)
	{
		gotoxy(64, 6 * num + i);
		puts(IceCream[i]);
	}
	Color[num] = 3;
}

void Icecream1_RED(int num)
{
	int i;
	RED;
	for (i = 0; i<6; i++){
		gotoxy(64, 6 * num + i);
		puts(IceCream1[i]);
	}
}

void Icecream1_BLUE(int num)
{
	int i;
	BLUE;
	for (i = 0; i<6; i++)
	{
		gotoxy(64, 6 * num + i);
		puts(IceCream1[i]);
	}
}
void Icecream1_YELLOW(int num)
{
	int i;
	YELLOW;
	for (i = 0; i<6; i++)
	{
		gotoxy(64, 6 * num + i);
		puts(IceCream1[i]);
	}
}
void accumulate_of_Icecream()
{
	int i;
	side();
	for (i = 0; i<3; i++)
	{
		switch (rand() % 3)
		{
		case 0: Icecream_BLUE(i);
			break;
		case 1: Icecream_RED(i);
			break;
		case 2: Icecream_YELLOW(i);
			break;
		default:
			break;
		}
	}
	Icecream_down();
}
void Timer()
{
	int Time;
	for (Time = 100; Time >= 0; Time--)
	{
		Sleep(1000);
		gotoxy(2, 0);
		if (Time >= 100) printf("TIME %d", Time);
		else if (Time >= 10) printf("TIME %d ", Time);
		else if (Time >= 0) printf("TIME %d  ", Time);
		else printf("TIME 0  ");
	}
	return;
}
void Icecream_game()
{
	char input;
	int i;
	accumulate_of_Icecream();
	for (i = 2; i >= 0; i--)
	{
		while (1)
		{
			WHITE;
			gotoxy(3, 1);
			if (LIFE >= 10)printf("♥ %d", LIFE);
			else printf("♥ %d ", LIFE);
			gotoxy(3, 3);
			printf("SCORE");
			gotoxy(1, 4);
			printf("%7d ", SCORE);
			if (!LIFE) { gotoxy(0, 23); return; }
			input = getch();
			switch (input){
			case LEFT:
				if (Color[i] == 1) { Icecream1_RED(i); sign[i] = 1; SCORE += 300; }
				else { sign[i] = 0; --LIFE; }
				break;
			case RIGHT:
				if (Color[i] == 2) { Icecream1_BLUE(i); sign[i] = 1; SCORE += 300; }
				else { sign[i] = 0; --LIFE; }
				break;

			case DOWN:
				if (Color[i] == 3) { Icecream1_YELLOW(i); sign[i] = 1; SCORE += 300; }
				else { sign[i] = 0; --LIFE; }
				break;
			default:
				break;
			}
			input = 0;
			if (sign[i]) break;
		}
	}
	gotoxy(0, 23);
	if (LIFE)
	{
		if (sign[0] + sign[1] + sign[2] == 3)
		{
			sign[0] = sign[1] = sign[2] = 0;
			Icecream_game();
		}
	}
	else return;
}
int strcmp1(const char *a, const char *b, int c)           // 커스텀함수. 문자열에 같은 문자가 포함되어 있으면 0을 반환하고 아니면 1을 반환한다
{
	int i = 0, j = 0, h = 0;
	while (*(a + i) && *(b + j))
	{
		if (a[i] != b[j])
		{
			i++;
		}
		else
		{
			for (h = 0; h<c; h++)
			{
				if (a[i] == b[h] && b[h + 1] == 0)
				{
					return 0;
				}
				i++;
			}
		}
	}
	return 1;
}


void down11(int random, int qLength, int random2)           // 1초에 한칸씩 밑으로 내려주는 함수, random은 문제. qLength는 문제의 글자수, random2는 색깔
{
	int i, j, h, q;

	strcpy(a[21], "                              ");



	if (qLength == 0)                   //문제의 길이(즉 문제가 없을시) 가 0일시                     
	{


		if (life_p == 1)
		{
			//	LIFE--;
			life_p = 0;
		}


		for (i = 21; i >= 1; i--)                       // 첫째줄하고 마지막줄은 내려줄 필요가 없으니까 29부터 1까지
		{
			strcpy(a[i], a[i - 1]);                      // 아래로 내려주는 구문
			color[i] = color[i - 1];                     // 칼라역시 아래로 내려줌
		}
		strcpy(a[0], "                              ");      // 첫째줄을 바꿔준다. 문제가 없으니까 그냥 바꿔주면 됨


		if (strcmp(a[21], "                              ")) // 29번쨰줄까지 문제가 남아있다면
		{
			life_p = 1;																	// life_p를 1 늘려준다. 바로 라이프를 없애면 29번째줄에 당도했을때 없어지게됨
		}

		// 칼라를 입혀준다
	}

	else                                    //문제가 있을시에
	{

		j = 37 - qLength;                  // 앞공백과
		h = rand() % j + 1;                // 뒷공백을 정해준다 물론 랜덤으로.
		q = 37 - h - qLength;

		if (life_p == 1)                   // 역시 위에하고 똑같다. 라이프를 줄여주는구문

		{
			LIFE--;
			life_p = 0;
		}
		for (i = 21; i >= 1; i--)         // 위하고 똑같음
		{
			strcpy(a[i], a[i - 1]);
			color[i] = color[i - 1];
		}




		// 두번째줄에 문제를 넣어주는 구문. 
		strcpy(a[0], " ");
		for (i = 0; i<h - 1; i++)
		{
			strcat(a[0], " ");
		}
		strcat(a[0], question[random]);
		for (i = 0; i<q - 1; i++)
		{
			strcat(a[0], " ");
		}
		strcat(a[0], " ");

		if (strcmp(a[21], "                              "))
		{
			life_p = 1;
		}
	}
	color[0] = random2;
	return;
}
void xx()              // 스레드가 실행되면 가장먼저 실행되는 함수. 문제를 그줄에 출력할것인가 말것인가, 색깔은 어떻게 입힐것인가를 랜덤으로 정한 후 다음함수를 실행함
{
	int qLength;
	int random;
	int random2;
	random = rand() % 10;
	random2 = rand() % 3 + 1;
	if (random <= 4)
	{
		qLength = strlen(question[random]);
		down11(random, qLength, random2);
		return;
	}
	else
	{
		qLength = 0;
		down11(random, qLength, 0);
	}



	return;
}
unsigned __stdcall down(void *arg)         //처음으로 실행되는 스레드. xx()를 실행해 모든걸 셋팅해둔 뒤 출력하는것밖에 없다
{
	int i;
	while (1)
	{
		xx();

		for (i = 0; i<22; i++)
		{
			if (color[i] == 1)
			{
				BLUE;
				gotoxy(22, i);
				printf("%s\n", a[i]);
				WHITE;
			}
			else if (color[i] == 2)
			{
				RED;
				gotoxy(22, i);
				printf("%s\n", a[i]);
				WHITE;
			}
			else if (color[i] == 3)
			{
				YELLOW;
				gotoxy(22, i);
				printf("%s\n", a[i]);
				WHITE;
			}
			else;
		}
		Sleep(1000);
	}

}

unsigned __stdcall input(void *arg)           // 정답을 입력받는 스레드
{

	char n_key;
	int i, ls;
	int x = 24;

	while (1)
	{
		if (kbhit())                       //키보드에 키가 입력됬을시
		{      // n_key에 입력받은 값을 집어넣고
			n_key = getch();

			if (n_key == 8)
			{

				// 그게 백스페이스 일시에
				ip[strlen(ip) - 1] = '\0'; // 문자열 맨 뒷부분을 없애준다
			}
			else if (n_key == 13)          // n_key에 입력받은 값이 엔터 였을시
			{
				ls = strlen(ip);
				for (i = 21; i >= 0; i--)         //전체줄에 대하여 마지막줄부터 검증을 시작함
				{
					if (!strcmp1(a[i], ip, ls))      // 만약 그 줄에 문제의 답이 있을시
					{
						strcpy(a[i], "                              ");   // 싹 비워주고
						color[i] = 0;  // 칼라역시 흰색으로 바꿔준다
						break;
					}
				}
				for (i = 0; i<50; i++)       // 그리고  정답을 넣는 문자열을 싹 비워줌
					ip[i] = '\0';
				x = 24;
			}
			else
			{
				gotoxy(x++, 23);
				printf("%c", n_key);         // 내가 쓴 문자를 보여줌
				strncat(ip, &n_key, 1);     //  내가 쓴 문자를 문자열에 더해준다
			}
		}
	}

}
unsigned __stdcall Thread1(void *arg)
{
	Icecream_game(10, 0);
	exit(1);
}

unsigned __stdcall Thread2(void *arg)
{
	Timer();
	exit(1);
}

void Loading_f()
{

	int i;
	printf("\n\n\n\n\n\n");
	printf("                ★☆★☆★☆★☆기다려 주세요");
	for (i = 0; i<4; i++)
	{
		printf("☆★");
		Sleep(750);  			//0.75초
	}
	printf("\n\n\n");
	printf("                ★☆★☆★☆★☆기대해 주세요");
	for (i = 0; i<4; i++)
	{
		printf("☆★");
		Sleep(750); 			 //0.75초
	}
	printf("\n\n\n");

	for (i = 4; i>0; i--)
	{
		if (i == 4)
			ORIGINAL;
		if (i == 3)
			HIGH_GREEN;
		if (i == 2)
			YELLOW;
		if (i == 1)
			RED;
		printf("                   ★☆★☆★☆★☆ %d!! ☆★☆★☆★☆★\n", i);
		printf("\n\n");
		Sleep(750);  			//0.75초
	}
}


void Intro_Draw()
{

	char cheat = 0;
	int i;
	int j = 2;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");		//40줄 뛰기
	RED;																							//RED 
	printf("             ■                 ■                     ■                     ■"); 		//1번 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("             ■                 ■                     ■                     ■");
	printf("             ■                 ■                     ■                     ■");			//2번 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf(" ■      ■  ■                 ■  ■             ■  ■                     ■");
	printf("             ■                 ■                     ■                     ■");
	BLUE;																							//BLUE
	printf("             ■                 ■                     ■                     ■");			//3번 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("  ■    ■   ■       ■■■■■■   ■           ■   ■                     ■");
	printf(" ■      ■  ■                 ■  ■             ■  ■                     ■");
	BLUE;
	printf("             ■                 ■                     ■                     ■");
	printf("             ■                 ■                     ■                     ■");			//4번 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("   ■  ■    ■■■                   ■         ■    ■                     ■");
	printf("  ■    ■   ■       ■■■■■■   ■           ■   ■                     ■");
	BLUE;
	printf(" ■      ■  ■                 ■  ■             ■  ■                     ■");
	printf("             ■                 ■                     ■                     ■");
	YELLOW;																							//YELLOW
	printf("             ■                 ■                     ■                     ■");			//5번 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("    ■■     ■     ■■■■■■■■   ■       ■     ■     ■■■■■■■■■");
	printf("   ■  ■    ■■■                   ■         ■    ■                     ■");
	BLUE;
	printf("  ■    ■   ■       ■■■■■■   ■           ■   ■                     ■");
	printf(" ■      ■  ■                 ■  ■             ■  ■                     ■");
	YELLOW;
	printf("             ■                 ■                     ■                     ■");
	printf("             ■                 ■                     ■                     ■");			//6번 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("     ■      ■            ■           ■     ■      ■                       ");
	printf("    ■■     ■     ■■■■■■■■   ■       ■     ■     ■■■■■■■■■");
	BLUE;
	printf("   ■  ■    ■■■                   ■         ■    ■                     ■");
	printf("  ■    ■   ■       ■■■■■■   ■           ■   ■                     ■");
	YELLOW;
	printf(" ■      ■  ■                 ■  ■             ■  ■                     ■");
	printf("             ■                 ■                     ■                     ■");
	HIGH_GREEN;																						//HIGH_GREEN
	printf("             ■                 ■                     ■                     ■");			//7번 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("■■■■■■ ■            ■   ■       ■   ■       ■■■                   ");
	printf("     ■      ■            ■           ■     ■      ■                       ");
	BLUE;
	printf("    ■■     ■     ■■■■■■■■   ■       ■     ■     ■■■■■■■■■");
	printf("   ■  ■    ■■■                   ■         ■    ■                     ■");
	YELLOW;
	printf("  ■    ■   ■       ■■■■■■   ■           ■   ■                     ■");
	printf(" ■      ■  ■                 ■  ■             ■  ■                     ■");
	HIGH_GREEN;
	printf("             ■                 ■                     ■                     ■");
	printf("             ■                 ■                     ■                     ■");			//8번 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("             ■                 ■        ■ ■        ■     ■■■■■■■■■");
	printf("■■■■■■ ■            ■   ■       ■   ■       ■■■                   ");
	BLUE;
	printf("     ■      ■            ■           ■     ■      ■                       ");
	printf("    ■■     ■     ■■■■■■■■   ■       ■     ■     ■■■■■■■■■");
	YELLOW;
	printf("   ■  ■    ■■■                   ■         ■    ■                     ■");
	printf("  ■    ■   ■       ■■■■■■   ■           ■   ■                     ■");
	HIGH_GREEN;
	printf(" ■      ■  ■                 ■  ■             ■  ■                     ■");
	printf("             ■                 ■                     ■                     ■");
	RED;																							//RED
	printf("             ■                 ■                     ■                     ■");			//9번 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("   ■■■                       ■         ■■        ■             ■        ");
	printf("             ■                 ■        ■ ■        ■     ■■■■■■■■■");
	BLUE;
	printf("■■■■■■ ■            ■   ■       ■   ■       ■■■                   ");
	printf("     ■      ■            ■           ■     ■      ■                       ");
	YELLOW;
	printf("    ■■     ■     ■■■■■■■■   ■       ■     ■     ■■■■■■■■■");
	printf("   ■  ■    ■■■                   ■         ■    ■                     ■");
	HIGH_GREEN;
	printf("  ■    ■   ■       ■■■■■■   ■           ■   ■                     ■");
	printf(" ■      ■  ■                 ■  ■             ■  ■                     ■");
	RED;
	printf("             ■                 ■                     ■                     ■");
	printf("             ■                 ■                     ■                     ■");			//10번 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("                      ■■■■■■  ■■■■■■■■   ■             ■      ■");
	printf("   ■■■                       ■         ■■        ■             ■        ");
	BLUE;
	printf("             ■                 ■        ■ ■        ■     ■■■■■■■■■");
	printf("■■■■■■ ■            ■   ■       ■   ■       ■■■                   ");
	YELLOW;
	printf("     ■      ■            ■           ■     ■      ■                       ");
	printf("    ■■     ■     ■■■■■■■■   ■       ■     ■     ■■■■■■■■■");
	HIGH_GREEN;
	printf("   ■  ■    ■■■                   ■         ■    ■                     ■");
	printf("  ■    ■   ■       ■■■■■■   ■           ■   ■                     ■");
	RED;
	printf(" ■      ■  ■                 ■  ■             ■  ■                     ■");
	printf("             ■                 ■                     ■                     ■");
	BLUE;																							//BLUE
	printf("             ■                 ■                     ■                     ■");			//11번 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("                                                       ■                     ■");
	printf("                      ■■■■■■  ■■■■■■■■   ■             ■      ■");
	BLUE;
	printf("   ■■■                       ■         ■■        ■             ■        ");
	printf("             ■                 ■        ■ ■        ■     ■■■■■■■■■");
	YELLOW;
	printf("■■■■■■ ■            ■   ■       ■   ■       ■■■                   ");
	printf("     ■      ■            ■           ■     ■      ■                       ");
	HIGH_GREEN;
	printf("    ■■     ■     ■■■■■■■■   ■       ■     ■     ■■■■■■■■■");
	printf("   ■  ■    ■■■                   ■         ■    ■                     ■");
	RED;
	printf("  ■    ■   ■       ■■■■■■   ■           ■   ■                     ■");
	printf(" ■      ■  ■                 ■  ■             ■  ■                     ■");
	BLUE;
	printf("             ■                 ■                     ■                     ■");
	printf("             ■                 ■                     ■                     ■");			//12번 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("                                        ■■■■                              ■");
	printf("                                                       ■                     ■");
	BLUE;
	printf("                      ■■■■■■  ■■■■■■■■   ■             ■      ■");
	printf("   ■■■                       ■         ■■        ■             ■        ");
	YELLOW;
	printf("             ■                 ■        ■ ■        ■     ■■■■■■■■■");
	printf("■■■■■■ ■            ■   ■       ■   ■       ■■■                   ");
	HIGH_GREEN;
	printf("     ■      ■            ■           ■     ■      ■                       ");
	printf("    ■■     ■     ■■■■■■■■   ■       ■     ■     ■■■■■■■■■");
	RED;
	printf("   ■  ■    ■■■                   ■         ■    ■                     ■");
	printf("  ■    ■   ■       ■■■■■■   ■           ■   ■                     ■");
	BLUE;
	printf(" ■      ■  ■                 ■  ■             ■  ■                     ■");
	printf("             ■                 ■                     ■                     ■");
	YELLOW;																							//YELLOW
	printf("             ■                 ■                     ■                     ■");			//13번 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("                                                                              ■");
	printf("                                        ■■■■                              ■");
	BLUE;
	printf("                                                       ■                     ■");
	printf("                      ■■■■■■  ■■■■■■■■   ■             ■      ■");
	YELLOW;
	printf("   ■■■                       ■         ■■        ■             ■        ");
	printf("             ■                 ■        ■ ■        ■     ■■■■■■■■■");
	HIGH_GREEN;
	printf("■■■■■■ ■            ■   ■       ■   ■       ■■■                   ");
	printf("     ■      ■            ■           ■     ■      ■                       ");
	RED;
	printf("    ■■     ■     ■■■■■■■■   ■       ■     ■     ■■■■■■■■■");
	printf("   ■  ■    ■■■                   ■         ■    ■                     ■");
	BLUE;
	printf("  ■    ■   ■       ■■■■■■   ■           ■   ■                     ■");
	printf(" ■      ■  ■                 ■  ■             ■  ■                     ■");
	YELLOW;
	printf("             ■                 ■                     ■                     ■");
	printf("             ■                 ■                     ■                     ■");			//14번 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("                                                              ■■■■■■■■■");
	printf("                                                                              ■");
	BLUE;
	printf("                                        ■■■■                              ■");
	printf("                                                       ■                     ■");
	YELLOW;
	printf("                      ■■■■■■  ■■■■■■■■   ■             ■      ■");
	printf("   ■■■                       ■         ■■        ■             ■        ");
	HIGH_GREEN;
	printf("             ■                 ■        ■ ■        ■     ■■■■■■■■■");
	printf("■■■■■■ ■            ■   ■       ■   ■       ■■■                   ");
	RED;
	printf("     ■      ■            ■           ■     ■      ■                       ");
	printf("    ■■     ■     ■■■■■■■■   ■       ■     ■     ■■■■■■■■■");
	BLUE;
	printf("   ■  ■    ■■■                   ■         ■    ■                     ■");
	printf("  ■    ■   ■       ■■■■■■   ■           ■   ■                     ■");
	YELLOW;
	printf(" ■      ■  ■                 ■  ■             ■  ■                     ■");
	printf("             ■                 ■                     ■                     ■");
	GREEN;																							//GREEN
	printf("             ■                 ■                     ■                     ■");			//15번 
	Sleep(wait);


	printf("\n");			//8줄 띄기(천장맞춤) 
	Sleep(wait);
	printf("\n");
	Sleep(wait);
	printf("\n");
	Sleep(wait);
	printf("\n");
	Sleep(wait);
	printf("\n");
	Sleep(wait);
	printf("\n");
	Sleep(wait);
	printf("\n");
	Sleep(wait);
	SKY_BLUE;
	printf("                ★☆★☆★☆★☆기다려 주세요...★☆★☆★☆★☆\n");
	Sleep(2000);
	ORIGINAL;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	for (i = 1; i<19; i++)																					//깜빡거리기 (2번 아래에서 위로) 
	{
		printf("\n\n\n\n\n\n\n\n\n\n");
		if (j - 9 == 0)
		{
			BLACK;
			j++;
		}
		else RED;
		printf("                                                              ■■■■■■■■■");
		printf("                                                                              ■");
		if (j - 8 == 0)
		{
			BLACK;
			j++;
		}
		else BLUE;
		printf("                                        ■■■■                              ■");
		printf("                                                       ■                     ■");
		if (j - 7 == 0)
		{
			BLACK;
			j++;
		}
		else YELLOW;
		printf("                      ■■■■■■  ■■■■■■■■   ■             ■      ■");
		printf("   ■■■                       ■         ■■        ■             ■        ");
		if (j - 6 == 0)
		{
			BLACK;
			j++;
		}
		else HIGH_GREEN;
		printf("             ■                 ■        ■ ■        ■     ■■■■■■■■■");
		printf("■■■■■■ ■            ■   ■       ■   ■       ■■■                   ");
		if (j - 5 == 0)
		{
			BLACK;
			j++;
		}
		else { RED };
		printf("     ■      ■            ■           ■     ■      ■                       ");
		printf("    ■■     ■     ■■■■■■■■   ■       ■     ■     ■■■■■■■■■");
		if (j - 4 == 0)
		{
			BLACK;
			j++;
		}
		else { BLUE };
		printf("   ■  ■    ■■■                   ■         ■    ■                     ■");
		printf("  ■    ■   ■       ■■■■■■   ■           ■   ■                     ■");
		if (j - 3 == 0)
		{
			BLACK;
			j++;
		}
		else
		{
			YELLOW
		};
		printf(" ■      ■  ■                 ■  ■             ■  ■                     ■");
		printf("             ■                 ■                     ■                     ■");
		if (j - 2 == 0)
		{
			BLACK;
			j++;
		}
		else
		{
			GREEN
		};
		printf("             ■                 ■                     ■                     ■");
		SKY_BLUE;
		printf("\n\n\n\n\n\n\n                ★☆★☆★☆★☆기다려 주세요...★☆★☆★☆★☆\n");
		if (j == 1)
		{
			j = 2;
		}
		if (j == 10)
		{
			j = 1;
		}
		Sleep(bling);
	}

	printf("             ★☆★☆★☆★☆아무 키나 눌러서 시작!★☆★☆★☆★☆\n");				//Draw 함수 종료지점 
	while (1)
	{
		cheat = getch(stdin);
		if (cheat)
			break;
	}

}
/*
gets(cheat);

if(cheat==101)
return 1;

else if(cheat==8)
return 2;

else if(cheat==00)
return 3;

else
return 0;
*/




int Intro_Selete(int Cheat_Code)
{
	while (1)
	{
		int Selete_num;
		int i;

		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		RED;
		printf("                                                              ■■■■■■■■■");
		printf("                                                                              ■");
		BLUE;
		printf("                                        ■■■■                              ■");
		printf("                                                       ■                     ■");
		YELLOW;
		printf("                      ■■■■■■  ■■■■■■■■   ■             ■      ■");
		printf("   ■■■                       ■         ■■        ■             ■        ");
		HIGH_GREEN;
		printf("             ■                 ■        ■ ■        ■     ■■■■■■■■■");
		printf("■■■■■■ ■            ■   ■       ■   ■       ■■■                   ");
		RED;
		printf("     ■      ■            ■           ■     ■      ■                       ");
		printf("    ■■     ■     ■■■■■■■■   ■       ■     ■     ■■■■■■■■■");
		BLUE;
		printf("   ■  ■    ■■■                   ■         ■    ■                     ■");
		printf("  ■    ■   ■       ■■■■■■   ■           ■   ■                     ■");
		YELLOW;
		printf(" ■      ■  ■                 ■  ■             ■  ■                     ■");
		printf("             ■                 ■                     ■                     ■");
		GREEN;
		printf("             ■                 ■                     ■                     ■");


		SKY_BLUE;
		printf("\n\n             ▶▶▶▶▶▶▶▶▶▶▶Main Menu◀◀◀◀◀◀◀◀◀◀◀◀");
		GOLD;
		printf("\n\n                                1. Game start");
		HIGH_GREEN;
		printf("\n\n                               2. How to play??");
		PURPLE;
		printf("\n\n                                3. exit game");
		ORIGINAL;
		printf("\n");
		scanf_s("%d", &Selete_num);

		if (Selete_num == 1)
		{
			PlaySound(TEXT("Yammi.wav"), NULL, SND_ASYNC | SND_LOOP | SND_NODEFAULT);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("\n\n            ▶▶▶▶▶▶▶▶▶▶▶Game start!!◀◀◀◀◀◀◀◀◀◀◀◀\n\n");
			for (i = 5; i > 0; i--)
			{
				if (i == 3)
					ORIGINAL;
				if (i == 2)
					YELLOW;
				if (i == 1)
					RED;
				printf("\n\n            ▶▶▶▶▶▶▶▶▶▶▶.....%d......◀◀◀◀◀◀◀◀◀◀◀◀", i);
				printf("\n\n");
				Sleep(1000);  			//1.0초
				
			}
			system("cls");
			return 0;
		}

		else if (Selete_num == 2)
		{
			printf("\n\n            ▶▶▶▶▶▶▶▶▶▶▶게임 설명.◀◀◀◀◀◀◀◀◀◀◀◀\n\n");
			printf("\n\n                    ▶각기 다른 색의 단어들이 내려옵니다◀");
			printf("\n\n                    ▶옆의 아이스크림에 쌓인 색 순서대로◀");
			printf("\n\n                  ▶단어를 입력해서 아이스크림을 쌓으세요!◀");
			printf("\n\n                 ▶단어가 지정된 갯수 이상 바닥에 떨어지거나◀");
			printf("\n\n                          ▶타임오버되면 게임오버!◀");
			printf("\n\n                    ▶아무 키나 누르시면 돌아갑니다...◀");
			while (1)
			{
				Selete_num = getch(stdin);
				if (Selete_num)
				{
					Selete_num = 1;
					break;
				}
			}

		}

		else if (Selete_num == 3)
		{
			printf("\n\n        ▶▶▶▶▶▶▶▶▶▶▶게임을 종료합니다.◀◀◀◀◀◀◀◀◀◀◀◀\n\n");
			return 0;
		}
	}





	return 0;

}


int main()
{
	system("mode con:cols=80 lines=30");
	int cheat = 0, game_selete;
	PlaySound(TEXT("Silver Scrapes.wav"), NULL, SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	Loading_f();

	Intro_Draw();

	game_selete = Intro_Selete(cheat);
	ORIGINAL;


	srand((unsigned)time(NULL));
	_beginthreadex(NULL, 0, down, 0, 0, NULL);
	_beginthreadex(NULL, 0, input, 0, 0, NULL);
	_beginthreadex(NULL, 0, Thread1, 0, 0, NULL);
	_beginthreadex(NULL, 0, Thread2, 0, 0, NULL);
	while (1)
	{
		if (LIFE == 0)		 // 라이프가 0일시 끝남
			break;
	}
	return 0;
}


