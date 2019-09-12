#pragma once

#include "Creatures.h"

class Predator : public Creature
{
public:
	Predator(sf::Vector2i startingPos, int healthDecrease = 1) 
		: m_healthDecrease(healthDecrease)
		, Creature(startingPos, Board::Predator) {}

	virtual void update(Board& board, std::list<Creature*>& creatures);

private:
	int m_healthDecrease;
};

