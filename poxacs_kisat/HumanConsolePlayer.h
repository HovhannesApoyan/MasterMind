#pragma once
#include "PlayerBase.h"
#include <iostream>
#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>

class HumanConsolePlayer : public PlayerBase
{
public:
	HumanConsolePlayer(const std::string& name)
		:PlayerBase(name)
	{

	}

	void prepareForANewGame() override
	{
		std::cout << "Welcome to Mastermind. Press enter when ready...";
		std::string line;
		getline(std::cin, line);
	}

	Combination MakeAGuess() override
	{
		for (;;)
		{
			std::cout << "Make a guess\n";
			std::string comb;
			getline(std::cin, comb);
			boost::trim(comb);
			try
			{
				Combination c(comb);
				return c;
			}
			catch (std::exception& e)
			{
				std::cout << "Try again.\n";
			}
		}
	}

	bool ProcessResult(Combination guess, MatchResult res) override
	{
		std::cout << "Opponent responds to guess " << guess << " with " << res << "\n";
		return true;
	}

	MatchResult Reply(Combination guess) override
	{
		for (;;)
		{
			std::cout << "Reply to guess " << guess << "\n";
			std::string line;
			getline(std::cin, line);
			std::istringstream iss(line);
			int first, second;
			char c;
			try
			{
				if (!(iss >> first >> c >> second) || c != ':' || iss >> c)
				{
					throw std::invalid_argument("cannot parse input for match");
				}

				MatchResult res(first, second);
				return res;
			}
			catch (std::exception& e)
			{
				std::cout << "Try again.\n";
			}

		}
	}
};