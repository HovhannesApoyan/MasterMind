#include "HumanConsolePlayer.h"

HumanConsolePlayer::HumanConsolePlayer(const std::string& name)
	:PlayerBase(name)
{

}

void HumanConsolePlayer::PrepareForANewGame()
{
	std::cout << '[' << GetName() << "] input remember number's 4 digits:";
	std::string line;
	getline(std::cin, line);
}

Combination HumanConsolePlayer::MakeAGuess()
{
	for (;;)
	{
		std::cout << '[' << GetName() << "] make a guess\n";
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

bool HumanConsolePlayer::ProcessResult(Combination guess, MatchResult res)
{
	std::cout << "Opponent responds to guess " << guess << " with " << res << "\n";
	return true;
}

MatchResult HumanConsolePlayer::Reply(Combination guess)
{
	for (;;)
	{
		std::cout << '[' << GetName() << "] reply to guess " << guess << "\n";
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