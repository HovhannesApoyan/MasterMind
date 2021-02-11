#pragma once
#include <algorithm>
#include "PlayerBase.h"

class CPUPlayer : public PlayerBase
{
public:
	CPUPlayer(std::string const& name);
	void PrepareForANewGame() override;
	virtual Combination MakeAGuess() override;
	virtual MatchResult Reply(Combination Guess);
	virtual bool ProcessResult(Combination Guess, MatchResult result) override;
private:
	std::vector<Combination> potential_combinations;
	Combination myComb;
};