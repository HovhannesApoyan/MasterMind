#pragma once
#include "PlayerBase.h"
#include <iostream>
#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>

class HumanConsolePlayer : public PlayerBase
{
public:
	HumanConsolePlayer(const std::string& name);
	void PrepareForANewGame() override;
	Combination MakeAGuess() override;
	bool ProcessResult(Combination guess, MatchResult res) override;
	MatchResult Reply(Combination guess) override;
};