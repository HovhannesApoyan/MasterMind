#pragma once
#include "CommonTypes.h"

struct IPlayer
{
	virtual std::string getName() const = 0;
	virtual void prepareForANewGame() = 0;
	virtual Combination MakeAGuess() = 0;
	virtual MatchResult Reply(Combination Guess) = 0;
	//return false if cheating is suspected
	virtual bool ProcessResult(Combination Guess, MatchResult result) = 0;
	virtual ~IPlayer() = default;
};
