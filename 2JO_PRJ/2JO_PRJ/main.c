#include <Windows.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include<MMsystem.h>
#include<process.h>
#pragma comment(lib,"winmm.lib") 

#define COL                   GetStdHandle(STD_OUTPUT_HANDLE)        // �ܼ�â�� �ڵ����� �ޱ�

#define BLACK                SetConsoleTextAttribute(COL, 0x0000);        // ������
#define DARK_BLUE         SetConsoleTextAttribute(COL, 0x0001);        // �Ķ���
#define GREEN                SetConsoleTextAttribute(COL, 0x0002);        // ���
#define BLUE_GREEN        SetConsoleTextAttribute(COL, 0x0003);        // û���
#define BLOOD               SetConsoleTextAttribute(COL, 0x0004);        // �˺�����
#define PURPLE               SetConsoleTextAttribute(COL, 0x0005);        // �����
#define GOLD                 SetConsoleTextAttribute(COL, 0x0006);        // �ݻ�
#define ORIGINAL            SetConsoleTextAttribute(COL, 0x0007);        // ���� ȸ�� (ORIGINAL CONSOLE COLOR)
#define GRAY                 SetConsoleTextAttribute(COL, 0x0008);        // ȸ��
#define BLUE                  SetConsoleTextAttribute(COL, 0x0009);        // �Ķ���
#define HIGH_GREEN       SetConsoleTextAttribute(COL, 0x000a);        // ���λ�
#define SKY_BLUE           SetConsoleTextAttribute(COL, 0x000b);        // �ϴû�
#define RED                   SetConsoleTextAttribute(COL, 0x000c);        // ������
#define PLUM                SetConsoleTextAttribute(COL, 0x000d);        // ���ֻ�
#define YELLOW             SetConsoleTextAttribute(COL, 0x000e);        // �����
#define WHITE                SetConsoleTextAttribute(COL, 0x000f);        // ���

#define LEFT   75      // ��������Ű
#define RIGHT  77      // ��������Ű
#define DOWN   80      // �Ʒ�����


#define wait 300		//0.3�� 
#define bling 490		//0.49��

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
char question[5][10] = { "printf", "scanf", "while", "for", "system" };  // ����, �� �߰��� �� ����
char a[22][45] = {
	"                           ",                    // ȭ�鿡 ��µ� ���ڿ���. �̰��� ������ ���� ��µȴ�
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
int color[22] = { 0 };                                   // ���� ����. 
char ip[50];                               // �Է¹��� ����
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
		gotoxy(11, i); printf("��");
		gotoxy(61, i); printf("��");
	}
	gotoxy(11, 22); printf("��������������������������");

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
			if (LIFE >= 10)printf("�� %d", LIFE);
			else printf("�� %d ", LIFE);
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
int strcmp1(const char *a, const char *b, int c)           // Ŀ�����Լ�. ���ڿ��� ���� ���ڰ� ���ԵǾ� ������ 0�� ��ȯ�ϰ� �ƴϸ� 1�� ��ȯ�Ѵ�
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


