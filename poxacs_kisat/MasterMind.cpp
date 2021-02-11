#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <time.h>
#include "MasterMind.h"


void MasterMind::PrepareForANewGame()
{
	auto name1 = players[0]->getName();
	auto name2 = players[1]->getName();
	if (name1.empty() || name2.empty() || name1 == name2)
	{
		throw std::logic_error("One of the players has empty name or both players have the same name");
	}
	for (auto p : players)
	{
		p->prepareForANewGame();
	}
}

IPlayer* MasterMind::Play()
{
	try
	{
		PrepareForANewGame();
		int turn = rand() % 2;

		int opponent = 1 - turn;
		for (;; std::swap(turn, opponent))
		{

			//ToDo add try catch at each of player's moves and make the throwing player lose
			auto guess = players[turn]->MakeAGuess();

			//ToDo add try catch at each of player's moves and make the throwing player lose
			auto matchres = players[opponent]->Reply(guess);

			if (matchres.IsAWin())
			{
				return players[turn];
			}


			//ToDo add try catch at each of player's moves and make the throwing player lose
			bool cheating = !players[turn]->ProcessResult(guess, matchres);


			if (cheating)
			{
				std::cout << boost::format("player %1% suspects player %2% in cheating") % players[turn]->getName() % players[opponent]->getName();
			}
		}
		return nullptr;
	}
	catch (std::exception& e)
	{
		std::cout << boost::format("exception thrown in Play() function: %1%") % e.what();
		throw;
	}
}










