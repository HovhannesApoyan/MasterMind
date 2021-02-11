#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "CPUPlayer.h"
#include "HumanConsolePlayer.h"
#include "MasterMind.h"

int inputComand();
void PrepareForANewGame();

int main()
{
	srand(time(nullptr));
	std::cout << "Welcome to Mastermind.\n";

	while (true)
	{
		system("cls");
		MasterMind::menu();
		switch (inputComand())
		{
		case comandToInt(Comand::new_game):
			//TODO
			break;
		case comandToInt(Comand::human_with_human):
		{
			HumanConsolePlayer h1("Armen");
			HumanConsolePlayer h2("Ashot");
			MasterMind g(&h1, &h2);
			std::cout << g.Play()->GetName();
			system("pause");
			break;
		}
		case comandToInt(Comand::human_with_computer):
		{
			HumanConsolePlayer h1("Armen");
			CPUPlayer c2("Jack");
			MasterMind g(&h1, &c2);
			std::cout << g.Play()->GetName();
			system("pause");
			break;
		}
		case comandToInt(Comand::computer):
			//TODO
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
	system("cls");
	return comand;
}

void PrepareForAGame()//TODO
{
	std::cout << "input remember number's 4 digits:";
	std::string line;
	getline(std::cin, line);
}