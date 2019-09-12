#include "Prey.h"

void Prey::update(Board& board, std::list<Creature*>& creatures)
{
	int moveX = Random::get().intInRange(-1, 1);
	int moveY = Random::get().intInRange(-1, 1);

	sf::Vector2i newPos(m_position + sf::Vector2i(moveX, moveY));
	board.calcValidPos(newPos);

	//Move only if empty
	if (board(newPos) == Board::Cell::Empty) {
		board(newPos) = Board::Cell::Prey;
		board(m_position) = Board::Cell::Empty;
		m_position = newPos;
	}

	m_health += m_healthIncrease;
}

Prey* Prey::reproduce(const Board& board)
{
	m_health = 1;

	int moveX = Random::get().intInRange(-1, 1);
	int moveY = Random::get().intInRange(-1, 1);
	if (moveX == 0 && moveY == 0)
		moveX = 1;

	sf::Vector2i newPos(m_position + sf::Vector2i(moveX, moveY));
	board.calcValidPos(newPos);
	return new Prey(newPos);
}
