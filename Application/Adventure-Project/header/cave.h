#include <iostream>
#include <iomanip>
#include <thread>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include "Monsters/wolf.h"
#include "Monsters/zombie.h"

using namespace std;

#ifndef global_variable
#define global_variable
wstring email;
bool registration;
#endif

char key;
extern int wolfHP = 8;
extern int wolfDmg = 3;
extern int minerHP = 20;
extern int minerDmg = 5;
extern int playerLS;
extern int playerHealth = 8;
extern int playerDamage = 1;
extern int playerDefense = 0;
extern bool winFight;
extern bool isCaveExplored;
extern bool isJungleExplored;

//Sends items to the database

#ifndef itemtodbfunction
#define itemtodbfunction
void itemToDB(string emailStr, string whichItem, string item)
{
	string link = "https://piratescove.maxprogress.bg/inc/upload.php?email=" + emailStr + "&whichItem=" + whichItem + " &item=" + item + "";

	wstring temp = wstring(link.begin(), link.end());

	LPCWSTR newLink = temp.c_str();

	ShellExecute(0, 0, newLink, 0, 0, SW_SHOW);
}
#endif

void cave()
{
	string emailStr(email.begin(), email.end());

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

	//Makes a choice

	if (key == 'L' || key == 'l')
	{
		cout << "As you enter the left tunnel, you notice a small box on a stone pedestal." << endl;
		cout << "Inside you find a talisman. Wearing it makes you feel more alive! (HP: +1)" << endl << endl;

		playerHealth += 1;

		cout << "Your health is now " << playerHealth << "!" << endl << endl;
		
		//Sends item to database

		if (registration == true) {
			itemToDB(emailStr, "item2", "talisman");
		}

		cout << "Continue (Enter)" << endl << endl;
		key = _getch();

	}
	else
	{
		cout << "When you go in the right tunnel, suddenly you feel the ground slowly breaking." << endl;
		cout << "The entrance gets covered by a big rock. You fall to your death." << endl;
		gameOver();
		exit(EXIT_SUCCESS);
		
	}

	system("CLS");

	cout << "As you continue your journey through the barely-lit tunnel, you end up at a huge cavern." << endl;
	cout << "A wolf spots you and it looks angry! Time to fight!" << endl << endl;

	cout << "Continue (Enter)" << endl << endl;

	key = _getch();

	system("CLS");

	//Loop stops when the player or monster die

	while (wolfHP >= 1 && playerHealth >= 1)
	{

		//Outputs idle position animation

		while (true)
		{
			wolfStanding();

			key = _getch();

			//Plays different animations based on input

			if (key == 'A' || key == 'a')
			{
				attackWolf1();
				attackWolf2();
				attackWolf1();
				wolfHP -= playerDamage;
			}
			else if ((key == 'D' || key == 'd') && playerDefense < 2)
			{
				wolfDefense();
				playerDefense += 1;
			}
			else if ((key == 'R' || key == 'r') && playerHealth < 9)
			{
				wolfRest();
				playerHealth += 2;
			}

			playerHealth -= wolfDmg - playerDefense;

			system("CLS");

			//If the player dies, game over

			if (playerHealth <= 0)
			{
				cout << "You died! Game over!";
				gameOver();
				exit(EXIT_SUCCESS);

			}
			else if (wolfHP <= 0)
			{
				cout << "You won the fight! The wolf dropped to the ground, dead." << endl;

				playerHealth = 9;
				playerDefense = 0;
				break;
			}
		}
	}
		
	cout << "After the fight, you feel exhausted. You sit on the ground when suddenly you find a pickaxe." << endl;

	if (registration == true) {
		itemToDB(emailStr, "item3", "pickaxe");
	}

	playerDamage = 4;
	cout << "Your damage is now " << playerDamage << "!" << endl << endl;

	cout << "Continue (Enter)" << endl << endl;
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
	//Wrong input exits the program
	else if (key == '<')
	{
		cout << "The trolley stays in place. You can hear something falling." << endl;
		cout << "You look up at the ceiling. Spikes are falling on you! They hit you and you die.";
		gameOver();
		exit(EXIT_SUCCESS);
	}

	cout << "After a while, your journey with the trolley comes to an end." << endl;
	cout << "It stops right in front of a metal door." << endl << endl;

	cout << "Continue (Enter)" << endl << endl;
	key = _getch();

	system("CLS");

	cout << "You see a miner's helmet next to it. (DEF: +2)" << endl;

	//Sends item to database

	if (registration == true) {
		itemToDB(emailStr, "item4", "helmet");
	}

	playerDefense += 2;

	cout << "You picked up the helmet! You feel more safe! Your defense is now " << playerDefense << "!" << endl << endl;

	cout << "Continue (Enter)" << endl << endl;
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

		cout << "Continue (Enter)" << endl << endl;
		key = _getch();

		system("CLS");

		Sleep(200);
		cout << "In the middle of the room you can see a chest full with silver coins." << endl;
		cout << "Right as you start to pick it up, you see something rising up behind it." << endl;
		Sleep(200);
		cout << "It's a tall muscular miner. You discover that he is a zombie, judging by the" << endl;
		cout << "look of his face and the missing flesh on parts of it." << endl;
		Sleep(200);
		cout << "To get the treasure, prepare to fight him. This won't be an easy task." << endl << endl;
		Sleep(200);

		cout << "Continue (Enter)" << endl << endl;
		key = _getch();

		system("CLS");

		//Loop stops when the player or monster die

		while (minerHP >= 1 && playerHealth >= 1)
		{
			//Outputs idle position animation

			while (true)
			{
				zombieStanding();

				key = _getch();

				//Plays different animations based on input

				if (key == 'A' || key == 'a')
				{
					zombieAttack1();
					zombieAttack2();
					zombieAttack1();
					minerHP -= playerDamage;
				}
				else if ((key == 'D' || key == 'd') && playerDefense < 4)
				{
					zombieDefense();
					playerDefense += 1;
				}
				else if ((key == 'R' || key == 'r') && playerHealth < 9)
				{
					zombieRest();
					playerHealth += 2;
				}

				playerHealth -= minerDmg - playerDefense;

				system("CLS");

				//If the player dies, game over

				if (playerHealth <= 0)
				{
					cout << "You died! Game over!";
					gameOver();
					exit(EXIT_SUCCESS);

				}
				else if (minerHP <= 0)
				{
					cout << "Congratulations! You killed the Zombie Miner! After his death, you pick up the" << endl;

					if (registration == true) {
						itemToDB(emailStr, "item5", "zombie trophy");
					}

					cout << "lost chest and escape by digging the nearby wall with your pickaxe!" << endl << endl;

					playerLS = 0;
					playerHealth = 8;
					playerDamage = 2;
					playerDefense = 0;
					isCaveExplored = true;

					cout << "Continue (Enter)" << endl << endl;
					key = _getch();

					system("CLS");
					break;
				}
			}
		}
	}
	else
	{
		cout << "Upon entering 318, you hear something. Suddenly, big rocks are falling from the ceiling." << endl;
		cout << "One falls on you and crushes you.";
		gameOver();
		exit(EXIT_SUCCESS);
	}
			
}