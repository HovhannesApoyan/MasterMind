#pragma once

#include "IPlayer.h"
#include <string>
#include <stdexcept>

class PlayerBase : public IPlayer
{
public:
	PlayerBase(const std::string& name, const int count_digits = 4)
		:name(name)
		, count_digits(count_digits)
	{
		if (name.empty())
		{
			throw std::invalid_argument("empty name not allowed");
		}
	}
	std::string getName() const override
	{
		return name;
	}

protected:
	const int count_digits;
private:
	std::string name;
};