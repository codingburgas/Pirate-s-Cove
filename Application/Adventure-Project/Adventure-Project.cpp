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
	
	int playerHealth = 8;
	int playerDamage = 1;
	int playerDefense = 0;
	int playerAll = playerDefense + playerHealth;
	int wolfHP = 8;
	int wolfDmg = 3;
	char key;
	bool winFight = false;

	cout << "You wake up and find yourself on a deserted island. You've just survived a shipwreck and you are now looking for a way to survive. As you're standing on the warm sand, you're scouting out the area nearby. You see a metal bar. It could be used as a weapon. Do you take it? (DMG: 1)" << endl;
	cout << "Y/N" << endl;

	key = _getch();

	if (key == 'Y' || key == 'y')
	{
		cout << "You picked up the metal bar! ";
		playerDamage = 2;
		cout << "Your damage is now " << playerDamage;
	}
	Sleep(200);
	system("CLS");

	cout << "You see a cave and a jungle. Where do you want to go?" << endl;
	cout << "C/J" << endl;
	 
	key = _getch();

	if (key == 'C' || key == 'c')
	{	
		cout << "You entered the cave. It is really dark inside. You find a torch on the wall." << endl;
		Sleep(200);
		cout << "After a long walk, you find two tunnels. On the floor in front of them you see two numbers - 8478(left) and 8368(right)" << endl;
		Sleep(200);
		cout << "Unsure which one to pick, you find a message on the wall nearby." << endl;
		cout << R"(
           .-.---------------------------------.-.
          ((o))                                   )
           \U/_______          _____         ____/
             |                                  |
             |                                  |
             |                                  |
             |          3     1     4           |
             |                                  |
             |                      *           |
             |                                  |
             |                2     7           |
             |                                  |
             |                                  |
             |                                  |
             |____    _______    __  ____    ___|
            /A\                                  \
           ((o))                                  )
            '-'----------------------------------')" << endl << endl;

		cout << "Choose a tunnel(L/R): " << endl;

		key = _getch();

		if (key == 'L' || key == 'l')
		{
			cout << "As you enter the left tunnel, you notice a small box on a stone pedestal. Inside you find a talisman. Wearing it makes you feel more alive! (HP +1)" << endl;
			playerHealth += 1;
			
		}
		else
		{
			cout << "When you go in the right tunnel, suddenly you feel the ground slowly breaking. The entrance gets covered by a big rock. You fall to your death.";
		}


		Sleep(1000);
		cout << "As you continue your journey through the barely-lit tunnel, you end up at a huge cavern. A wolf spots you and it looks angry!" << endl;
		cout << "Time to fight!" << endl;

		while (wolfHP >= 1 && playerHealth >= 1)
		{
			cout << "Attack, Defend or Rest!" << endl << endl;
			cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
			cout << "ENEMY HP: " << wolfHP << " ENEMY DMG: " << wolfDmg << endl << endl;
			cout << "A/D/R" << endl << endl;

			key = _getch();

			if (key == 'A' || key == 'a')
			{
				wolfHP -= playerDamage;
			}
			else if ((key == 'D' || key == 'd') && playerDefense < 2)
			{
				playerDefense += 1;
			}
			else if ((key == 'R' || key == 'r') && playerHealth < 9)
			{
				playerHealth += 2;
			}
		
			else
			{
				cout << "Please choose a valid action!";
				key = _getch();
			}

			playerHealth -= wolfDmg - playerDefense;

			system("CLS");

			if (playerHealth <= 0)
			{
				cout << "You died! Game over!";
			}
			else if (wolfHP <= 0)
			{
				cout << "You won the fight! The wolf dropped to the ground, dead." << endl;
			}

		}
		
		cout << "After the fight, you feel exhausted. You sit on the ground when suddenly you find a pickaxe. Do you want to take it(DMG: 4)?" << endl;
		cout << "Y/N" << endl;

		key = _getch();

		if (key == 'y' || key == 'Y')
		{
			cout << "You picked up the pickaxe! ";
			playerDamage = 4;
			cout << "Your damage is now " << playerDamage << "!" << endl << endl << endl;
		}
		Sleep(200);
		cout << "After walking for a while, you find a trolley and a lever next to it. You sit in the trolley. Looks like you need to move the lever to move it." << endl;
		Sleep(200);
		cout << "There is one problem though - you don't know whether to push the lever or to pull it. You look in front of you and find the following note in the trolley: " << endl;
		Sleep(200);
		cout << R"(
             _______________________
             |                     |
             |                     |
             |	To find out what   |
             |	to do with the	   |
             |  lever, choose the  |
             |  action which has   |
             |  the fractions that |
             |  give the same      |
             |  result.            |
             |                     |
             |  Pull - 0.4; 1/4;   |
             |  40%                |
             |  Push - 0.5; 1/2;   |
             |  50%                |
             |                     |
             |__    ___   __    ___|)" << endl << endl;

		Sleep(200);
		cout << "Choose whether to pull or push the lever(> - push; < - pull)." << endl;
		cout << "> / <" << endl;
		key = _getch();
		if (key == '>')
		{
			cout << "The trolley starts moving! You made the right choice!";
		}
		else if (key == '<')
		{
			cout << "The trolley stays at its place. You can hear something falling. You look up at the ceiling. Spikes are falling on you! They hit you and you die.";
		}
	}

	else if (key == 'J' || key == 'j')
	{
		cout << "You enter the jungle.";
	}

	else
	{
		cout << "Please choose a valid location!";
		key = _getch();
	}
	else if (key == 'J' || key == 'j')
	{
		cout << "You head towards the jungle, not knowing what you'll find there." << endl;
		Sleep(200);
		cout << "While walking, you notice an ancient temple, a dim light glowing within it. You decide to investigate." << endl;
		Sleep(200);
		cout << "As you're going down the stairs, a trap locks you in place and symbols on the wall start to glow. You read the message which says:" << endl;
		cout << R"(
		I provide light but I'm not a candle

		I'm hot but I'm not a bonfire

		I have rays but I'm not an aquarium

		I'm a star but I'm not a celebrity

		I rise in the morning but I'm not 

		someone getting out of bed)" << endl << endl;

		cout << "The available options are:" << endl;
		cout << "Sun/Mars/Lightbulb (S/M/L)" << endl;

		key = _getch();

		if (key == 'S' || key == 's')
		{
			cout << "As you confirm your choice, the trap releases you and you barely escape the falling rock above you." << endl;
			cout << "Since the exit is now blocked, you continue further into the temple." << endl;
		}
		else
		{
			cout << "As soon as you select the option, the trap squeezes you even tighter and a giant rock crushes you." << endl;
		}
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