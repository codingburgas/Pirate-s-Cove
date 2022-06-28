int wolfHP;
int wolfDmg;

#ifndef global_variable_player
#define global_variable_player
int playerHealth;
int playerDamage;
int playerDefense;
#endif

void wolfStanding()
{
	cout << "Attack, Defend or Rest!" << endl << endl;
	cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
	cout << "ENEMY HP: " << wolfHP << " ENEMY DMG: " << wolfDmg << endl << endl;
	cout << "A/D/R" << endl << endl;

	cout << R"(

         )      (\_            \  O_\
        ((    _/{  "-;          \-'\
         )).-' {{ ;'`             / |
        ( (  ;._ \\               |  \

        )";
}

void wolfDefense()
{
	system("cls");

	cout << "Attack, Defend or Rest!" << endl << endl;
	cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
	cout << "ENEMY HP: " << wolfHP << " ENEMY DMG: " << wolfDmg << endl << endl;
	cout << "A/D/R" << endl << endl;

	cout << R"(

         )      (\_        O_\
        ((    _/{  "-;   (-'\
         )).-' {{ ;'`     / |
        ( (  ;._ \\       |  \

        )";

	Sleep(500);
	system("cls");
}

void wolfRest()
{
	system("cls");

	cout << "Attack, Defend or Rest!" << endl << endl;
	cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
	cout << "ENEMY HP: " << wolfHP << " ENEMY DMG: " << wolfDmg << endl << endl;
	cout << "A/D/R" << endl << endl;

	cout << R"(

                          (`')
                           \/	Healed!
	
         )      (\_     \  O_\
        ((    _/{  "-;   \-'\
         )).-' {{ ;'`     / |
        ( (  ;._ \\       |  \

        )";

	Sleep(500);
	system("cls");
}

void attackWolf1()
{
	system("cls");

	cout << "Attack, Defend or Rest!" << endl << endl;
	cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
	cout << "ENEMY HP: " << wolfHP << " ENEMY DMG: " << wolfDmg << endl << endl;
	cout << "A/D/R" << endl << endl;

	cout << R"(

         )      (\_          O_\
        ((    _/{  "-;  ---(-'\
         )).-' {{ ;'`       / |
        ( (  ;._ \\         |  \

        )";

	Sleep(100);
	system("cls");
}

void attackWolf2()
{
	cout << "Attack, Defend or Rest!" << endl << endl;
	cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
	cout << "ENEMY HP: " << wolfHP << " ENEMY DMG: " << wolfDmg << endl << endl;
	cout << "A/D/R" << endl << endl;

	cout << R"(

         )      (\_        O_\
        ((    _/{  "-;---(-'\
         )).-' {{ ;'`     / |
        ( (  ;._ \\       |  \

        )";
	Sleep(100);
	system("cls");
}