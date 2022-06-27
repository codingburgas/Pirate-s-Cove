#include <iostream>
#include <iomanip>
#include <thread>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>


using namespace std;

#ifndef global_variable
#define global_variable
wstring email;
bool registartion;
#endif


char choice;
int spiderHP = 7;
int spiderDmg = 5;
int queenDmg = 5;
int queenHP = 15;
extern int playerLS;
extern int playerHealth;
extern int playerDamage;
extern int playerDefense;
extern bool winFight;
extern bool isCaveExplored;
extern bool isJungleExplored;

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

void jungle()
{
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

		while (spiderHP >= 1 && playerHealth >= 1)
		{
			cout << "Attack, Defend or Rest!" << endl << endl;
			cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
			cout << "ENEMY HP: " << spiderHP << " ENEMY DMG: " << spiderDmg << endl << endl;
			cout << "A/D/R" << endl << endl;

			choice = _getch();

			if (choice == 'A' || choice == 'a')
			{
				spiderHP -= playerDamage;
			}
			else if ((choice == 'D' || choice == 'd') && playerDefense < 4)
			{
				playerDefense += 1;
			}
			else if ((choice == 'R' || choice == 'r') && playerHealth < 9)
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

					if (registration == true) {
						itemToDB(emailStr, "item8", "tooth");
					}

					playerHealth += 1;

					cout << "Your health is now " << playerHealth << "!" << endl;

					cout << "After you pass the maze, you see what looks like a bridge, split in half." << endl;
					cout << "On the other side you see a giant door with a tiny dahole." << endl << endl;

					cout << "Continue (Enter)" << endl << endl;
					choice = _getch();

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

						while (queenHP >= 1 && playerHealth >= 1)
						{
							cout << "Attack, Defend or Rest!" << endl << endl;
							cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
							cout << "ENEMY HP: " << queenHP << " ENEMY DMG: " << queenDmg << endl << endl;
							cout << "A/D/R" << endl << endl;

							choice = _getch();

							if (choice == 'A' || choice == 'a')
							{
								queenHP -= playerDamage;
								playerHealth += playerLS;
							}
							else if ((choice == 'D' || choice == 'd') && playerDefense < 4)
							{
								playerDefense += 1;
							}
							else if ((choice == 'R' || choice == 'r') && playerHealth < 9)
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