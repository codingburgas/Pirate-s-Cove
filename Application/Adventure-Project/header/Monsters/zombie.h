int minerHP;
int minerDmg;

void zombieRest()
{
    system("cls");

    cout << "Attack, Defend or Rest!" << endl << endl;
    cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
    cout << "ENEMY HP: " << minerHP << " ENEMY DMG: " << minerDmg << endl << endl;
    cout << "A/D/R" << endl << endl;

    cout << R"(

              ,
          _,-""-._
        ,"        ".
       /    ,-,  ,"\
      "    /   \ | o|
      \    `-o-"  `-',
       `,   _.--'`'--`
         `--`---'               (`')
           ,' '                  \/   Healed!
         ./ ,  `,                        
         / /     \             \  O_\    
        (_)))_ _,"              \-'\
           _))))_,                / |
          (_,-._)))               |  \


        )";

    Sleep(500);
    system("cls");
}

void zombieStanding()
{
    cout << "Attack, Defend or Rest!" << endl << endl;
    cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
    cout << "ENEMY HP: " << minerHP << " ENEMY DMG: " << minerDmg << endl << endl;
    cout << "A/D/R" << endl << endl;

    cout << R"(

              ,
          _,-""-._
        ,"        ".
       /    ,-,  ,"\
      "    /   \ | o|
      \    `-o-"  `-',
       `,   _.--'`'--`
         `--`---'            
           ,' '      
         ./ ,  `,            
         / /     \             \  O_\    
        (_)))_ _,"              \-'\
           _))))_,                / |
          (_,-._)))               |  \


        )";
}

void zombieDefense()
{
    system("cls");

    cout << "Attack, Defend or Rest!" << endl << endl;
    cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
    cout << "ENEMY HP: " << minerHP << " ENEMY DMG: " << minerDmg << endl << endl;
    cout << "A/D/R" << endl << endl;

    cout << R"(

              ,
          _,-""-._
        ,"        ".
       /    ,-,  ,"\
      "    /   \ | o|
      \    `-o-"  `-',
       `,   _.--'`'--`
         `--`---'            
           ,' '      
         ./ ,  `,            
         / /     \                O_\    
        (_)))_ _,"              (-'\
           _))))_,                / |
          (_,-._)))               |  \

        )";

    Sleep(500);
    system("cls");
}

void zombieAttack1()
{
    system("cls");

    cout << "Attack, Defend or Rest!" << endl << endl;
    cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
    cout << "ENEMY HP: " << minerHP << " ENEMY DMG: " << minerDmg << endl << endl;
    cout << "A/D/R" << endl << endl;

    cout << R"(

              ,
          _,-""-._
        ,"        ".
       /    ,-,  ,"\
      "    /   \ | o|
      \    `-o-"  `-',
       `,   _.--'`'--`
         `--`---'            
           ,' '      
         ./ ,  `,            
         / /     \                O_\    
        (_)))_ _,"           ---(-'\
           _))))_,                / |
          (_,-._)))               |  \

        )";

    Sleep(100);
    system("cls");
}

void zombieAttack2()
{
    cout << "Attack, Defend or Rest!" << endl << endl;
    cout << "DMG: " << playerDamage << " DEF: " << playerDefense << " HP: " << playerHealth << endl << endl;
    cout << "ENEMY HP: " << minerHP << " ENEMY DMG: " << minerDmg << endl << endl;
    cout << "A/D/R" << endl << endl;

    cout << R"(

              ,
          _,-""-._
        ,"        ".
       /    ,-,  ,"\
      "    /   \ | o|
      \    `-o-"  `-',
       `,   _.--'`'--`
         `--`---'            
           ,' '      
         ./ ,  `,            
         / /     \     O_\    
        (_)))_ _,"---(-'\
           _))))_,     / |
          (_,-._)))    |  \

        )";
    Sleep(100);
    system("cls");
}