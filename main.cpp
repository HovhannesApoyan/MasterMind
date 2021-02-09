#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <windows.h>
#include <cctype>
#include "MasterMind.h"

MasterMind masterMindObject();
int inputComand();

int main()
{
	MasterMind mind;
	while (true)
	{
		system("cls");
		mind.menu();
		switch (inputComand())
		{
		case comandToInt(Comand::new_game):
			masterMindObject().newGame();
			break;
		case comandToInt(Comand::two_player):
			masterMindObject().twoPlayer();
			break;
		case comandToInt(Comand::with_computer):
			masterMindObject().withComputer();
			break;
		case comandToInt(Comand::computer):
			masterMindObject().playComputer();
			break;
		case comandToInt(Comand::quit):
			exit(0);
			break;
		default:
			std::cout << "Not correct command!!!\n";
			Sleep(300);
			break;
		}
	}
}

MasterMind masterMindObject()
{
	system("cls");
	int n;
	std::cout << std::setw(10) << "The digits are from (2;6).\n";
	do {
		std::cout << "input count digits: ";
		std::cin >> n;
	} while (n <= 1 || n >= 7);
	return MasterMind(n);
}

int inputComand()
{
	std::string str;
	int comand;
	do { getline(std::cin, str); } while (str.empty());
	bool b = std::find_if(str.begin(), str.end(), ispunct) == str.end() && std::find_if(str.begin(), str.end(), isalpha) == str.end() && std::find_if(str.begin(), str.end(), isdigit) != str.end();
	if (!str.empty() && b)
	{
		comand = stoi(str);
	}
	else
	{
		comand = -1;
	}
	return comand;
}