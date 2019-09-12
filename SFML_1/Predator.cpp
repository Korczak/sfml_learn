#include "Predator.h"

void Predator::update(Board& board, std::list<Creature*>& creatures)
{
	int moveX = Random::get().intInRange(-1, 1);
	int moveY = Random::get().intInRange(-1, 1);
	if (moveX == 0 && moveY == 0)
		moveX = 1;
	//std::cout << "MOVE: " << moveX << " " << moveY << std::endl;

	sf::Vector2i newPos(m_position + sf::Vector2i(moveX, moveY));
	board.calcValidPos(newPos);


	if (board(newPos) == Board::Cell::Empty) { //When predator moves to empty space
		board(m_position) = Board::Cell::Empty;
		board(newPos) = Board::Cell::Predator;
		m_position = newPos;
	}
	else if (board(newPos) == Board::Cell::Prey) { //When predator meets Prey
		board(m_position) = Board::Cell::Empty;
		board(newPos) = Board::Cell::Predator;
		m_position = newPos;

		m_isEatingPrey = true;
	}
	

	m_health -= m_healthDecrease;
}
