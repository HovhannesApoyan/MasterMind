#pragma once
#include <vector>

/*
auto comb = player1->MakeAGuess()
auto res = player2->RespondToGuess(comb)
if (res == "4:4")
std::cout << player1->getName() << " winner";
//
preparing   tveryky generacne cpu-in hamar
*/
enum class Comand
{
	new_game = 1,
	two_player = 2,
	with_computer = 3,
	computer = 4,
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

class MasterMind {
public:
	explicit MasterMind();
	MasterMind(const int& n);
	const std::vector<std::vector<int>>& getNumbers()const;
	void generateNDigitNumbers();
	const std::vector<int>& randomNumber()const;
	void printNumbers()const;

	void newGame();
	void twoPlayer();
	void withComputer();
	void playComputer();
	void menu();

	void inputNumber(std::vector<int>& CurrentNumber, std::string& str);
	const int intersection(const std::vector<int>& rememberedNumber, const std::vector<int>& CurrentNumber)const;
	bool numbersCheck(const std::vector<int>& CurrentNumber
		, const std::vector<int>& rememberedNumber, std::vector<std::string>& Info
		, int& CountCorrectDigit, int& CountCorrectPosition);
	void updateList(std::vector<std::vector<int>>& list,
		std::vector<int>& CurrentNumber, std::string& Info);

	~MasterMind();
private:
	const int count_digits;
	int size_numbers;
	std::vector<std::vector<int>> numbers;
};