#pragma once
#include <string>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iterator>

struct Constants
{
	static const int digit_count = 4;
};

struct MatchResult
{
	explicit MatchResult(int common_digits = 0, int correct_places = 0);
	bool IsAWin() const;
	int common_digits;
	int correct_places;
};

std::ostream& operator << (std::ostream& out, MatchResult r);
bool operator == (MatchResult m1, MatchResult m2);
bool operator != (MatchResult m1, MatchResult m2);

class Combination
{
public:
	explicit Combination(int n = 0);
	explicit Combination(std::string const& s);
	static MatchResult Match(const Combination& c1, const Combination& c2);
	static std::vector<Combination> GenerateAll();
	friend std::ostream& operator <<(std::ostream& out, Combination const& c);
private:
	std::string m_comb;
};