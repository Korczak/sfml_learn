#pragma once

#include <SFML/System.hpp>
#include "Random.h"
#include "Board.h"
#include <list>

class Creature
{
public:
	Creature(sf::Vector2i startingPos, Board::Cell type) 
		: m_position(startingPos)
		, m_type(type) {}
	virtual ~Creature() = default;

	virtual void update(Board& board, std::list<Creature*>& creatures) {};

	inline const sf::Vector2i getPosition() const 	{ return m_position; }
	void destroy();
	inline int getHealth() const { return m_health; }
	inline bool isReproducing() const 
		{ return m_health >= m_maxHealth && m_type == Board::Prey ? true : false; }
	inline bool isEatingPrey() const { return m_isEatingPrey; }
	inline void eatPrey(unsigned health) { m_health += health, m_isEatingPrey = false; }
	inline Board::Cell getType() { return m_type; }
protected:
	bool m_isEatingPrey = false;
	int m_health = 100;
	const int m_maxHealth = 100;
	sf::Vector2i m_position;
	Board::Cell m_type;
};

