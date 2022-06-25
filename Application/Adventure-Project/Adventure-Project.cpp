#include <iostream>
#include <iomanip>
#include <thread>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "header/colorSelection.h"
#include "header/gotoxy.h"
#include "header/Logo.h"
#include "header/gameOver.h"
#include "header/theEnd.h"
#include "header/cave.h"
#include "header/jungle.h"

using namespace std;

const int xStartPosition = 50;
int colorSelectionVar;

int playerLS = 0;
int playerHealth = 8;
int playerDamage = 1;
int playerDefense = 0;
bool winFight = false;
bool isCaveExplored = false;
bool isJungleExplored = false;

enum
{
	BLACK = 0,
	RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
	YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
	WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
};

WORD displayColor[] = { WHITE, WHITE };

// Coordinates of X and Y

void mainMenu();

void game()
{
	cout << "You wake up and find yourself on a deserted island." << endl;
	cout << "You've just survived a shipwreck and you are now looking for a way to survive." << endl;
	cout << "As you're standing on the warm sand, you're scouting out the area nearby." << endl << endl;

	cout << "Continue" << endl << endl;
	key = _getch();

	system("CLS");

	cout << "You see a metal bar. It could be used as a weapon. (DMG: +1)" << endl;
	cout << "You picked up the metal bar! Your damage is now " << playerDamage << "!" << endl << endl;

	playerDamage = 2;
	
	cout << "Continue" << endl << endl;
	key = _getch();

	system("CLS");

	cout << "You see a cave and a jungle. Where do you want to go?" << endl;
	cout << "C/J" << endl;

	key = _getch();

	system("CLS");

	if (key == 'C' || key == 'c')
	{
		cave();
		if (isJungleExplored == false)
		{
			cout << "After this adventure, you think that maybe it's time to explore the jungle." << endl << endl;
			cout << "Go to the jungle";
			key = _getch();
			system("cls");
			jungle();
		}
		else
			theEnd();
	}

	else if (key == 'J' || key == 'j')
	{
		jungle();
		if (isCaveExplored == false)
		{
			cout << "After conquering the jungle, maybe it's time to explore the cave." << endl;
			cout << "Go to the cave";
			key = _getch();
			system("cls"); 
			cave();
		}
		else
			theEnd();
	}
}


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

		gotoxy(xStartPosition, 11);
		colorSelection(displayColor[1]);
		cout << "2. Exit";

		key = _getch();

		if (key == 72 && (counter == 2)) // 72 - up arrow (keyboard)
			counter--;
		if (key == 80 && (counter == 1)) // 80 - down arrow (keyboard)
			counter++;

		//carriage return - enter (keyboard)
		if (key == '\r')
		{
			for (int i = 0; i < 2; i++)
				displayColor[i] = WHITE;

			system("CLS");

			if (counter == 1)
			{
				game();
				break;
			}
			else if (counter == 2)
			{
				exit(EXIT_SUCCESS);
			}
		}
		for (int i = 0; i < 2; i++)
			displayColor[i] = WHITE;
	}
}

int main()
{
	SetConsoleTitleA("The Pirate's Cove");
	mainMenu();
}