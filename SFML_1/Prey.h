#pragma once
#include "Creatures.h"
#include <SFML\Window\Keyboard.hpp>

class Prey : public Creature
{
public:
	Prey(sf::Vector2i startingPos, int healthIncrease = 1)
		: m_healthIncrease(healthIncrease)
		, Creature(startingPos, Board::Prey)
	{
		m_health = 1;
	}

	virtual void update(Board& board, std::list<Creature*>& creatures);
	Prey* reproduce(const Board& board);
private:
	int m_healthIncrease;
};