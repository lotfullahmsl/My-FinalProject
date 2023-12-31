#include <iostream>
#include <string>
#include<cstdlib> // we are using this for generating random numbers
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")


using namespace std;
struct character_info_struct {
    string name;
    char character_class;
};
int Character_full_health = 100;
int Character_remaining_health = Character_full_health;
int Enemy_full_health = 100;
int Enemy_remaning_health = Enemy_full_health;

//World of Giant 
void Stone_Giant(const character_info_struct character_info, char& user_choice);
void Fire_Giant(const character_info_struct character_info, char& user_choice);

void warrior_specifications();
void mage_specifications();
void rogue_specifications();
void character_information(const character_info_struct character_info);
void main_menu(char& user_choice);

int main() {
    character_info_struct character_info; // structure for character information
    char user_choice, run; // initialization for user input and rerunning the game
    char attacking_choice; // asking for embarking on a quest
    char embarking_on_quest;
    
    cout << "\n\t\t\tWelcome to Realm of Legends!\n";

    do {
        main_menu(user_choice);
        system("cls");

        if (user_choice == '1') {
            character_information(character_info);
            string storyline = "\n\n\tIn this land of Eldoria, a prophecy says you're the hero."
                "\n\tUse the old (Power Crystal). Pick warrior, mage, or rogue."
                "\n\tFight mythical challenges, shape your story"
                "\n\twith each choice. Level up, get powers, and choose realm fates."
                "\n\tBe the hero Eldoria wants in the epic Realm of Legends. Your story awaits!\n";
            cout << endl;

            cout << " ";
            for (int i = 1; i <= storyline.length(); ++i) {
                cout << storyline[i];
                Sleep(20);
            }

            string first_level = "\n\n\tWelcome to the World of Giants...\n\tIn this level, there are three different objectives.\n";
            cout << " ";
            for (int i = 1; i <= first_level.length(); ++i) {
                cout << first_level[i];
                Sleep(20);
            }

            cout << "\t1. Attack \n\t2. Main Menu \n\t3. Exit\n\tYour Choice: ";
            cin >> attacking_choice;

            if (attacking_choice == '1') {

                character_information(character_info);
                cout << "\n\t1. Stone Giant \n\t2. Fire Giant \n\t3. Hill Giant \n\tChoose Your Enemy: ";
                cin >> embarking_on_quest;
                if (embarking_on_quest == '1')
                {
                    Stone_Giant(character_info, run);
                    while (run == 'a');
                    system("cls");
                }
                else if (embarking_on_quest == '2') {
                    Fire_Giant(character_info, run);
                    while (run == 'a');
                    system("cls");
                }

            }


        }


        else if (user_choice == '2') {
            cout << "\n\tEnter Name of Your Character: ";
            getline(cin, character_info.name);

            cout << "\n\tChoose Your Character Class \n\t1. Warrior \n\t2. Mage \n\t3. Rogue \n\tChoose Class: ";
            cin >> character_info.character_class;
            cin.ignore();
            character_information(character_info);
            cout << "\n\tCharacter Created!\n\n";
        }
        else if (user_choice == '3') {
            cout << "\n\tGame Ended!\n\n";
            return 0;
        }
        else {
            cout << "\n\tInvalid Input";
        }
        cout << "\tPress 'a' to continue...";
        cin >> run;
        system("cls");
    } while (run == 'a');
}

void warrior_specifications() {
    int experience = 0;
    string char_class = "Warrior";
    cout << "\n\tYour Character Class is: " << char_class << endl;
    cout << "\tYour Experience Points are: " << experience << endl;
}

void mage_specifications() {
    int experience = 0;
    string char_class = "Mage";
    cout << "\tYour Character Class is: " << char_class << endl;
    cout << "\tYour Experience Points are: " << experience << endl;
}

void rogue_specifications() {
    int experience = 0;
    string char_class = "Rogue";
    cout << "\n\tYour Character Class is: " << char_class << endl;
    cout << "\tYour Experience Points are: " << experience << endl;
}

// In the parameter below, we add constant because we want that our
// structure shouldn't be modified by the character_information function
// and I am passing it by value because our structure is not too much big and it's simple
// if we call it by reference, it will still work but in the coming section, I will need some accuracy to 
// avoid changing the original data

