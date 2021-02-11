#pragma once
#include "CommonTypes.h"

struct IPlayer
{
	virtual std::string GetName() const = 0;
	virtual void PrepareForANewGame() = 0;
	virtual Combination MakeAGuess() = 0;
	virtual MatchResult Reply(Combination Guess) = 0;
	virtual bool ProcessResult(Combination Guess, MatchResult result) = 0;
	virtual ~IPlayer() = default;
};