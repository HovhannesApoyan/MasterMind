#pragma once
#include "IPlayer.h"
#include "CommonTypes.h"
#include <boost/format.hpp>

class MasterMind
{
public:
	MasterMind(IPlayer* p1, IPlayer* p2);
	IPlayer* Play();
	static void menu();
private:
	IPlayer* players[2];
	int turn;

	void PrepareForANewGame();
};

enum class Comand
{
	new_game = 1,
	human_with_human,
	human_with_computer,
	computer,
	quit = 0,
};

inline constexpr int comandToInt(Comand com)
{
	return static_cast<int>(com);
}

inline std::ostream& operator <<(std::ostream& out, const Comand& com)
{
	out << static_cast<int>(com);
	return out;
}