void down11(int random, int qLength, int random2)           // 1�ʿ� ��ĭ�� ������ �����ִ� �Լ�, random�� ����. qLength�� ������ ���ڼ�, random2�� ����
{
	int i, j, h, q;

	strcpy(a[21], "                              ");



	if (qLength == 0)                   //������ ����(�� ������ ������) �� 0�Ͻ�                     
	{


		if (life_p == 1)
		{
			//	LIFE--;
			life_p = 0;
		}


		for (i = 21; i >= 1; i--)                       // ù°���ϰ� ���������� ������ �ʿ䰡 �����ϱ� 29���� 1����
		{
			strcpy(a[i], a[i - 1]);                      // �Ʒ��� �����ִ� ����
			color[i] = color[i - 1];                     // Į�󿪽� �Ʒ��� ������
		}
		strcpy(a[0], "                              ");      // ù°���� �ٲ��ش�. ������ �����ϱ� �׳� �ٲ��ָ� ��


		if (strcmp(a[21], "                              ")) // 29�����ٱ��� ������ �����ִٸ�
		{
			life_p = 1;																	// life_p�� 1 �÷��ش�. �ٷ� �������� ���ָ� 29��°�ٿ� �絵������ �������Ե�
		}

		// Į�� �����ش�
	}

	else                                    //������ �����ÿ�
	{

		j = 37 - qLength;                  // �հ����
		h = rand() % j + 1;                // �ް����� �����ش� ���� ��������.
		q = 37 - h - qLength;

		if (life_p == 1)                   // ���� �����ϰ� �Ȱ���. �������� �ٿ��ִ±���

		{
			LIFE--;
			life_p = 0;
		}
		for (i = 21; i >= 1; i--)         // ���ϰ� �Ȱ���
		{
			strcpy(a[i], a[i - 1]);
			color[i] = color[i - 1];
		}




		// �ι�°�ٿ� ������ �־��ִ� ����. 
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
void xx()              // �����尡 ����Ǹ� ������� ����Ǵ� �Լ�. ������ ���ٿ� ����Ұ��ΰ� �����ΰ�, ������ ��� �������ΰ��� �������� ���� �� �����Լ��� ������
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
unsigned __stdcall down(void *arg)         //ó������ ����Ǵ� ������. xx()�� ������ ���� �����ص� �� ����ϴ°͹ۿ� ����
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

unsigned __stdcall input(void *arg)           // ������ �Է¹޴� ������
{

	char n_key;
	int i, ls;
	int x = 24;

	while (1)
	{
		if (kbhit())                       //Ű���忡 Ű�� �Է�����
		{      // n_key�� �Է¹��� ���� ����ְ�
			n_key = getch();

			if (n_key == 8)
			{

				// �װ� �齺���̽� �Ͻÿ�
				ip[strlen(ip) - 1] = '\0'; // ���ڿ� �� �޺κ��� �����ش�
			}
			else if (n_key == 13)          // n_key�� �Է¹��� ���� ���� ������
			{
				ls = strlen(ip);
				for (i = 21; i >= 0; i--)         //��ü�ٿ� ���Ͽ� �������ٺ��� ������ ������
				{
					if (!strcmp1(a[i], ip, ls))      // ���� �� �ٿ� ������ ���� ������
					{
						strcpy(a[i], "                              ");   // �� ����ְ�
						color[i] = 0;  // Į�󿪽� ������� �ٲ��ش�
						break;
					}
				}
				for (i = 0; i<50; i++)       // �׸���  ������ �ִ� ���ڿ��� �� �����
					ip[i] = '\0';
				x = 24;
			}
			else
			{
				gotoxy(x++, 23);
				printf("%c", n_key);         // ���� �� ���ڸ� ������
				strncat(ip, &n_key, 1);     //  ���� �� ���ڸ� ���ڿ��� �����ش�
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
	printf("                �ڡ١ڡ١ڡ١ڡٱ�ٷ� �ּ���");
	for (i = 0; i<4; i++)
	{
		printf("�١�");
		Sleep(750);  			//0.75��
	}
	printf("\n\n\n");
	printf("                �ڡ١ڡ١ڡ١ڡٱ���� �ּ���");
	for (i = 0; i<4; i++)
	{
		printf("�١�");
		Sleep(750); 			 //0.75��
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
		printf("                   �ڡ١ڡ١ڡ١ڡ� %d!! �١ڡ١ڡ١ڡ١�\n", i);
		printf("\n\n");
		Sleep(750);  			//0.75��
	}
}


void Intro_Draw()
{

	char cheat = 0;
	int i;
	int j = 2;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");		//40�� �ٱ�
	RED;																							//RED 
	printf("             ��                 ��                     ��                     ��"); 		//1�� 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("             ��                 ��                     ��                     ��");
	printf("             ��                 ��                     ��                     ��");			//2�� 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf(" ��      ��  ��                 ��  ��             ��  ��                     ��");
	printf("             ��                 ��                     ��                     ��");
	BLUE;																							//BLUE
	printf("             ��                 ��                     ��                     ��");			//3�� 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("  ��    ��   ��       �������   ��           ��   ��                     ��");
	printf(" ��      ��  ��                 ��  ��             ��  ��                     ��");
	BLUE;
	printf("             ��                 ��                     ��                     ��");
	printf("             ��                 ��                     ��                     ��");			//4�� 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("   ��  ��    ����                   ��         ��    ��                     ��");
	printf("  ��    ��   ��       �������   ��           ��   ��                     ��");
	BLUE;
	printf(" ��      ��  ��                 ��  ��             ��  ��                     ��");
	printf("             ��                 ��                     ��                     ��");
	YELLOW;																							//YELLOW
	printf("             ��                 ��                     ��                     ��");			//5�� 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("    ���     ��     ���������   ��       ��     ��     ����������");
	printf("   ��  ��    ����                   ��         ��    ��                     ��");
	BLUE;
	printf("  ��    ��   ��       �������   ��           ��   ��                     ��");
	printf(" ��      ��  ��                 ��  ��             ��  ��                     ��");
	YELLOW;
	printf("             ��                 ��                     ��                     ��");
	printf("             ��                 ��                     ��                     ��");			//6�� 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("     ��      ��            ��           ��     ��      ��                       ");
	printf("    ���     ��     ���������   ��       ��     ��     ����������");
	BLUE;
	printf("   ��  ��    ����                   ��         ��    ��                     ��");
	printf("  ��    ��   ��       �������   ��           ��   ��                     ��");
	YELLOW;
	printf(" ��      ��  ��                 ��  ��             ��  ��                     ��");
	printf("             ��                 ��                     ��                     ��");
	HIGH_GREEN;																						//HIGH_GREEN
	printf("             ��                 ��                     ��                     ��");			//7�� 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("������� ��            ��   ��       ��   ��       ����                   ");
	printf("     ��      ��            ��           ��     ��      ��                       ");
	BLUE;
	printf("    ���     ��     ���������   ��       ��     ��     ����������");
	printf("   ��  ��    ����                   ��         ��    ��                     ��");
	YELLOW;
	printf("  ��    ��   ��       �������   ��           ��   ��                     ��");
	printf(" ��      ��  ��                 ��  ��             ��  ��                     ��");
	HIGH_GREEN;
	printf("             ��                 ��                     ��                     ��");
	printf("             ��                 ��                     ��                     ��");			//8�� 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("             ��                 ��        �� ��        ��     ����������");
	printf("������� ��            ��   ��       ��   ��       ����                   ");
	BLUE;
	printf("     ��      ��            ��           ��     ��      ��                       ");
	printf("    ���     ��     ���������   ��       ��     ��     ����������");
	YELLOW;
	printf("   ��  ��    ����                   ��         ��    ��                     ��");
	printf("  ��    ��   ��       �������   ��           ��   ��                     ��");
	HIGH_GREEN;
	printf(" ��      ��  ��                 ��  ��             ��  ��                     ��");
	printf("             ��                 ��                     ��                     ��");
	RED;																							//RED
	printf("             ��                 ��                     ��                     ��");			//9�� 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("   ����                       ��         ���        ��             ��        ");
	printf("             ��                 ��        �� ��        ��     ����������");
	BLUE;
	printf("������� ��            ��   ��       ��   ��       ����                   ");
	printf("     ��      ��            ��           ��     ��      ��                       ");
	YELLOW;
	printf("    ���     ��     ���������   ��       ��     ��     ����������");
	printf("   ��  ��    ����                   ��         ��    ��                     ��");
	HIGH_GREEN;
	printf("  ��    ��   ��       �������   ��           ��   ��                     ��");
	printf(" ��      ��  ��                 ��  ��             ��  ��                     ��");
	RED;
	printf("             ��                 ��                     ��                     ��");
	printf("             ��                 ��                     ��                     ��");			//10�� 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("                      �������  ���������   ��             ��      ��");
	printf("   ����                       ��         ���        ��             ��        ");
	BLUE;
	printf("             ��                 ��        �� ��        ��     ����������");
	printf("������� ��            ��   ��       ��   ��       ����                   ");
	YELLOW;
	printf("     ��      ��            ��           ��     ��      ��                       ");
	printf("    ���     ��     ���������   ��       ��     ��     ����������");
	HIGH_GREEN;
	printf("   ��  ��    ����                   ��         ��    ��                     ��");
	printf("  ��    ��   ��       �������   ��           ��   ��                     ��");
	RED;
	printf(" ��      ��  ��                 ��  ��             ��  ��                     ��");
	printf("             ��                 ��                     ��                     ��");
	BLUE;																							//BLUE
	printf("             ��                 ��                     ��                     ��");			//11�� 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("                                                       ��                     ��");
	printf("                      �������  ���������   ��             ��      ��");
	BLUE;
	printf("   ����                       ��         ���        ��             ��        ");
	printf("             ��                 ��        �� ��        ��     ����������");
	YELLOW;
	printf("������� ��            ��   ��       ��   ��       ����                   ");
	printf("     ��      ��            ��           ��     ��      ��                       ");
	HIGH_GREEN;
	printf("    ���     ��     ���������   ��       ��     ��     ����������");
	printf("   ��  ��    ����                   ��         ��    ��                     ��");
	RED;
	printf("  ��    ��   ��       �������   ��           ��   ��                     ��");
	printf(" ��      ��  ��                 ��  ��             ��  ��                     ��");
	BLUE;
	printf("             ��                 ��                     ��                     ��");
	printf("             ��                 ��                     ��                     ��");			//12�� 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("                                        �����                              ��");
	printf("                                                       ��                     ��");
	BLUE;
	printf("                      �������  ���������   ��             ��      ��");
	printf("   ����                       ��         ���        ��             ��        ");
	YELLOW;
	printf("             ��                 ��        �� ��        ��     ����������");
	printf("������� ��            ��   ��       ��   ��       ����                   ");
	HIGH_GREEN;
	printf("     ��      ��            ��           ��     ��      ��                       ");
	printf("    ���     ��     ���������   ��       ��     ��     ����������");
	RED;
	printf("   ��  ��    ����                   ��         ��    ��                     ��");
	printf("  ��    ��   ��       �������   ��           ��   ��                     ��");
	BLUE;
	printf(" ��      ��  ��                 ��  ��             ��  ��                     ��");
	printf("             ��                 ��                     ��                     ��");
	YELLOW;																							//YELLOW
	printf("             ��                 ��                     ��                     ��");			//13�� 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("                                                                              ��");
	printf("                                        �����                              ��");
	BLUE;
	printf("                                                       ��                     ��");
	printf("                      �������  ���������   ��             ��      ��");
	YELLOW;
	printf("   ����                       ��         ���        ��             ��        ");
	printf("             ��                 ��        �� ��        ��     ����������");
	HIGH_GREEN;
	printf("������� ��            ��   ��       ��   ��       ����                   ");
	printf("     ��      ��            ��           ��     ��      ��                       ");
	RED;
	printf("    ���     ��     ���������   ��       ��     ��     ����������");
	printf("   ��  ��    ����                   ��         ��    ��                     ��");
	BLUE;
	printf("  ��    ��   ��       �������   ��           ��   ��                     ��");
	printf(" ��      ��  ��                 ��  ��             ��  ��                     ��");
	YELLOW;
	printf("             ��                 ��                     ��                     ��");
	printf("             ��                 ��                     ��                     ��");			//14�� 
	Sleep(wait);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	RED;
	printf("                                                              ����������");
	printf("                                                                              ��");
	BLUE;
	printf("                                        �����                              ��");
	printf("                                                       ��                     ��");
	YELLOW;
	printf("                      �������  ���������   ��             ��      ��");
	printf("   ����                       ��         ���        ��             ��        ");
	HIGH_GREEN;
	printf("             ��                 ��        �� ��        ��     ����������");
	printf("������� ��            ��   ��       ��   ��       ����                   ");
	RED;
	printf("     ��      ��            ��           ��     ��      ��                       ");
	printf("    ���     ��     ���������   ��       ��     ��     ����������");
	BLUE;
	printf("   ��  ��    ����                   ��         ��    ��                     ��");
	printf("  ��    ��   ��       �������   ��           ��   ��                     ��");
	YELLOW;
	printf(" ��      ��  ��                 ��  ��             ��  ��                     ��");
	printf("             ��                 ��                     ��                     ��");
	GREEN;																							//GREEN
	printf("             ��                 ��                     ��                     ��");			//15�� 
	Sleep(wait);


	printf("\n");			//8�� ���(õ�����) 
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
	printf("                �ڡ١ڡ١ڡ١ڡٱ�ٷ� �ּ���...�ڡ١ڡ١ڡ١ڡ�\n");
	Sleep(2000);
	ORIGINAL;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	for (i = 1; i<19; i++)																					//�����Ÿ��� (2�� �Ʒ����� ����) 
	{
		printf("\n\n\n\n\n\n\n\n\n\n");
		if (j - 9 == 0)
		{
			BLACK;
			j++;
		}
		else RED;
		printf("                                                              ����������");
		printf("                                                                              ��");
		if (j - 8 == 0)
		{
			BLACK;
			j++;
		}
		else BLUE;
		printf("                                        �����                              ��");
		printf("                                                       ��                     ��");
		if (j - 7 == 0)
		{
			BLACK;
			j++;
		}
		else YELLOW;
		printf("                      �������  ���������   ��             ��      ��");
		printf("   ����                       ��         ���        ��             ��        ");
		if (j - 6 == 0)
		{
			BLACK;
			j++;
		}
		else HIGH_GREEN;
		printf("             ��                 ��        �� ��        ��     ����������");
		printf("������� ��            ��   ��       ��   ��       ����                   ");
		if (j - 5 == 0)
		{
			BLACK;
			j++;
		}
		else { RED };
		printf("     ��      ��            ��           ��     ��      ��                       ");
		printf("    ���     ��     ���������   ��       ��     ��     ����������");
		if (j - 4 == 0)
		{
			BLACK;
			j++;
		}
		else { BLUE };
		printf("   ��  ��    ����                   ��         ��    ��                     ��");
		printf("  ��    ��   ��       �������   ��           ��   ��                     ��");
		if (j - 3 == 0)
		{
			BLACK;
			j++;
		}
		else
		{
			YELLOW
		};
		printf(" ��      ��  ��                 ��  ��             ��  ��                     ��");
		printf("             ��                 ��                     ��                     ��");
		if (j - 2 == 0)
		{
			BLACK;
			j++;
		}
		else
		{
			GREEN
		};
		printf("             ��                 ��                     ��                     ��");
		SKY_BLUE;
		printf("\n\n\n\n\n\n\n                �ڡ١ڡ١ڡ١ڡٱ�ٷ� �ּ���...�ڡ١ڡ١ڡ١ڡ�\n");
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

	printf("             �ڡ١ڡ١ڡ١ڡپƹ� Ű�� ������ ����!�ڡ١ڡ١ڡ١ڡ�\n");				//Draw �Լ� �������� 
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
		printf("                                                              ����������");
		printf("                                                                              ��");
		BLUE;
		printf("                                        �����                              ��");
		printf("                                                       ��                     ��");
		YELLOW;
		printf("                      �������  ���������   ��             ��      ��");
		printf("   ����                       ��         ���        ��             ��        ");
		HIGH_GREEN;
		printf("             ��                 ��        �� ��        ��     ����������");
		printf("������� ��            ��   ��       ��   ��       ����                   ");
		RED;
		printf("     ��      ��            ��           ��     ��      ��                       ");
		printf("    ���     ��     ���������   ��       ��     ��     ����������");
		BLUE;
		printf("   ��  ��    ����                   ��         ��    ��                     ��");
		printf("  ��    ��   ��       �������   ��           ��   ��                     ��");
		YELLOW;
		printf(" ��      ��  ��                 ��  ��             ��  ��                     ��");
		printf("             ��                 ��                     ��                     ��");
		GREEN;
		printf("             ��                 ��                     ��                     ��");


		SKY_BLUE;
		printf("\n\n             ����������������������Main Menu������������������������");
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
			printf("\n\n            ����������������������Game start!!������������������������\n\n");
			for (i = 5; i > 0; i--)
			{
				if (i == 3)
					ORIGINAL;
				if (i == 2)
					YELLOW;
				if (i == 1)
					RED;
				printf("\n\n            ����������������������.....%d......������������������������", i);
				printf("\n\n");
				Sleep(1000);  			//1.0��
				
			}
			system("cls");
			return 0;
		}

		else if (Selete_num == 2)
		{
			printf("\n\n            �������������������������� ����.������������������������\n\n");
			printf("\n\n                    ������ �ٸ� ���� �ܾ���� �����ɴϴ٢�");
			printf("\n\n                    ������ ���̽�ũ���� ���� �� ������΢�");
			printf("\n\n                  ���ܾ �Է��ؼ� ���̽�ũ���� ��������!��");
			printf("\n\n                 ���ܾ ������ ���� �̻� �ٴڿ� �������ų���");
			printf("\n\n                          ��Ÿ�ӿ����Ǹ� ���ӿ���!��");
			printf("\n\n                    ���ƹ� Ű�� �����ø� ���ư��ϴ�...��");
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
			printf("\n\n        ���������������������������� �����մϴ�.������������������������\n\n");
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
		if (LIFE == 0)		 // �������� 0�Ͻ� ����
			break;
	}
	return 0;
}


