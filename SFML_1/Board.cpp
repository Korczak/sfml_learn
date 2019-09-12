#include "Board.h"

Board::Board(const Config& config) 
	: m_boardWidth(config.simSize.x)
	, m_boardHeight(config.simSize.y)
{
	m_board = std::vector<Cell>(m_boardWidth * m_boardHeight);
	std::fill(m_board.begin(), m_board.end(), this->Empty);
}

sf::Color Board::getColor(unsigned x, unsigned y)
{
	if ((*this)(x, y) == Cell::Empty)
		return sf::Color::Black;
	else if ((*this)(x, y) == Cell::Predator)
		return sf::Color::Red;
	else
		return sf::Color::Green;
}

void Board::calcValidPos(sf::Vector2i& pos) const {
	if (pos.x >= m_boardWidth)
		pos.x = 0;
	else if (pos.x < 0)
		pos.x = m_boardWidth - 1;
	if (pos.y >= m_boardHeight)
		pos.y = 0;
	else if (pos.y < 0)
		pos.y = m_boardHeight - 1;
}