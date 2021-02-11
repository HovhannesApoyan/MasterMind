#include "CPUPlayer.h"

CPUPlayer::CPUPlayer(std::string const& name)
	:PlayerBase(name)
{

}
void CPUPlayer::PrepareForANewGame()
{
	potential_combinations = Combination::GenerateAll();
	myComb = potential_combinations[rand() % potential_combinations.size()];

}
Combination CPUPlayer::MakeAGuess()
{
	if (potential_combinations.empty())
		return Combination(0);
	return potential_combinations[rand() % potential_combinations.size()];
}
MatchResult CPUPlayer::Reply(Combination Guess)
{
	return Combination::Match(myComb, Guess);
}
bool CPUPlayer::ProcessResult(Combination Guess, MatchResult result)
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