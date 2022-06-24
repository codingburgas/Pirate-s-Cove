#include <iostream>
#include <iomanip>
#include <thread>
#include <stdio.h>
#include <Windows.h>
#include "header/colorSelection.h"
#include "header/gotoxy.h"
#include "header/Logo.h"
#include "header/gameOver.h"
#include "header/theEnd.h"
#include <conio.h>

using namespace std;

const int xStartPosition = 50;
int colorSelectionVar;

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
	char key;
	int wolfHP = 8;
	int wolfDmg = 3;
	int spiderHP = 7;
	int spiderDmg = 5;
	int queenDmg = 5;
	int queenHP = 15;
	int minerHP = 20;
	int minerDmg = 5;
	int playerLS = 0;
	int playerHealth = 8;
	int playerDamage = 1;
	int playerDefense = 0;
	bool winFight = false;
	bool isCaveExplored = false;
	bool isJungleExplored = false;

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
		cout << "You entered the cave. It is really dark inside. You find a torch on the wall." << endl;
		Sleep(200);
		cout << "After a long walk, you find two tunnels. On the floor you see two numbers - 8478(left) and 8368(right)" << endl;
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

		system("CLS");

		if (key == 'L' || key == 'l')
		{
			cout << "As you enter the left tunnel, you notice a small box on a stone pedestal." << endl;
			cout << "Inside you find a talisman. Wearing it makes you feel more alive! (HP: +1)" << endl << endl;
			playerHealth += 1;

			cout << "Continue" << endl << endl;
			key = _getch();

			system("CLS");

		}
		else
		{
			cout << "When you go in the right tunnel, suddenly you feel the ground slowly breaking." << endl;
			cout << "The entrance gets covered by a big rock. You fall to your death." << endl;
			gameOver();
		}

		cout << "As you continue your journey through the barely-lit tunnel, you end up at a huge cavern." << endl;
		cout << "A wolf spots you and it looks angry! Time to fight!" << endl << endl;

		cout << "Continue" << endl << endl;

		key = _getch();

		system("CLS");

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

			playerHealth -= wolfDmg - playerDefense;

			system("CLS");

			if (playerHealth <= 0)
			{
				cout << "You died! Game over!";
				gameOver();

			}
			else if (wolfHP <= 0)
			{
				cout << "You won the fight! The wolf dropped to the ground, dead." << endl;

				playerHealth = 9;
				playerDefense = 0;

				cout << "After the fight, you feel exhausted. You sit on the ground when suddenly you find a pickaxe." << endl;
				cout << "Your damage is now " << playerDamage << "!" << endl << endl;
				
				cout << "Continue" << endl << endl;
				key = _getch();

				system("CLS");

				cout << "After walking for a while, you find a trolley and a lever next to it." << endl;
				cout << "You sit in the trolley. Looks like you need to move the lever to move it." << endl;

				Sleep(200);
				cout << "There is one problem though - you don't know whether to push the lever or to pull it." << endl;
				cout << "You look in front of you and find the following note in the trolley: " << endl;

				Sleep(200);
				cout << R"(
			_______________________
			|                     |
			|                     |
			|  To find out what   |
			|  to do with the     |
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

				system("CLS");

				if (key == '>')
				{
					cout << "The trolley starts moving! You made the right choice! " << endl;
				}
				else if (key == '<')
				{
					cout << "The trolley stays in place. You can hear something falling." << endl;
					cout << "You look up at the ceiling. Spikes are falling on you! They hit you and you die.";
					gameOver();
				}

				cout << "After a while, your journey with the trolley comes to an end." << endl;
				cout << "It stops right in front of a metal door." << endl << endl;

				cout << "Continue" << endl << endl; 
				key = _getch();

				system("CLS");

				cout << "You see a miner's helmet next to it. (DEF: +2)" << endl;

				playerDefense += 2;

				cout << "You picked up the helmet! You feel more safe! Your defense is now " << playerDefense << "!" << endl << endl;

				cout << "Continue" << endl << endl;
				key = _getch();

				system("CLS");

				Sleep(200);
				cout << "Looking for clues on how to open the door, you find the following on the wall: " << endl;

				Sleep(200);
				cout << R"(
				.-.---------------------------------.-.
				((o))                                   )
				\U/_______          _____         ____/
				|                                  |
				|                                  |
				|                                  |
				|       Take 5, add 8 to it,       |
				|       subtract 3 from the        |
				|       result, then divide        |
				|       by 2, multiply by 14,      |
				|       add 7 to the result        |
				|       and finally, multiply      |
				|       by 4.                      |
				|                                  |
				|                                  |
				|____    _______    __  ____    ___|
				/A\                                  \
				((o))                                  )
				'-'----------------------------------')" << endl << endl;

				cout << "You also find the numbers from 0 to 9. Looks like you need to enter a code to open the door." << endl;
				cout << "Choose between 308 and 318(F - 308; S - 318)" << endl;
				cout << "F/S" << endl;

				key = _getch();

				if (key == 'F' || key == 'f')
				{	
					system("CLS");

					cout << "Upon entering 308, you hear the door opening! Good job, you entered the right code!" << endl;
					cout << "After walking for a while, you find another door. Drawn on it, you can see that you" << endl;
					cout << "need to press a button which is on top of the door." << endl;

					Sleep(200);
					cout << "You can't reach it, so you use your pickaxe to press it. It works!" << endl;
					cout << "The door opens and you go in the next room." << endl << endl;

					cout << "Continue" << endl << endl;
					key = _getch();

					system("CLS");

					Sleep(200);
					cout << "In the middle of the room you can see a chest full with silver coins." << endl;
					cout << "Right as you start to pick it up, you see something rising up behind it." << endl;
					Sleep(200);
					cout << "It's a tall muscular miner. You discover that he is a zombie, judging by the" << endl;
					cout << "look of his face and the missing flesh on parts of it." << endl;
					Sleep(200);
					cout << "To get the treasure, prepare to fight him. This won't be an easy task." << endl;
					Sleep(200);

					cout << "Continue" << endl << endl;
					key = _getch();

					system("CLS");

					while (minerHP >= 1 && playerHealth >= 1)
					{
						cout << "Attack, Defend or Rest!" << endl << endl;
						cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
						cout << "ENEMY HP: " << minerHP << " ENEMY DMG: " << minerDmg << endl << endl;
						cout << "A/D/R" << endl << endl;

						key = _getch();

						if (key == 'A' || key == 'a')
						{
							minerHP -= playerDamage;
							playerHealth += playerLS;
						}
						else if ((key == 'D' || key == 'd') && playerDefense < 4)
						{
							playerDefense += 1;
						}
						else if ((key == 'R' || key == 'r') && playerHealth < 9)
						{
							playerHealth += 2;
						}

						playerHealth -= minerDmg - playerDefense;

						system("CLS");

						if (playerHealth <= 0)
						{
							cout << "You died! Game over!";
							gameOver();

						}
						else if (minerHP <= 0)
						{
							cout << "Congratulations! You killed the Zombie Miner! After his death, you pick up the" << endl;
							cout << "lost chest and escape by digging the nearby wall with your pickaxe!" << endl << endl;

							isCaveExplored = true;
							cout << "Continue" << endl << endl;
							key = _getch();

							system("CLS");

							if (isJungleExplored == false)
							{
								cout << "After this adventure, you think that maybe it's time to explore the jungle." << endl << endl;
								cout << "Go to the jungle";
								key = _getch();
							}
							else
								theEnd();

						}
					}
				}
				else
				{
					cout << "Upon entering 318, you hear something. Suddenly, big rocks are falling from the ceiling." << endl;
					cout << "One falls on you and crushes you.";
					gameOver();
				}
			}
		}

	}

		else if (key == 'J' || key == 'j')
		{
			cout << "You head towards the jungle, not knowing what you'll find there." << endl;

			Sleep(200);

			cout << "While walking, you notice an ancient temple, a dim light glowing within it. You decide to investigate." << endl;

			Sleep(200);

			cout << "As you're going down the stairs, a trap locks you in place and symbols on the wall start to glow." << endl;
			cout << "You read the message which says: " << endl;

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

			system("CLS");

			if (key == 'S' || key == 's')
			{
				cout << "As you confirm your choice, the trap releases you and you barely escape the falling rock above you." << endl;
				cout << "Since the exit is now blocked, you continue further into the temple." << endl;
				cout << "While walking, you stumble upon an ancient piece of armor! Wearing makes you feel protected. (DEF: +2)" << endl;

				playerDefense += 2;

				cout << "Your defense is now " << playerDefense << "!" << endl << endl;

				cout << "Continue" << endl << endl;
				key = _getch();

				system("CLS");

				cout << "You find a room with a chest inside. When you go to open it, a spider jumps from the ceiling, landing in front of you!" << endl;

				while (spiderHP >= 1 && playerHealth >= 1)
				{
					cout << "Attack, Defend or Rest!" << endl << endl;
					cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
					cout << "ENEMY HP: " << spiderHP << " ENEMY DMG: " << spiderDmg << endl << endl;
					cout << "A/D/R" << endl << endl;

					key = _getch();

					if (key == 'A' || key == 'a')
					{
						spiderHP -= playerDamage;
					}
					else if ((key == 'D' || key == 'd') && playerDefense < 4)
					{
						playerDefense += 1;
					}
					else if ((key == 'R' || key == 'r') && playerHealth < 9)
					{
						playerHealth += 2;
					}

					playerHealth -= spiderDmg - playerDefense;

					system("CLS");

					if (playerHealth <= 0)
					{
						cout << "You died! Game over!";
						gameOver();
					}
					else if (spiderHP <= 0)
					{
						cout << "You won the fight! The spider made a loud screech and died." << endl;
						playerHealth = 8;
						playerDefense = 2;

						cout << "Now that the threat is gone, you open the chest and find a sword," << endl;
						cout << "which has a red, glowing jem in its handle. (LIFESTEAL: +1; DMG: +3)" << endl << endl;

						playerDamage += 3;
						playerLS += 1;

						cout << "Continue" << endl << endl;
						key = _getch();

						system("CLS");

						cout << "Going deeper into the temple, you stumble upon a massive maze." << endl;
						cout << "Lucky for you, however, there is a map on the wall which will guide you through the maze." << endl;
						cout << "There is one problem, though. It's coded in some unknown way." << endl;

						

						cout << R"(
  _____   _______    __    ______   _______  ______  
 / ___ \ (  __   )  /  \  / ___  \ (  ____ \/ ___  \ 
( (   ) )| (  )  |  \/) ) \/   \  \| (    \/\/   )  )
( (___) || | /   |    | |    ___) /| (__        /  / 
 \____  || (/ /) |    | |   (___ ( |  __)      /  /  
      ) ||   / | |    | |       ) \| (        /  /   
/\____) )|  (__) |  __) (_/\___/  /| )       /  /    
\______/ (_______)  \____/\______/ |/        \_/     
                                                     
)" << endl << endl;

						cout << "The entrance of the maze splits into two paths. Maybe this code could help you choose the direction?" << endl;
						cout << "L/R" << endl;

						key = _getch();

						system("CLS");

						if (key == 'L' || key == 'l')
						{
							cout << "As you walk down the left path, you notice a spider's tooth, which when worn, gives you more health! (HP: +1)" << endl;
							playerHealth += 1;

							cout << "Your health is now " << playerHealth << "!" << endl;

							cout << "After you pass the maze, you see what looks like a bridge, split in half." << endl;
							cout << "On the other side you see a giant door with a tiny keyhole." << endl << endl;

							cout << "Continue" << endl << endl;
							key = _getch();

							system("CLS");

							cout << "In order to cross the bridge, you need to solve an another riddle. " << endl;
							cout << R"(
             _______________________
             |                     |
             |                     |
             |	I am a protector   |
             |	I sit on a bridge  |
             |  One person can see |
             |  right through me,  |
             |  while others wonder|
             |  what I hide.       |
             |  What am I?         |
             |                     |
             |  Sunglasses (S)     |
             |  Window (W)         |
             |  Binoculars(B)      |
             |                     |
             |                     |
             |__    ___   __    ___|)" << endl << endl;

							cout << "S/W/B" << endl;

							key = _getch();

							system("CLS");

							if (key == 'S' || key == 's')
							{
								cout << "The ground starts to rumble. A stone foundation connects the two sides so you can cross the gap." << endl;
								cout << "You walk up to the door and you notice there's a tooth-shaped carving in the door." << endl;
								cout << "You use the spider tooth amulet from the maze to open the gate." << endl << endl;

								cout << "Continue" << endl << endl;
								key = _getch();

								system("CLS");

								cout << "You hear loud creaking, after which you see an enormous spider, which looks like the Spider Queen!" << endl;
								cout << "Behind her you see a shiny treasure chest, filled with gold." << endl << endl;

								cout << "Continue" << endl << endl;
								key = _getch();

								system("CLS");

								while (queenHP >= 1 && playerHealth >= 1)
								{
									cout << "Attack, Defend or Rest!" << endl << endl;
									cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
									cout << "ENEMY HP: " << queenHP << " ENEMY DMG: " << queenDmg << endl << endl;
									cout << "A/D/R" << endl << endl;

									key = _getch();

									if (key == 'A' || key == 'a')
									{
										queenHP -= playerDamage;
										playerHealth += playerLS;
									}
									else if ((key == 'D' || key == 'd') && playerDefense < 4)
									{
										playerDefense += 1;
									}
									else if ((key == 'R' || key == 'r') && playerHealth < 9)
									{
										playerHealth += 2;
									}

									playerHealth -= queenDmg - playerDefense;

									system("CLS");

									if (playerHealth <= 0)
									{
										cout << "You died! Game over!";
										gameOver();

									}
									else if (queenHP <= 0)
									{
										cout << "Congratulations! You killed the Spider Queen! After her graceful death, you claim the" << endl;
										cout << "lost treasure and escape through a hole in the wall" << endl << endl;

										isJungleExplored = true;
										cout << "Continue" << endl << endl;
										key = _getch();

										system("CLS");

										if (isCaveExplored == false)
										{
											cout << "After conquering the jungle, maybe it's time to explore the cave." << endl;
											cout << "Go to the cave";
											key = _getch();
										}
										else
											theEnd();

									}

								}
							}
							else
							{
								cout << "The ground beneath you starts to break and you fall to your death." << endl;
							}

						}
					}
				}
			}
			else
			{
				cout << "As soon as you select the option, the trap squeezes you even tighter and a giant rock crushes you." << endl;
			}
		}
		else
		{
			cout << "Please choose a valid location!";
			key = _getch();
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