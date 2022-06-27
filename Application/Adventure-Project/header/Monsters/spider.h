int spiderHP;
int spiderDmg;


void spiderRest()
{
    system("cls");

    cout << "Attack, Defend or Rest!" << endl << endl;
    cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
    cout << "ENEMY HP: " << spiderHP << " ENEMY DMG: " << spiderDmg << endl << endl;
    cout << "A/D/R" << endl << endl;

    cout << R"(

                                   (`')
             :                      \/   Healed!
             :                    
             :                    \  O_\ 
         /\('')/\                  \-'\
         \      /                   / |
                                    |  \  


        )";

    Sleep(500);
    system("cls");
}

void spiderStanding()
{
    cout << "Attack, Defend or Rest!" << endl << endl;
    cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
    cout << "ENEMY HP: " << spiderHP << " ENEMY DMG: " << spiderDmg << endl << endl;
    cout << "A/D/R" << endl << endl;

    cout << R"(
        
             :
             :                    
             :                    \  O_\ 
         /\('')/\                  \-'\
         \      /                   / |
                                    |  \          


        )";
}

void spiderDefense()
{
    system("cls");

    cout << "Attack, Defend or Rest!" << endl << endl;
    cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
    cout << "ENEMY HP: " << spiderHP << " ENEMY DMG: " << spiderDmg << endl << endl;
    cout << "A/D/R" << endl << endl;

    cout << R"(

             :
             :                    
             :                    O_\ 
         /\('')/\               (-'\
         \      /                 / |
                                  |  \

        )";

    Sleep(500);
    system("cls");
}

void spiderAttack1()
{
    system("cls");

    cout << "Attack, Defend or Rest!" << endl << endl;
    cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
    cout << "ENEMY HP: " << spiderHP << " ENEMY DMG: " << spiderDmg << endl << endl;
    cout << "A/D/R" << endl << endl;

    cout << R"(

             :
             :                    
             :                 O_\ 
         /\('')/\         ---(-'\
         \      /              / |
                               |  \  

        )";

    Sleep(100);
    system("cls");
}

void spiderAttack2()
{
    cout << "Attack, Defend or Rest!" << endl << endl;
    cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
    cout << "ENEMY HP: " << spiderHP << " ENEMY DMG: " << spiderDmg << endl << endl;
    cout << "A/D/R" << endl << endl;

    cout << R"(

             :
             :                    
             :        O_\ 
         /\('')/\---(-'\
         \      /     / |
                      |  \

        )";
    Sleep(100);
    system("cls");
}