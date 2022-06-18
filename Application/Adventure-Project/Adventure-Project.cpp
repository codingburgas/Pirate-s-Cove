#include <iostream>
#include <iomanip>
#include <thread>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

int nScreenWidth = 120;
int nScreenHeight = 30;

const int xStartPosition = 50;

int colorSelectionVar;

enum
{
	BLACK = 0,
	GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
	RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
	YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
	WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
};

WORD displayColor[] = { WHITE, WHITE };

bool colorSelection(WORD newColor)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hStdOut != INVALID_HANDLE_VALUE)
		return SetConsoleTextAttribute(hStdOut, newColor);

	return false;
}

// Coordinates of X and Y
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Logo()
{
	colorSelection(YELLOW);
	cout << R"(
		  
	   
                   ________            ____  _            __      _          ______              
	          /_  __/ /_  ___     / __ \(_)________ _/ /____ ( )_____   / ____/___ _   _____ 
	           / / / __ \/ _ \   / /_/ / / ___/ __ `/ __/ _ \|// ___/  / /   / __ \ | / / _ \
	          / / / / / /  __/  / ____/ / /  / /_/ / /_/  __/ (__  )  / /___/ /_/ / |/ /  __/
	         /_/ /_/ /_/\___/  /_/   /_/_/   \__,_/\__/\___/ /____/   \____/\____/|___/\___/ 
                                                                                

                                                                                    
)" << '\n';
}

void mainMenu();


void mainMenu()
{
	Logo();

	int counter = 1;
	char key;

	while(true)
	{
		if (counter >= 1 && counter <= 2)
			displayColor[counter - 1] = RED;

		gotoxy(xStartPosition, 10);
		colorSelection(displayColor[0]);
		cout << "1. Start";

		

		key = _getch();

		if (key == 72 && (counter >= 2 && counter <= 4)) // 72 - up arrow (keyboard)
			counter--;
		if (key == 80 && (counter >= 1 && counter <= 3)) // 80 - down arrow (keyboard)
			counter++;

		//carriage return - enter (keyboard)
		if (key == '\r')
		{
			for (int i = 0; i < 4; i++)
				displayColor[i] = WHITE;

			system("CLS");

			if (counter == 1)
			{
				
				break;
			}
			
		}
		for (int i = 0; i < 4; i++)
			displayColor[i] = WHITE;
	}
}

int main()
{
	mainMenu();
}