//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MasterMind::MasterMind()
//	:count_digits(0)
//	, size_numbers(0)
//	, numbers(0)
//{
//	std::cout << numbers.size();
//}
//MasterMind::MasterMind(const int& n)
//	: count_digits(n)
//	, size_numbers(pow(10, count_digits))
//	, numbers(size_numbers)
//{
//
//}
//void MasterMind::generateNDigitNumbers()
//{
//	int size = size_numbers / 10;
//	int count = 0;
//	for (int i = size_numbers; i < size_numbers + size; ++i) {
//		std::string str = std::to_string(i);
//		for (int j = 1; j < str.size(); ++j)
//		{
//			numbers[count].push_back((static_cast<int>(str[j])) - '0');
//		}
//		++count;
//	}
//	for (int i = size_numbers / 10; i < size_numbers; ++i) {
//		std::string str = std::to_string(i);
//		for (int j = 0; j < str.size(); ++j)
//		{
//			numbers[count].push_back((static_cast<int>(str[j])) - '0');
//		}
//		++count;
//	}
//}
//const std::vector<int>& MasterMind::randomNumber() const
//{
//	srand(time(0));
//	int index = rand() % size_numbers;
//	return numbers[index];
//}
//void MasterMind::printNumbers() const
//{
//	for (int i = 0; i < numbers.size(); i++) {
//		for (auto j = numbers[i].begin(); j != numbers[i].end(); ++j)
//			std::cout << *j << " ";
//		std::cout << "\n";
//	}
//}
//void MasterMind::newGame()
//{
//	system("cls");
//	generateNDigitNumbers();
//	std::vector<int> rememberedNumber = randomNumber();
//	std::vector<std::string> firstInfo;
//	system("cls");
//	int iteracia = 0;
//	while (iteracia < 20)
//	{
//		bool firstPlayer = false;
//		std::cout << "input your number's digits: ";
//		std::string firstNumberStr;
//		std::vector<int> currentNumber;
//		inputNumber(currentNumber, firstNumberStr);
//		firstInfo.push_back(firstNumberStr);
//
//		int countCorrectPosition;
//		int countCorrectDigit;
//		firstPlayer = numbersCheck(currentNumber, rememberedNumber, firstInfo
//			, countCorrectDigit, countCorrectPosition);
//		std::cout << countCorrectDigit << " : " << countCorrectPosition << "\n";
//
//		if (firstPlayer)
//		{
//			std::cout << "\tWinner!!!\n";
//			system("pause");
//			system("cls");
//			break;
//		}
//		++iteracia;
//	}
//	if (iteracia >= 20)
//	{
//		std::cout << "\tDefeat!!!\n";
//		system("pause");
//		system("cls");
//	}
//}
//void MasterMind::twoPlayer()
//{
//	system("cls");
//	generateNDigitNumbers();
//	std::vector<int> rememberedNumber = randomNumber();
//	std::vector<std::string> firstInfo;
//	std::vector<std::string> secondInfo;
//	system("cls");
//	int iteracia = 0;
//	while (iteracia < 20)
//	{
//		bool first = false;
//		bool second = false;
//
//		if (!firstInfo.empty())
//		{
//			for (int i = 0; i < firstInfo.size(); ++i)
//			{
//				std::cout << firstInfo[i] << "\n";
//			}
//		}
//
//		std::cout << "input first number's digits: ";
//		int firstCountCorrectDigit;
//		int firstCountCorrectPosition;
//		std::vector<int> firstCurrentNumber;
//		std::string firstNumberStr;
//		inputNumber(firstCurrentNumber, firstNumberStr);
//		firstInfo.push_back(firstNumberStr);
//		first = numbersCheck(firstCurrentNumber, rememberedNumber, firstInfo
//			, firstCountCorrectDigit, firstCountCorrectPosition);
//		std::cout << firstCountCorrectDigit << " : " << firstCountCorrectPosition << "\n";
//		system("pause");
//		system("cls");
//
//		//second
//		if (!secondInfo.empty())
//		{
//			for (int i = 0; i < secondInfo.size(); ++i)
//			{
//				std::cout << secondInfo[i] << "\n";
//			}
//		}
//		std::cout << "input second number's digits: ";
//		int secondCountCorrectDigit = 0;
//		int secondCountCorrectPosition = 0;
//		std::vector<int> secondCurrentNumber;
//		std::string secondNumberStr;
//		inputNumber(secondCurrentNumber, secondNumberStr);
//		secondInfo.push_back(secondNumberStr);
//		second = numbersCheck(secondCurrentNumber, rememberedNumber, secondInfo
//			, secondCountCorrectDigit, secondCountCorrectPosition);
//		++iteracia;
//		std::cout << secondCountCorrectDigit << " : " << secondCountCorrectPosition << "\n";
//		system("pause");
//		system("cls");
//
//		if (first && second)
//		{
//			std::cout << "\tDraw!!!\n";
//			system("pause");
//			system("cls");
//			break;
//		}
//		else if (first && !second)
//		{
//			std::cout << "\tFirst player winner!!!\n";
//			system("pause");
//			system("cls");
//			break;
//		}
//		else if (!first && second)
//		{
//			std::cout << "\tSecond player winner!!!\n";
//			system("pause");
//			system("cls");
//			break;
//		}
//	}
//	if (iteracia >= 20)
//	{
//		std::cout << "\tDefeat!!!\n";
//		system("pause");
//		system("cls");
//	}
//}
//void MasterMind::withComputer()
//{
//	system("cls");
//	std::vector<std::string> firstInfo;
//	std::vector<std::string> secondInfo;
//	generateNDigitNumbers();
//	std::vector<int> rememberedNumber = randomNumber();
//	std::vector<std::vector<int>> computer = getNumbers();
//	system("cls");
//
//	int iteracia = 0;
//	while (iteracia < 20)
//	{
//		bool first = false;
//		bool second = false;
//		if (!firstInfo.empty())
//		{
//			for (int i = 0; i < firstInfo.size(); ++i)
//			{
//				std::cout << firstInfo[i] << "\n";
//			}
//		}
//		std::cout << "input your number's digits: ";
//		int firstCountCorrectDigit = 0;
//		int firstCountCorrectPosition = 0;
//		std::vector<int> firstCurrentNumber;
//		std::string firstNumberStr;
//		inputNumber(firstCurrentNumber, firstNumberStr);
//		firstInfo.push_back(firstNumberStr);
//		first = numbersCheck(firstCurrentNumber, rememberedNumber, firstInfo
//			, firstCountCorrectDigit, firstCountCorrectPosition);
//		std::cout << firstCountCorrectDigit << " : " << firstCountCorrectPosition << "\n";
//		system("pause");
//		system("cls");
//
//		//computer
//		std::cout << "The computer is playing . . .\n";
//		int computerCountCorrectDigit = 0;
//		int computerCountCorrectPosition = 0;
//		srand(time(0));
//		int index = rand() % computer.size();
//		std::vector<int> secondCurrentNumber = computer[index];
//		second = numbersCheck(secondCurrentNumber, rememberedNumber, secondInfo
//			, computerCountCorrectDigit, computerCountCorrectPosition);
//		if (!second)
//		{
//			updateList(computer, secondCurrentNumber, secondInfo[secondInfo.size() - 1]);
//		}
//		std::cout << "The computer was played.\n";
//		system("pause");
//		system("cls");
//
//		if (first && second)
//		{
//			std::cout << "\tDraw!!!\n";
//			system("pause");
//			system("cls");
//			break;
//		}
//		else if (first && !second)
//		{
//			std::cout << "\tYou are a winner!!!\n";
//			system("pause");
//			system("cls");
//			break;
//		}
//		else if (!first && second)
//		{
//			std::cout << "\tComputer is winner!!!\n";
//			system("pause");
//			system("cls");
//			break;
//		}
//		++iteracia;
//	}
//	if (iteracia >= 20)
//	{
//		std::cout << "\tDefeat!!!\n";
//		system("pause");
//		system("cls");
//	}
//}
//void MasterMind::playComputer()
//{
//	system("cls");
//	std::vector<int> rememberedNumber;
//	std::string str;
//	std::cout << "input remember number's digits: ";
//	inputNumber(rememberedNumber, str);
//	std::vector<std::string> Info_History;
//	Info_History.push_back(str);
//	generateNDigitNumbers();
//	std::vector<std::vector<int>> computer = getNumbers();
//
//	system("cls");
//	int iteracia = 0;
//	while (iteracia < 20)
//	{
//		std::cout << "input number's digits: ";
//		srand(time(0));
//		int index = rand() % computer.size();
//		std::vector<int> currentNumber = computer[index];
//		for (int i = 0; i < this->count_digits; ++i)
//		{
//			std::cout << currentNumber[i] << " ";
//		}
//		std::cout << "\n";
//		int countCorrectDigit;
//		std::cin >> countCorrectDigit;
//		char x;
//		std::cin >> x;
//		int countCorrectPosition;
//		std::cin >> countCorrectPosition;
//
//		std::string Infodig = std::to_string(countCorrectDigit);
//		Infodig += " : ";
//		std::string str1 = std::to_string(countCorrectPosition);
//		Infodig.push_back(str1[0]);
//		Info_History.push_back(Infodig);
//
//		if (countCorrectDigit == this->count_digits && countCorrectPosition == this->count_digits)
//		{
//			std::cout << "\tComputer is Winner!!!\n";
//			system("pause");
//			system("cls");
//			break;
//		}
//		else
//		{
//			updateList(computer, currentNumber, Info_History[Info_History.size() - 1]);
//		}
//		++iteracia;
//	}
//	if (iteracia >= 20)
//	{
//		std::cout << "\tDefeat!!!\n";
//		system("pause");
//		system("cls");
//	}
//}
//void MasterMind::menu()
//{
//	std::cout << std::setw(15) << Comand::new_game << " - New Game\n";
//	std::cout << std::setw(15) << Comand::two_player << " - 2 Player\n";
//	std::cout << std::setw(15) << Comand::with_computer << " - With Computer\n";
//	std::cout << std::setw(15) << Comand::computer << " - Computer\n";
//	std::cout << std::setw(15) << Comand::quit << " - Exit\n";
//}
//void MasterMind::inputNumber(std::vector<int>& CurrentNumber, std::string& str)
//{
//	for (int i = 0; i < this->count_digits; ++i)
//	{
//		int digit;
//		std::cin >> digit;
//		CurrentNumber.push_back(digit);
//		std::string s1 = std::to_string(digit);
//		str.push_back(s1[0]);
//	}
//}
//const int MasterMind::intersection(const std::vector<int>& rememberedNumber, const std::vector<int>& CurrentNumber) const
//{
//	std::vector<int> sortRememberedNumber = rememberedNumber;
//	std::vector<int> sortCurrentNumber = CurrentNumber;
//	std::stable_sort(sortRememberedNumber.begin(), sortRememberedNumber.end());
//	std::stable_sort(sortCurrentNumber.begin(), sortCurrentNumber.end());
//	std::vector<int> firstIntersec;
//	std::set_intersection(sortRememberedNumber.begin(), sortRememberedNumber.end()
//		, sortCurrentNumber.begin(), sortCurrentNumber.end(), std::back_inserter(firstIntersec));
//	return firstIntersec.size();
//}
//bool MasterMind::numbersCheck(const std::vector<int>& CurrentNumber
//	, const std::vector<int>& rememberedNumber, std::vector<std::string>& Info
//	, int& CountCorrectDigit, int& CountCorrectPosition)
//{
//	bool b = false;
//	CountCorrectPosition = 0;
//	for (int j = 0; j < this->count_digits; ++j)
//	{
//		if (CurrentNumber[j] == rememberedNumber[j])
//			++CountCorrectPosition;
//	}
//	CountCorrectDigit = intersection(rememberedNumber, CurrentNumber);
//
//	if (CountCorrectDigit == this->count_digits && CountCorrectPosition == this->count_digits)
//	{
//		b = true;
//	}
//	std::string Infodig = std::to_string(CountCorrectDigit);
//	Infodig += " : ";
//	std::string str1 = std::to_string(CountCorrectPosition);
//	Infodig.push_back(str1[0]);
//	Info.push_back(Infodig);
//	return b;
//}
//void MasterMind::updateList(std::vector<std::vector<int>>& list
//	, std::vector<int>& CurrentNumber, std::string& Info)
//{
//	std::vector<std::vector<int>> CurrentList;
//	int Digit = Info[0] - '0';
//	int Position = Info[Info.size() - 1] - '0';
//	for (int i = 0; i < list.size(); ++i)
//	{
//		int CountCorrectPosition = 0;
//		for (int j = 0; j < this->count_digits; ++j)
//		{
//			if (CurrentNumber[j] == list[i][j])
//				++CountCorrectPosition;
//		}
//		int CountCorrectDigit = intersection(CurrentNumber, list[i]);
//		if (CountCorrectDigit == Digit && CountCorrectPosition == Position)
//		{
//			CurrentList.push_back(list[i]);
//		}
//	}
//	list = CurrentList;
//}
//MasterMind::~MasterMind()
//{
//}
//const std::vector<std::vector<int>>& MasterMind::getNumbers() const
//{
//	return numbers;
//}