void character_information(const character_info_struct character_info) {
    if (character_info.character_class == '1') {
        cout << "\n\tYour Character Name is: " << character_info.name;
        warrior_specifications();
        cout << "\tyour health is: " << Character_remaining_health << endl;
    }
    else if (character_info.character_class == '2') {
        cout << "\n\tYour Character Name is: " << character_info.name;
        cout << endl;
        mage_specifications();
        cout << "\tyour health is: " << Character_remaining_health << endl;
    }
    else if (character_info.character_class == '3') {
        cout << "\n\tYour Character Name is: " << character_info.name;
        rogue_specifications();
        cout << "\tyour health is: " << Character_remaining_health << endl;
    }
    else {
        cout << "\n\tInvalid Input!";
    }
}

void main_menu(char& user_choice) {
    cout << "\n\tMain Menu\n\t1. Start the Game \n\t2. Create a Character \n\t3. Exit \n\tEnter Choice: ";
    cin >> user_choice;
    cin.ignore();
}

// Level 1 Enemies

void Stone_Giant(const character_info_struct character_info, char& user_choice) {
    char run;
    do {
        // Character turn to attack
        cout << "\n\t" << character_info.name << " is attacking...\n";
        int Enemy_reduced_health = (rand() % 20);
        if (Enemy_reduced_health >= 15) {
            
            cout << "\t\t\t\t\t\tWOW, Great Shot!\n";
        }
        cout << "\tDamage is: " << Enemy_reduced_health << endl;

        Enemy_remaning_health = Enemy_remaning_health - Enemy_reduced_health;
        if (Enemy_remaning_health >= 0)
        {
            cout << "\tEnemy Remaining Health is: " << Enemy_remaning_health << endl;
        }
        if (Enemy_remaning_health <= 0) {
            system("cls");
            cout << "\tEnemy Down!\n";
            cout << "\tYou defeated the enemy!\n";
            cout << "\tPress 'a' to continue or any other Key to exit: ";
            cin >> run;

            if (run == 'a') {
                main_menu(user_choice);
            }
            else {
                break;
            }

        }


        // Enemy's turn to attack
        cout << "\n\tEnemy is attacking...\n";
        int Character_reduced_health = (rand() % 10);

        cout << "\tEnemy Damage to you is: " << Character_reduced_health << endl;
        Character_remaining_health = Character_remaining_health - Character_reduced_health;

        if (Character_remaining_health >= 0)
        {
            cout << "\tYour Remaining Health is: " << Character_remaining_health << endl;
        }

        cout << "\n\tPress 'a' to continue attacking, or any other key to stop: ";
        cin >> run;

        if (run != 'a') break;  // Break loop if player chooses to stop
        if (Character_remaining_health <= 0) {
            cout << "\tYou were defeated by the enemy.\n";
            main_menu(user_choice);
        }
        if (Enemy_remaning_health <= 0) {
            cout << "You Won!";
        }

    } while (run == 'a');

}
void Fire_Giant(const character_info_struct character_info, char& user_choice) {
    char run;
    do {
        // Character turn to attack
        cout << "\n\t" << character_info.name << " is attacking...\n";
        int Enemy_reduced_health = (rand() % 30);
        if (Enemy_reduced_health >= 10) {
            cout << "\t\t\t\t\t\tWOW, Great Shot!\n";
        }
        cout << "\tDamage is: " << Enemy_reduced_health << endl;

        Enemy_remaning_health = Enemy_remaning_health - Enemy_reduced_health;
        if (Enemy_remaning_health >= 0)
        {
            cout << "\tEnemy Remaining Health is: " << Enemy_remaning_health << endl;
        }
        if (Enemy_remaning_health <= 0) {
            system("cls");
            cout << "\tEnemy Down!\n";
            cout << "\tYou defeated the enemy!\n";
            cout << "\tPress 'a' to continue or any other Key to exit: ";
            cin >> run;
            if (run == 'a') {
                main_menu(user_choice);
            }
            else {
                break;
            }

        }



        // Enemy's turn to attack
        cout << "\n\tEnemy is attacking...\n";
        int Character_reduced_health = (rand() % 30);

        cout << "\tEnemy Damage to you is: " << Character_reduced_health << endl;
        Character_remaining_health = Character_remaining_health - Character_reduced_health;

        if (Character_remaining_health >= 0)
        {
            cout << "\tYour Remaining Health is: " << Character_remaining_health << endl;
        }
        cout << "\n\tPress 'a' to continue attacking, or any other key to stop: ";
        cin >> run;

        if (run != 'a') break;  // Break loop if player chooses to stop
        if (Character_remaining_health <= 0) {
            cout << "\tYou were defeated by the enemy.\n";
            main_menu(user_choice);
        }
        if (Enemy_remaning_health <= 0) {
            cout << "You Won!";
        }

    } while (run == 'a');
}