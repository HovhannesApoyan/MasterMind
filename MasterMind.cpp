#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include<time.h>
#include "MasterMind.h"

MasterMind::MasterMind()
	:countDigits(0)
	, sizeNumbers(0)
	, numbers(0)
{
	std::cout << numbers.size();
}
MasterMind::MasterMind(const int& n)
	: countDigits(n)
	, sizeNumbers(pow(10, countDigits))
	, numbers(sizeNumbers)
{

}
void MasterMind::generateNDigitNumbers()
{
	int size = sizeNumbers / 10;
	int count = 0;
	for (int i = sizeNumbers; i < sizeNumbers + size; ++i) {
		std::string str = std::to_string(i);
		for (int j = 1; j < str.size(); ++j)
		{
			numbers[count].push_back((static_cast<int>(str[j])) - '0');
		}
		++count;
	}
	for (int i = sizeNumbers / 10; i < sizeNumbers; ++i) {
		std::string str = std::to_string(i);
		for (int j = 0; j < str.size(); ++j)
		{
			numbers[count].push_back((static_cast<int>(str[j])) - '0');
		}
		++count;
	}
}
const std::vector<int>& MasterMind::randomNumber() const
{
	srand(time(0));
	int index = rand() % sizeNumbers;
	return numbers[index];
}
void MasterMind::printNumbers() const
{
	for (int i = 0; i < numbers.size(); i++) {
		for (auto j = numbers[i].begin(); j != numbers[i].end(); ++j)
			std::cout << *j << " ";
		std::cout << "\n";
	}
}
void MasterMind::New_Game()
{
	system("cls");
	generateNDigitNumbers();
	std::vector<int> rememberedNumber = randomNumber();
	std::vector<std::string> firstInfo;
	system("cls");
	int iteracia = 0;
	while (iteracia < 20)
	{
		bool firstPlayer = false;
		std::cout << "input your number's digits: ";
		std::string firstNumberStr;
		std::vector<int> currentNumber;
		input_Number(currentNumber, firstNumberStr);
		firstInfo.push_back(firstNumberStr);

		int countCorrectPosition;
		int countCorrectDigit;
		firstPlayer = Numbers_Check(currentNumber, rememberedNumber, firstInfo
			, countCorrectDigit, countCorrectPosition);
		std::cout << countCorrectDigit << " : " << countCorrectPosition << "\n";

		if (firstPlayer)
		{
			std::cout << "\tWinner!!!\n";
			system("pause");
			system("cls");
			break;
		}
		++iteracia;
	}
	if (iteracia >= 20)
	{
		std::cout << "\tDefeat!!!\n";
		system("pause");
		system("cls");
	}
}
void MasterMind::Two_Player()
{
	system("cls");
	generateNDigitNumbers();
	std::vector<int> rememberedNumber = randomNumber();
	std::vector<std::string> firstInfo;
	std::vector<std::string> secondInfo;
	system("cls");
	int iteracia = 0;
	while (iteracia < 20)
	{
		bool first = false;
		bool second = false;

		if (!firstInfo.empty())
		{
			for (int i = 0; i < firstInfo.size(); ++i)
			{
				std::cout << firstInfo[i] << "\n";
			}
		}

		std::cout << "input first number's digits: ";
		int firstCountCorrectDigit;
		int firstCountCorrectPosition;
		std::vector<int> firstCurrentNumber;
		std::string firstNumberStr;
		input_Number(firstCurrentNumber, firstNumberStr);
		firstInfo.push_back(firstNumberStr);
		first = Numbers_Check(firstCurrentNumber, rememberedNumber, firstInfo
			, firstCountCorrectDigit, firstCountCorrectPosition);
		std::cout << firstCountCorrectDigit << " : " << firstCountCorrectPosition << "\n";
		system("pause");
		system("cls");

		//second
		if (!secondInfo.empty())
		{
			for (int i = 0; i < secondInfo.size(); ++i)
			{
				std::cout << secondInfo[i] << "\n";
			}
		}
		std::cout << "input second number's digits: ";
		int secondCountCorrectDigit = 0;
		int secondCountCorrectPosition = 0;
		std::vector<int> secondCurrentNumber;
		std::string secondNumberStr;
		input_Number(secondCurrentNumber, secondNumberStr);
		secondInfo.push_back(secondNumberStr);
		second = Numbers_Check(secondCurrentNumber, rememberedNumber, secondInfo
			, secondCountCorrectDigit, secondCountCorrectPosition);
		++iteracia;
		std::cout << secondCountCorrectDigit << " : " << secondCountCorrectPosition << "\n";
		system("pause");
		system("cls");

		if (first && second)
		{
			std::cout << "\tDraw!!!\n";
			system("pause");
			system("cls");
			break;
		}
		else if (first && !second)
		{
			std::cout << "\tFirst player winner!!!\n";
			system("pause");
			system("cls");
			break;
		}
		else if (!first && second)
		{
			std::cout << "\tSecond player winner!!!\n";
			system("pause");
			system("cls");
			break;
		}
	}
	if (iteracia >= 20)
	{
		std::cout << "\tDefeat!!!\n";
		system("pause");
		system("cls");
	}
}
void MasterMind::With_Computer()
{
	system("cls");
	std::vector<std::string> firstInfo;
	std::vector<std::string> secondInfo;
	generateNDigitNumbers();
	std::vector<int> rememberedNumber = randomNumber();
	std::vector<std::vector<int>> computer = getNumbers();
	system("cls");

	int iteracia = 0;
	while (iteracia < 20)
	{
		bool first = false;
		bool second = false;
		if (!firstInfo.empty())
		{
			for (int i = 0; i < firstInfo.size(); ++i)
			{
				std::cout << firstInfo[i] << "\n";
			}
		}
		std::cout << "input your number's digits: ";
		int firstCountCorrectDigit = 0;
		int firstCountCorrectPosition = 0;
		std::vector<int> firstCurrentNumber;
		std::string firstNumberStr;
		input_Number(firstCurrentNumber, firstNumberStr);
		firstInfo.push_back(firstNumberStr);
		first = Numbers_Check(firstCurrentNumber, rememberedNumber, firstInfo
			, firstCountCorrectDigit, firstCountCorrectPosition);
		std::cout << firstCountCorrectDigit << " : " << firstCountCorrectPosition << "\n";
		system("pause");
		system("cls");

		//computer
		std::cout << "The computer is playing . . .\n";
		int computerCountCorrectDigit = 0;
		int computerCountCorrectPosition = 0;
		srand(time(0));
		int index = rand() % computer.size();
		std::vector<int> secondCurrentNumber = computer[index];
		second = Numbers_Check(secondCurrentNumber, rememberedNumber, secondInfo
			, computerCountCorrectDigit, computerCountCorrectPosition);
		if (!second)
		{
			Update_List(computer, secondCurrentNumber, secondInfo[secondInfo.size() - 1]);
		}
		std::cout << "The computer was played.\n";
		system("pause");
		system("cls");

		if (first && second)
		{
			std::cout << "\tDraw!!!\n";
			system("pause");
			system("cls");
			break;
		}
		else if (first && !second)
		{
			std::cout << "\tYou are a winner!!!\n";
			system("pause");
			system("cls");
			break;
		}
		else if (!first && second)
		{
			std::cout << "\tComputer is winner!!!\n";
			system("pause");
			system("cls");
			break;
		}
		++iteracia;
	}
	if (iteracia >= 20)
	{
		std::cout << "\tDefeat!!!\n";
		system("pause");
		system("cls");
	}
}
void MasterMind::Play_Computer()
{
	system("cls");
	std::vector<int> rememberedNumber;
	std::string str;
	std::cout << "input remember number's digits: ";
	input_Number(rememberedNumber, str);
	std::vector<std::string> Info_History;
	Info_History.push_back(str);
	generateNDigitNumbers();
	std::vector<std::vector<int>> computer = getNumbers();

	system("cls");
	int iteracia = 0;
	while (iteracia < 20)
	{
		std::cout << "input number's digits: ";
		srand(time(0));
		int index = rand() % computer.size();
		std::vector<int> currentNumber = computer[index];

		for (int i = 0; i < this->countDigits; ++i)
		{
			std::cout << currentNumber[i] << " ";
		}
		std::cout << "\n";
		int countCorrectDigit;
		std::cin >> countCorrectDigit;
		char x;
		std::cin >> x;
		int countCorrectPosition;
		std::cin >> countCorrectPosition;

		std::string Infodig = std::to_string(countCorrectDigit);
		Infodig += " : ";
		std::string str1 = std::to_string(countCorrectPosition);
		Infodig.push_back(str1[0]);
		Info_History.push_back(Infodig);

		if (countCorrectDigit == this->countDigits && countCorrectPosition == this->countDigits)
		{
			std::cout << "\tComputer is Winner!!!\n";
			system("pause");
			system("cls");
			break;
		}
		else
		{
			Update_List(computer, currentNumber, Info_History[Info_History.size() - 1]);
		}
		++iteracia;
	}
	if (iteracia >= 20)
	{
		std::cout << "\tDefeat!!!\n";
		system("pause");
		system("cls");
	}
}
void MasterMind::menu()
{
	std::cout << std::setw(15) << newGame << " - New Game\n";
	std::cout << std::setw(15) << twoPlayer << " - 2 Player\n";
	std::cout << std::setw(15) << withComputer << " - With Computer\n";
	std::cout << std::setw(15) << computer << " - Computer\n";
	std::cout << std::setw(15) << quit << " - Exit\n";
}
void MasterMind::input_Number(std::vector<int>& CurrentNumber, std::string& str)
{
	for (int i = 0; i < this->countDigits; ++i)
	{
		int digit;
		std::cin >> digit;
		CurrentNumber.push_back(digit);
		std::string s1 = std::to_string(digit);
		str.push_back(s1[0]);
	}
}
bool MasterMind::Numbers_Check(const std::vector<int>& CurrentNumber
	, const std::vector<int>& rememberedNumber, std::vector<std::string>& Info
	, int& CountCorrectDigit, int& CountCorrectPosition)
{
	bool b = false;
	CountCorrectPosition = 0;
	for (int j = 0; j < this->countDigits; ++j)
	{
		if (CurrentNumber[j] == rememberedNumber[j])
			++CountCorrectPosition;
	}
	std::vector<int> sortRememberedNumber = rememberedNumber;
	std::vector<int> sortCurrentNumber = CurrentNumber;
	std::stable_sort(sortRememberedNumber.begin(), sortRememberedNumber.end());
	std::stable_sort(sortCurrentNumber.begin(), sortCurrentNumber.end());
	std::vector<int> firstIntersec;
	std::set_intersection(sortRememberedNumber.begin(), sortRememberedNumber.end()
		, sortCurrentNumber.begin(), sortCurrentNumber.end(), std::back_inserter(firstIntersec));
	CountCorrectDigit = firstIntersec.size();

	if (CountCorrectDigit == this->countDigits && CountCorrectPosition == this->countDigits)
	{
		b = true;
	}
	std::string Infodig = std::to_string(CountCorrectDigit);
	Infodig += " : ";
	std::string str1 = std::to_string(CountCorrectPosition);
	Infodig.push_back(str1[0]);
	Info.push_back(Infodig);
	return b;
}
void MasterMind::Update_List(std::vector<std::vector<int>>& list
	, std::vector<int>& CurrentNumber, std::string& Info)
{
	std::vector<std::vector<int>> CurrentList;
	int Digit = Info[0] - '0';
	int Position = Info[Info.size() - 1] - '0';
	for (int i = 0; i < list.size(); ++i)
	{
		int CountCorrectPosition = 0;
		for (int j = 0; j < this->countDigits; ++j)
		{
			if (CurrentNumber[j] == list[i][j])
				++CountCorrectPosition;
		}
		std::vector<int> sortRememberedNumber = CurrentNumber;
		std::vector<int> sortCurrentNumber = list[i];
		std::stable_sort(sortRememberedNumber.begin(), sortRememberedNumber.end());
		std::stable_sort(sortCurrentNumber.begin(), sortCurrentNumber.end());
		std::vector<int> firstIntersec;
		std::set_intersection(sortRememberedNumber.begin(), sortRememberedNumber.end()
			, sortCurrentNumber.begin(), sortCurrentNumber.end(), std::back_inserter(firstIntersec));
		int CountCorrectDigit = firstIntersec.size();
		if (CountCorrectDigit == Digit && CountCorrectPosition == Position)
		{
			CurrentList.push_back(list[i]);
		}
	}
	list = CurrentList;
}
MasterMind::~MasterMind()
{
}
const std::vector<std::vector<int>>& MasterMind::getNumbers() const
{
	return numbers;
}
