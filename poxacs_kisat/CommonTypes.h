#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

struct Constants
{
	static const int digit_count = 4;
};

struct MatchResult
{
	explicit MatchResult(int common_digits = 0, int correct_places = 0)
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
	int common_digits;
	int correct_places;

	bool IsAWin() const;

};

inline std::ostream& operator << (std::ostream& out, MatchResult r)
{
	return out << r.common_digits << ":" << r.correct_places;
}

inline bool operator == (MatchResult m1, MatchResult m2)
{
	return std::make_pair(m1.common_digits, m1.correct_places)
		== std::make_pair(m2.common_digits, m2.correct_places);
}
inline bool operator != (MatchResult m1, MatchResult m2)
{
	return !(m1 == m2);
}
inline bool MatchResult::IsAWin() const
{
	return *this == MatchResult(Constants::digit_count, Constants::digit_count);
}

class Combination
{
public:
	explicit Combination(int n = 0)
	{
		std::string str = std::to_string(n);
		if (str.size() != Constants::digit_count)
		{
			//throw std::invalid_argument("too small number for combination");
		}

		for (int i = 0; i < Constants::digit_count; ++i)
		{
			m_comb.push_back(n % 10 + '0');
			n /= 10;
			//m_comb.push_back((static_cast<int>(str[i])) - '0');
		}
		//	if (n != 0)
	//			throw std::invalid_argument("too large number for combination");
		std::reverse(m_comb.begin(), m_comb.end());
	}
	explicit Combination(std::string const& s)
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
	static MatchResult Match(const Combination& c1, const Combination& c2)
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

	static std::vector<Combination> GenerateAll()
	{
		const int size_numbers = pow(10, Constants::digit_count);
		int size = size_numbers / 10;
		int count = 0;
		std::vector<Combination> v;
		for (int i = size_numbers; i < size_numbers + size; ++i) {
			v.push_back(Combination(i));
			//++count;
		}
		for (int i = size_numbers / 10; i < size_numbers; ++i) {
			v.push_back(Combination(i));
			//++count;
		}
		///
		return v;
	}

	friend std::ostream& operator <<(std::ostream& out, Combination const& c)
	{
		for (int i = 0; i < c.m_comb.size(); ++i)
			out << c.m_comb[i];
		return out;
	}
private:
	std::string m_comb;
};