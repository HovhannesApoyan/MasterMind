#pragma once
#include "PlayerBase.h"
#include <algorithm>

class GoodCPUPlayer : public PlayerBase
{
public:
	GoodCPUPlayer(std::string const& name)
		:PlayerBase(name)
	{
		std::cout << "a\n";
	}
	void prepareForANewGame() override
	{
		potential_combinations = Combination::GenerateAll();
		myComb = potential_combinations[rand() % potential_combinations.size()];
		
	}
	virtual Combination MakeAGuess() override
	{
		if (potential_combinations.empty())
			return Combination(0);
		return potential_combinations[rand() % potential_combinations.size()];
	}
	virtual MatchResult Reply(Combination Guess) override
	{
		return Combination::Match(myComb, Guess);
	}
	
	//return false if cheating is suspected
	virtual bool ProcessResult(Combination Guess, MatchResult result) override
	{
		if (potential_combinations.size() == 1 && !result.IsAWin())
			return false;

		auto it = std::remove_if(potential_combinations.begin(), potential_combinations.end(),
			[=](Combination c)
			{
				return Combination::Match(c, Guess) != result;
			});

		potential_combinations.erase(it, potential_combinations.end());
		return true;
	}

private:
	std::vector<Combination> potential_combinations;
	Combination myComb;
};