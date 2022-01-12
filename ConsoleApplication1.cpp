#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>

#define SIZEUP 1000

using namespace std;

int height = 20, width = 20, x, y, bonusX, bonusY,pos;
bool final = true;
int score = 0;
char arr[SIZEUP] = {'O'};
int Xo[SIZEUP], Yo[SIZEUP], position = 0;
bool STOP,UP, DOWN, LEFT, RIGHT;
//saved old value of UP DOWN

void declare()
{
	pos = 0;
	srand(time(0));
	bonusX = rand() % (width-2) + 1;
	bonusY = rand() % (height-2) + 1;
	x = width / 2;
	y = height / 2;
	Xo[0] = x;
	Yo[0] = y;
	while (bonusX == x && bonusY == y)
	{
		bonusX = rand() % (width -2 ) + 1;
		bonusY = rand() % (height -2 )+ 1;
	}
}

bool check()
{
	if (x == 0 || y == 0 || x == width - 1 || y == height - 1) return false;
	if (final == false) return false;
	for (int i = 1; i <= position; i++)
	{
		if (Xo[0] == Xo[i] && Yo[0] == Yo[i]) return false;
	}
	return true;
}

void printFrames()
{
	for (int i = position; i > 0; i--)
	{
		Xo[i] = Xo[i - 1];
		Yo[i] = Yo[i - 1];
	}
	if (UP)
	{
		Yo[0]--;
	}
	if (DOWN)
	{
		Yo[0]++;
	}
	if (RIGHT)
	{
		Xo[0]++;
	}
	if (LEFT)
	{
		Xo[0]--;
	}
	/*if (Xo[0] == 0 || Xo[0] == width - 1 || Yo[0] == 0 || Yo[0] == height - 1)
	{
		final = false;
		return;
	}*/
	if (Xo[0] == 0)
	{
		Xo[0] = width - 2;
	}
	if (Yo[0] == 0)
	{
		Yo[0] = height - 2;
	}
	if (Xo[0] == width - 1)
	{
		Xo[0] = 1;
	}
	if (Yo[0] == height - 1)
	{
		Yo[0] = 1;
	}
	system("cls");
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				bool hihi = true;
				if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
				{
					cout << "#";
					hihi = false;
				}
				else			
					if (i == bonusY && j == bonusX)
					{
						cout << "X";
						hihi = false;
					}
				else 
					for (int k = 0; k <= position; k++)
					{
						if (i == Yo[k] && j == Xo[k])
						{
							cout << arr[k];
							hihi = false;
							break;
						}
					}
				if (hihi)
				{
					cout << " ";
				}
			}
			cout << endl;
		}
}

void run()
{
	if (_kbhit())
	{
		int a = _getch();
		int b = _getch();
		switch (b)
		{
		case 72:
		{
			//up
			if (DOWN) break;
			UP = true;
			DOWN = false;
			LEFT = false;
			RIGHT = false;
			//if (y == 0) final = false;
			break;
		}
		case 80:
		{
			//down
			if (UP) break;
			DOWN = true;
			UP = false;
			LEFT = false;
			RIGHT = false;
			//if (y == height - 1) final = false;
			break;
		}
		case 77:
		{
			//right
			if (LEFT) break;
			RIGHT = true;
			DOWN = false;
			LEFT = false;
			UP = false;
			//if (x == width - 1) final = false;
			break;
		}
		case 75:
		{
			//left
			if (RIGHT) break;
			LEFT = true;
			DOWN = false;
			UP = false;
			RIGHT = false;
			//if (x == 0) final = false;
			break;
		}
		}
	}
}

void reward()
{
	if(bonusX == Xo[0] && bonusY == Yo[0])
	{
		pos = pos + 1;
		arr[pos] = 'o';
		score = score + 1;
		position++;
		bonusX = rand() % (width - 2) + 1;
		bonusY = rand() % (height - 2) + 1;
		bool t = true;
		while (t)
		{
			for (int i = 0; i <= position; i++)
			{
				if (bonusX == Xo[i] && bonusY == Yo[i])
				{
					bonusX = rand() % (width - 2) + 1;
					bonusY = rand() % (height - 2) + 1;
					break;
				}
				else
				{
					t = false;
				}
			}
		}
	}
}

void createPoint()
{
	bonusX = rand() % (width - 2) + 1;
	bonusY = rand() % (height - 2) + 1;
	bool t = true;
	while (t)
	{
		for (int i = 0; i <= position; i++)
		{
			if (bonusX == Xo[i] && bonusY == Yo[i])
			{
				bonusX = rand() % (width - 2) + 1;
				bonusY = rand() % (height - 2) + 1;
				break;
			}
			else
			{
				t = false;
			}
		}
	}
}

int main()
{
	declare();
	while (check())
	{
		run();
		reward();
		printFrames();
		Sleep(30);
	}
	cout << "score: " << score << endl;
	//declare();
	//printFrames();
	system("pause");
	return 0;
}