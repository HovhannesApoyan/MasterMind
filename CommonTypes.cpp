#include "CommonTypes.h"

MatchResult::MatchResult(int common_digits, int correct_places)
	:common_digits(common_digits)
	, correct_places(correct_places)
{
	if (common_digits < 0 || common_digits > Constants::digit_count
		|| correct_places < 0 || correct_places > Constants::digit_count
		|| correct_places > common_digits)
	{
		throw std::invalid_argument("incorrect values for common digits and/or correct places");
	}
}
std::ostream& operator << (std::ostream& out, MatchResult r)
{
	return out << r.common_digits << ":" << r.correct_places;
}
bool operator == (MatchResult m1, MatchResult m2)
{
	return std::make_pair(m1.common_digits, m1.correct_places)
		== std::make_pair(m2.common_digits, m2.correct_places);
}
bool operator != (MatchResult m1, MatchResult m2)
{
	return !(m1 == m2);
}
bool MatchResult::IsAWin() const
{
	return *this == MatchResult(Constants::digit_count, Constants::digit_count);
}


Combination::Combination(int n)
{
	for (int i = 0; i < Constants::digit_count; ++i)
	{
		m_comb.push_back(n % 10 + '0');
		n /= 10;
	}
	if (n != 0)
		throw std::invalid_argument("too large number for combination");
	std::reverse(m_comb.begin(), m_comb.end());
}

Combination::Combination(std::string const& s)
	:m_comb(s)
{
	if (s.size() != Constants::digit_count)
	{
		throw std::invalid_argument("All characters in a combination must be digits");
	}
	if (!std::all_of(s.begin(), s.end(), isdigit))
	{
		throw std::invalid_argument("not all items in combination are digits");
	}
}

MatchResult Combination::Match(const Combination& c1, const Combination& c2)
{
	MatchResult m;
	std::vector<char> v;
	std::string s1(c1.m_comb), s2(c2.m_comb);
	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());
	std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::back_inserter(v));
	m.common_digits = v.size();
	for (int i = 0; i < Constants::digit_count; ++i)
	{
		m.correct_places += c1.m_comb[i] == c2.m_comb[i];
	}
	return m;
}

std::vector<Combination> Combination::GenerateAll()
{
	std::vector<Combination> v;
	const int max = pow(10, Constants::digit_count);
	for (int i = 0; i < max; ++i)
		v.push_back(Combination(i));
	return v;
}

std::ostream& operator <<(std::ostream& out, Combination const& c)
{
	return out << c.m_comb;
}