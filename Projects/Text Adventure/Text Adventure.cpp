// Text Adventure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int aPlayerOneStats[3] = {100,100,100}; //(Health, Stamina, Mana) (Remove this after battle system is changed to use  class structures)

//Global Variables
	
	char PName[16];
	char sClassChoice[8] = "";
	char sMovement[10] = "";
	int iAction = 8;
	int iActionMod = 0;
	int iTarget = 0;
	int iMove = 0;

//Classes and Default Stats

struct Warrior
{
	int WHealth;
	int WStamina;
	int WStrength;
	int WDefence;
	int WMDefence;
	int WAccuracy;
	int WEvade;
};

void update(Warrior &W)
{
	W.WHealth = 140;
	W.WStamina = 100;
	W.WStrength = 5;
	W.WDefence = 5;
	W.WMDefence = 2;
	W.WAccuracy = 70;
	W.WEvade = 2;
}

struct Mage
{
	int MHealth;
	int MStamina;
	int MP;
	int MStrength;
	int MPStrength;
	int MDefence;
	int MMDefence;
	int MAccuracy;
	int MPAccuracy;
	int MEvade;
};

void update(Mage &M)
{
	M.MHealth = 100;
	M.MStamina = 100;
	M.MP = 100;
	M.MStrength = 2;
	M.MPStrength = 5;
	M.MDefence = 2;
	M.MMDefence = 5;
	M.MAccuracy = 50;
	M.MPAccuracy = 70;
	M.MEvade = 3;
}

struct Ranger
{
	int RHealth;
	int RStamina;
	int RStrength;
	int RDefence;
	int RMDefence;
	int RAccuracy;
	int REvade;
};

void update(Ranger &R)
{
	R.RHealth = 120;
	R.RStamina = 100;
	R.RStrength = 3;
	R.RDefence = 3;
	R.RMDefence = 3;
	R.RAccuracy = 70;
	R.REvade = 5;
}

int PlayerHealth;
int PlayerStamina;
int PlayerMana;
int PlayerStrength;
int PlayerMPStrength;
int PlayerDefence;
int PlayerMPDefence;
int PlayerAccuracy;
int PlayerMPAccuracy;
int PlayerCriticalChance;
int PlayerCriticalMulti;
int PlayerMPCriticalChance;
int PlayerMPCriticalMulti;
int PlayerEvade;


//Functions

void Walk ()
{
	cout << "Blah blah walking\n";
}

void Jump ()
{
	cout << "Blah blah jumping\n";
}

void Sleep ()
{
	cout << "Blah blah sleeping\n";  //Base Stamina = 100
	//playerstamina * 1.3
	if(aPlayerOneStats[1] > 100)
		aPlayerOneStats[1] = 100;
}

void Eat ()
{
	cout << "Blah blah eating\n";   //Base Health = 100
	//playerhealth + taberegen
	if(aPlayerOneStats[0] > 100)
		aPlayerOneStats[1] = 100;
}

void Drink ()
{
	cout << "Blah blah drinking\n";  //Base Mana = 100
	//playermp + nomuregen
	if(aPlayerOneStats[2] > 100)
		aPlayerOneStats[2] = 100;
}

void Attack ()
{
	//if(targetevade*playeraccuracy > randomnumber
	cout << "Blah blah attacking\n";
	aPlayerOneStats[1] -= 20;
	//targethealth -= 10(playerstrength)*(1-(targetdefence*.01))
}

void Run ()
{
	cout << "Blah blah running\n";
}

void Die ()
{
	cout << "You are dead fool\n";
	aPlayerOneStats[0] = 0;
}

void PBattlePhase ()
{
	//while(playerhealth > 0)
		{
		switch(iAction - iActionMod)
			{
				case 0:					
					Walk ();
					break;
				case 1:
					Jump ();
					break;
				case 2:
					if(aPlayerOneStats[1] >= 20)
						Attack ();
					else
						cout << "\nNot enough stamina fool!\n";			
					break;
				case 3:
					Sleep ();
					break;
				case 4:
					Eat ();
					break;
				case 5:
					Drink ();
					break;
				case 6:
					Run ();
					break;
				case 7:
					Die ();
					break;
				default:
					cout << "Error, enter valid command\n";
			}
		}
}

int _tmain(int argc, _TCHAR* argv[])
{	 
	
	cout << "Choose Your Class!\n(Warrior, Mage, Ranger)\n" << endl;
	cin.getline(sClassChoice, 8);
	cout << "\n";
				
	cout << "Enter Your Name!\n";
	cin.clear();
	cout << "\n";
	cin.getline(PName,16);
	cout << "\n";
	
	cout << "Welcome to 'Sanzakar' " << PName << "!" << "\n" << endl;
		
	cout << "Home\n";
	cout << "Training Hall\n";
	cout << "Dark Forest\n";
	cout << "Royal Castle\n" ;
	cout << "Zorada Guild\n";
	cout << "Where will you go?\n" << endl;
	cin.getline(sMovement,10);
	cout << "\n";

	switch(sMovement[0])
	{
		case 'T':
			cout << "Welcome to the Training Hall!\nHow would you like to train today " << PName << "?" << "\n" << endl;
			cout << "Attack, Defense, Stamina, Evade, Accuracy, Critical Chance, Critical Multiplier.\n" ; 
			break;
		case 'D':
			cout << "Blah Dark Forest... So scary.\n" << endl;
			break;
		case 'R':
			cout << "Something about Royalty and shit, blah blah peasant.\n" << endl;
			break;
		case 'Z':
			//if(playerlevel > 10)
				//cout << "Something about joining guild or something idk.\n" << endl;
			//else
				//cout << "You are not a high enough level.\n"
			break;
		default:
			cout << "Invalid input\n";
			break;
	}
		
	
	return 0;
}

