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

void gameOver()
{
	cout << R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣶⣾⡿⠿⠿⠿⠿⠿⠿⢿⣷⣶⣦⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣾⡿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠛⠿⣷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⡿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⠤⠤⠤⠤⢤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣤⣴⣶⣿⣿⡄⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣰⣿⠟⠀⠀⠀⠀⠀⠀⣠⡴⠚⠉⠁⠀⠀⠀⠀⠀⠀⠀⠉⠙⠶⣄⣀⣤⣴⣶⠿⠟⠛⠉⣁⠀⠀⢻⣧⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣰⣿⠏⠀⠀⠀⠀⠀⢠⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⣴⡶⠿⠟⠛⢉⣁⣠⣤⡆⢾⣿⠿⣿⡄⠈⣿⡆⠀⠀
⠀⠀⠀⠀⠀⢰⣿⠏⠀⠀⠀⠀⠀⣰⠋⠀⠀⠀⠀⣀⣠⣤⣴⡾⠿⠛⠛⣉⠁⢠⣄⠀⢸⣿⢻⣟⠋⠁⠘⣿⣄⣼⡷⠀⠸⣿⡀⠀
⠀⠀⠀⠀⠀⣿⡿⠀⠀⠀⠀⠀⣸⣇⣠⣤⣶⡾⠿⠛⠋⠉⠀⠀⠀⠀⣾⡿⢿⣎⢿⣆⠈⣿⠘⣿⣶⡾⠇⢹⣿⠻⣷⡀⠀⢻⣧⠀
⠀⠀⠀⠀⢰⣿⣇⣀⣠⣤⣶⠿⠿⠛⠋⢉⣀⢤⣴⣶⣿⠀⠀⠀⠀⠀⣿⡇⠈⢿⡆⢻⣆⣿⡀⢹⣷⡀⣀⣄⢿⡆⠙⠿⠆⠈⣿⡆
⠀⣀⣤⣴⣾⠿⠟⠛⠉⠁⣠⡄⠀⣾⣆⢸⣿⡼⣿⡀⣀⣀⠀⠀⠀⠀⠸⣿⡀⢸⣿⠀⢻⣿⡇⠀⢿⠿⠛⠛⠉⣀⣤⣴⣶⡾⠿⠃
⠘⣿⡏⠁⠀⣰⣶⣶⡄⠀⣿⣿⡄⠸⣿⣿⣿⣷⢻⣿⠟⠛⠀⠀⠀⠀⠀⠹⣿⣾⡿⠀⠀⠉⢁⣀⣤⣴⣶⠿⠟⠛⣿⡏⠀⠀⠀⠀
⠀⢹⣷⠀⠀⣿⡏⠙⢋⡀⢻⡏⣿⣆⢿⡿⣿⢻⡎⣿⣦⣤⣶⡄⠀⠀⠀⠀⢀⣠⣤⣴⣶⠿⠛⣿⠋⠁⠀⠀⠀⢰⣿⠇⠀⠀⠀⠀
⠀⠀⢿⣇⠀⢸⣷⠸⠿⣧⢸⣿⠿⢿⣞⣷⠀⠀⠿⠘⠛⠉⣁⣠⣤⣶⡶⠿⠛⠋⠁⠀⠀⠀⣼⠃⠀⠀⠀⠀⠀⣾⡿⠀⠀⠀⠀⠀
⠀⠀⠘⣿⡄⠀⠻⣷⣤⣿⠿⣿⠀⠈⠛⢉⣀⣠⣤⣶⡾⠿⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⣠⡾⠁⠀⠀⠀⠀⠀⣼⡿⠃⠀⠀⠀⠀⠀
⠀⠀⠀⢹⣷⠀⠀⠉⠛⢁⣀⣠⣤⣶⠾⠿⠻⢯⣉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠾⠋⠀⠀⠀⠀⠀⢀⣼⣿⠃⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢿⣧⣴⣶⠿⣿⣿⡉⠁⠀⠀⠀⠀⠀⠉⠙⠲⠶⠤⣤⣤⠤⠴⠶⠚⠉⠀⠀⠀⠀⠀⠀⠀⣠⣾⡿⠁⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠈⠉⠁⠀⠀⠈⠿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⣷⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⣿⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠻⢿⣷⣶⣤⣤⣤⣀⣀⣠⣤⣤⣶⣶⣿⠿⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠛⠛⠛⠛⠛⠛⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
)";
	Sleep(150);
	cout << "Try again" << setw(30) << "Return to main menu";
}

void game()
{
	
	int playerHealth = 10;
	int playerDamage = 1;
	char key;

	cout << "You wake up and find yourself on a deserted island. You've just survived a shipwreck and you are now looking for a way to survive. As you're standing on the warm sand, you're scouting out the area nearby. You see a metal bar. It could be used as a weapon. Do you take it? (DMG: 3)" << endl;
	cout << "Y/N" << endl;

	key = _getch();

	if (key == 'Y' || key == 'y')
		playerDamage += 2;

	system("CLS");

	cout << "You see a cave and a jungle. Where do you want to go?" << endl;
	cout << "C/J" << endl;
	 
	key = _getch();

	if (key == 'C' || key == 'c')
	{
		cout << " You entered the cave. It is really dark inside. You find a torch on the wall." << endl;
		Sleep(200);
		cout << " After a long walk, you find two tunnels. On the floor in front of them you see two numbers - 8478(left) and 8368(right)" << endl;
		Sleep(200);
		cout << " Unsure which one to pick, you find a message on the wall nearby." << endl;
		cout << R"(
           .-.---------------------------------.-.
          ((o))                                   )
           \U/_______          _____         ____/
             |                                  |
             |                                  |
             |									|
             |          3	  1		4			|
             |                                  |
             |                      *           |
             |							        |
             |                2     7           |
             |                                  |
             |                                  |
             |                                  |
             |____    _______    __  ____    ___|KCK
            /A\                                  \
           ((o))                                  )
            '-'----------------------------------')" << endl << endl;
		cout << "Choose a tunnel(L/R): ";

		key = _getch();

		if (key == 'L' || key == 'l')
		{
			cout << "As you enter the left tunnel, you notice a small box on a stone pedestal. Inside you find a talisman. Wearing it makes you feel more alive!" << endl;
			playerHealth += 2;
		}
		else
		{
			cout << "When you go in the right tunnel, suddenly you feel the ground slowly breaking. The entrance gets covered by a big rock. You fall to your death.";
		}

		cout << "As you continue your journey through the barely-lit tunnel, you end up at a huge cavern. A wolf spots you and it looks angry!" << endl;

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