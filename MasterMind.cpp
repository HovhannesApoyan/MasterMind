#define _CRT_SECURE_NO_WARNINGS
#include "MasterMind.h"
#include <iostream>
#include <iomanip>

MasterMind::MasterMind(IPlayer* p1, IPlayer* p2)
	: turn(0)
{
	players[0] = p1;
	players[1] = p2;
}

void MasterMind::PrepareForANewGame()
{
	auto name1 = players[0]->GetName();
	auto name2 = players[1]->GetName();
	if (name1.empty() || name2.empty() || name1 == name2)
	{
		throw std::logic_error("One of the players has empty name or both players have the same name");
	}
	std::cout << boost::format("Starting a new game between %1% and %2%") % name1 % name2;
	std::cout << ". Players are preparing,\n";

	for (auto p : players)
	{
		p->PrepareForANewGame();
	}
}

IPlayer* MasterMind::Play()
{
	try
	{
		PrepareForANewGame();
		int turn = rand() % 2;
		std::cout << boost::format("Coin toss: player %1% starts the game") % players[turn]->GetName() << '\n';

		int opponent = 1 - turn;
		for (;; std::swap(turn, opponent))
		{
			//std::cout << boost::format("player %1% is about to make a guess") % players[turn]->GetName() << '\n';
			auto guess = players[turn]->MakeAGuess();
			//std::cout << boost::format("player %1% is about to respond to guess %2%") % players[opponent]->GetName() % guess;
			auto matchres = players[opponent]->Reply(guess);

			if (matchres.IsAWin())
			{
				std::cout << boost::format(" %1% is winner!!!") % players[turn]->GetName() << '\n';
				return players[turn];
			}

			bool cheating = !players[turn]->ProcessResult(guess, matchres);
			if (cheating)
			{
				std::cout << boost::format("player %1% suspects player %2% in cheating") % players[turn]->GetName() % players[opponent]->GetName();
			}
		}
		return nullptr;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		throw;
	}
}

void MasterMind::menu()
{
	std::cout << std::setw(15) << Comand::new_game << " - New Game\n";
	std::cout << std::setw(15) << Comand::human_with_human << " - Human with human\n";
	std::cout << std::setw(15) << Comand::human_with_computer << " - Human with computer\n";
	std::cout << std::setw(15) << Comand::computer << " - Computer\n";
	std::cout << std::setw(15) << Comand::quit << " - Exit\n";
}