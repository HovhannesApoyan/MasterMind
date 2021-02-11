#pragma once
#include "IPlayer.h"
#include <string>
#include <stdexcept>

class PlayerBase : public IPlayer
{
public:
	PlayerBase(const std::string& name)
		:name(name)
	{
		if (name.empty())
		{
			throw std::invalid_argument("empty name not allowed");
		}
	}
	std::string GetName() const override
	{
		return name;
	}
private:
	std::string name;
};