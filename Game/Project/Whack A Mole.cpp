#define _CRT_SECURE_NO_WARNINGS
#include <easyx.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
using namespace std;

class Game //遊戲
{
public:	
	Game() :r(0), s(0) {}
	int holex[8] = { 50 ,80,535,300,1030,785,535,1000 };
	int holey[8] = { 180 ,475,160,330,180,350,480,480 };
	int r = 0, s = 0,count=0;

	void hammer(int x,int y) {
		setfillcolor(GREEN);
		setlinecolor(BLACK);
		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 3);
		fillroundrect(x + 60, y - 10, x + 90, y + 150, 10, 20);
		setfillcolor(BROWN);
		setlinecolor(BLACK);
		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 3);
		fillroundrect(x + 30, y, x + 150, y - 80, 10, 20);
		fillellipse(x + 5, y, x + 55, y - 80);
		solidrectangle(x + 31, y - 2, x + 150, y - 78);
		fillellipse(x + 100, y, x + 170, y - 80);
	}
	void randon()
	{
		srand(time(0));
		r = (rand() % 10000) % 8;
		s = (rand() % 6000) % 6;
	}
	void normal() {
		IMAGE mouseimg;
		loadimage(&mouseimg, _T("D:\\gameimg\\test.png"), 220, 200);
		IMAGE Do;
		loadimage(&Do, _T("D:\\gameimg\\Do.png"), 220, 200);
		IMAGE Re;
		loadimage(&Re, _T("D:\\gameimg\\Re.png"), 220, 200);
		IMAGE Mi;
		loadimage(&Mi, _T("D:\\gameimg\\Mi.png"), 220, 200);
		IMAGE Fa;
		loadimage(&Fa, _T("D:\\gameimg\\Fa.png"), 220, 200);
		IMAGE Sol;
		loadimage(&Sol, _T("D:\\gameimg\\Sol.png"), 220, 200);
		IMAGE La;
		loadimage(&La, _T("D:\\gameimg\\La.png"), 220, 200);
			switch (s)
			{
			case 0:
				putimage(holex[r], holey[r], &Do);
				break;
			case 1:
				putimage(holex[r], holey[r], &Re);
				break;
			case 2:
				putimage(holex[r], holey[r], &Mi);
				break;
			case 3:
				putimage(holex[r], holey[r], &Fa);
				break;
			case 4:
				putimage(holex[r], holey[r], &Sol);
				break;
			case 5:
				putimage(holex[r], holey[r], &La);
				break;
		}
	}
};
class BackGround //背景
{
public:
	void gamefirst() {
		IMAGE start;
		loadimage(&start, _T("D:\\gameimg\\start.png"), 1280, 720);
		putimage(0, 0, &start);
	}
	void Back() {
		IMAGE backimg;
		loadimage(&backimg, _T("D:\\gameimg\\background.png"), 1280, 720);
		putimage(0, 0, &backimg);
	}

	
};


// 主函式
int main()
{
	initgraph(1280, 720);
	Game m;
	BackGround b;
	int start = 0, count = 0;
	MOUSEMSG a;
	IMAGE backimg;
	loadimage(&backimg, _T("D:\\gameimg\\background.png"), 1280, 720);
	IMAGE startimg;
	loadimage(&startimg, _T("D:\\gameimg\\start.png"), 1280, 720);
	wchar_t s[12];
	
	while (1)
	{
		a = GetMouseMsg();
		switch (a.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (a.x >= 238 && a.y >= 389 && a.x <= 1030 && a.y <= 573)
			{
				start = 1;
			}
			if (a.x >= 238 && a.y >= 581 && a.x <= 1030 && a.y <= 722)
			{
				start = 2;
			}
			break;
		case WM_MOUSEMOVE:
			putimage(0, 0, &startimg);
			m.hammer(a.x, a.y);
			swprintf_s(s,L"[%d,%d]", a.x, a.y);
			outtextxy(0,0,s);
			break;
		}


		if (start == 1)
		{
			b.Back();
			while (1) {
				a = GetMouseMsg();
				swprintf_s(s, L"[%d,%d]", a.x, a.y);
				outtextxy(0, 0, s);			
				for (int j = 0; j < 30; j++) {
						m.randon();
						m.normal();
				}
				putimage(0, 0, &backimg);
				
			}
			closegraph();
		}
		if (start == 2)
		{
			break;
		}
	}
	closegraph();
	return 0;
}