#ifndef MY_MASTER_MIND_H
#define MY_MASTER_MIND_H
#include <vector>

class MasterMind {
public:
	explicit MasterMind();
	MasterMind(const int& n);
	const std::vector<std::vector<int>>& getNumbers()const;
	void generateNDigitNumbers();
	const std::vector<int>& randomNumber()const;
	void printNumbers()const;

	void New_Game();
	void Two_Player();
	void With_Computer();
	void Play_Computer();
	void menu();

	void input_Number(std::vector<int>& CurrentNumber, std::string& str);
	bool Numbers_Check(const std::vector<int>& CurrentNumber
		, const std::vector<int>& rememberedNumber, std::vector<std::string>& Info
		, int& CountCorrectDigit, int& CountCorrectPosition);
	void Update_List(std::vector<std::vector<int>>& list,
		std::vector<int>& CurrentNumber, std::string& Info);

	enum Comand
	{
		newGame = 1,
		twoPlayer = 2,
		withComputer = 3,
		computer = 4,
		quit = 0,
	};

	~MasterMind();
private:
	int countDigits;
	int sizeNumbers;
	std::vector<std::vector<int>> numbers;
};
#endif
