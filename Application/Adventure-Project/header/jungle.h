#include <iostream>
#include <iomanip>
#include <thread>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include "Monsters/spider.h"
#include "Monsters/queen.h"

using namespace std;

#ifndef global_variable
#define global_variable
wstring email;
bool registartion;
#endif

//Initialise variables

char choice;
extern int spiderHP = 7;
extern int spiderDmg = 5;
extern int queenDmg = 5;
extern int queenHP = 25;
extern int playerLS;
extern int playerHealth;
extern int playerDamage;
extern int playerDefense;
extern bool winFight;
extern bool isCaveExplored;
extern bool isJungleExplored;

//Send items to database

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

//Begin jungle section

void jungle()
{
	//Sends email as string

	string emailStr(email.begin(), email.end());

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

	choice = _getch();

	system("CLS");

	if (choice == 'S' || choice == 's')
	{
		cout << "As you confirm your choice, the trap releases you and you barely escape the falling rock above you." << endl;
		cout << "Since the exit is now blocked, you continue further into the temple." << endl;
		cout << "While walking, you stumble upon an ancient piece of armor! Wearing makes you feel protected. (DEF: +2)" << endl;

		if (registration == true) {
			itemToDB(emailStr, "item6", "armor");
		}

		playerDefense += 2;

		cout << "Your defense is now " << playerDefense << "!" << endl << endl;

		cout << "Continue (Enter)" << endl << endl;
		choice = _getch();

		system("CLS");

		cout << "You find a room with a chest inside. When you go to open it, a spider jumps from the ceiling, landing in front of you!" << endl;

		//Loop stops when the player or monster die

		while (spiderHP >= 1 && playerHealth >= 1)
		{
			//Outputs idle position animation

			while (true)
			{
				spiderStanding();

				key = _getch();

				//Plays different animations based on input

				if (key == 'A' || key == 'a')
				{
					spiderAttack1();
					spiderAttack2();
					spiderAttack1();
					spiderHP -= playerDamage;
				}
				else if ((key == 'D' || key == 'd') && playerDefense < 4)
				{
					spiderDefense();
					playerDefense += 1;
				}
				else if ((key == 'R' || key == 'r') && playerHealth < 8)
				{
					spiderRest();
					playerHealth += 2;
				}

				playerHealth -= spiderDmg - playerDefense;

				system("CLS");

				//If the player dies, game over

				if (playerHealth <= 0)
				{
					cout << "You died! Game over!";
					gameOver();
					exit(EXIT_SUCCESS);

				}
				else if (spiderHP <= 0)
				{
					cout << "You won the fight! The spider dropped to the ground, dead." << endl;

					playerHealth = 8;
					playerDefense = 2;
					break;
				}
			}

			cout << "Now that the threat is gone, you open the chest and find a sword," << endl;
			cout << "which has a red, glowing jem in its handle. (LIFESTEAL: +1; DMG: +3)" << endl << endl;

			if (registration == true) {
				itemToDB(emailStr, "item7", "sword");
			}

			playerDamage += 3;
			playerLS += 1;

			cout << "Continue (Enter)" << endl << endl;
			choice = _getch();

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

			choice = _getch();

			system("CLS");

			if (choice == 'L' || choice == 'l')
			{
				cout << "As you walk down the left path, you notice a spider's tooth, which when worn, gives you more health! (HP: +1)" << endl;

				//Sends item to database

				if (registration == true) {
					itemToDB(emailStr, "item8", "tooth");
				}

				playerHealth += 1;

				cout << "Your health is now " << playerHealth << "!" << endl;

				cout << "After you pass the maze, you see what looks like a bridge, split in half." << endl;
				cout << "On the other side you see a giant door with a tiny keyhole." << endl << endl;

				cout << "Continue (Enter)" << endl << endl;
				choice = _getch();

				system("CLS");

				cout << "In order to cross the bridge, you need to solve an another riddle. " << endl;
				cout << R"(
					_______________________
					|                     |
					|                     |
					|  I am a protector   |
					|  I sit on a bridge  |
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

				choice = _getch();

				system("CLS");

				if (choice == 'S' || choice == 's')
				{
					cout << "The ground starts to rumble. A stone foundation connects the two sides so you can cross the gap." << endl;
					cout << "You walk up to the door and you notice there's a tooth-shaped carving in the door." << endl;
					cout << "You use the spider tooth amulet from the maze to open the gate." << endl << endl;

					cout << "Continue (Enter)" << endl << endl;
					choice = _getch();

					system("CLS");

					cout << "You hear loud creaking, after which you see an enormous spider, which looks like the Spider Queen!" << endl;
					cout << "Behind her you see a shiny treasure chest, filled with gold." << endl << endl;

					cout << "Continue (Enter)" << endl << endl;
					choice = _getch();

					system("CLS");

					//Loop stops when the player or monster die

					while (queenHP >= 1 && playerHealth >= 1)
					{
						//Outputs idle position animation

						while (true)
						{
							queenStanding();

							key = _getch();

							//Plays different animations based on input

							if (key == 'A' || key == 'a')
							{
								queenAttack1();
								queenAttack2();
								queenAttack1();
								queenHP -= playerDamage;
							}
							else if ((key == 'D' || key == 'd') && playerDefense < 4)
							{
								queenDefense();
								playerDefense += 1;
							}
							else if ((key == 'R' || key == 'r') && playerHealth < 8)
							{
								queenRest();
								playerHealth += 2;
							}

							playerHealth -= queenDmg - playerDefense;

							system("CLS");

							//If the player dies, game over

							if (playerHealth <= 0)
							{
								cout << "You died! Game over!";
								gameOver();
								exit(EXIT_SUCCESS);

							}
							else if (queenHP <= 0)
							{
								cout << "You won the fight! The spider dropped to the ground, dead." << endl;

								cout << "Congratulations! You killed the Spider Queen! After her graceful death, you claim the" << endl;

								if (registration == true) {
									itemToDB(emailStr, "item9", "spider trophy");
								}

								cout << "lost treasure and escape through a hole in the wall" << endl << endl;

								playerLS = 0;
								playerHealth = 8;
								playerDamage = 2;
								playerDefense = 0;
								isJungleExplored = true;

								cout << "Continue (Enter)" << endl << endl;
								choice = _getch();

								system("CLS");
								break;
							}
						}

					}
				}
				else
				{
					cout << "The ground beneath you starts to break and you fall to your death." << endl;
					gameOver();
					exit(EXIT_SUCCESS);
				}

			}
			else
			{
				cout << "As you walk down the right path, a trap crushes you to your death." << endl;
				gameOver();
				exit(EXIT_SUCCESS);
			}

		}
	}
	else
	{
		cout << "As you select your choice, the trap squeezes you even tighter and you get penetrated by wall spikes." << endl;
		gameOver();
		exit(EXIT_SUCCESS);
	}
}

