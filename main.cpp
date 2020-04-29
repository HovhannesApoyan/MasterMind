#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <windows.h>
#include <cctype>
#include "MasterMind.h"

MasterMind Master_Mind_Object();
int Input_Comand();

int main()
{
	MasterMind mind;
	while (true)
	{
		system("cls");
		mind.menu();
		switch (Input_Comand())
		{
		case mind.newGame:
			Master_Mind_Object().New_Game();
			break;
		case mind.twoPlayer:
			Master_Mind_Object().Two_Player();
			break;
		case mind.withComputer:
			Master_Mind_Object().With_Computer();
			break;
		case mind.computer:
			Master_Mind_Object().Play_Computer();
			break;
		case mind.quit:
			exit(0);
			break;
		default:
			std::cout << "Not correct command!!!\n";
			Sleep(300);
			break;
		}
	}
}

MasterMind Master_Mind_Object()
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
int Input_Comand()
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