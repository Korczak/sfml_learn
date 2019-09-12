#pragma once

#include "Config.h"
#include <SFML/System.hpp>
#include <vector>

class Board
{
public :
	enum Cell {
		Empty,
		Prey,
		Predator
	};
private:
	std::vector<Cell> m_board;
	int m_boardWidth;
	int m_boardHeight;
public:
	//Constructor
	Board(const Config& config);
	Board(const Board& board) = delete;

	//Accessors
	unsigned getWidth() const { return m_boardWidth; }
	unsigned getHeight() const { return m_boardHeight; }
	unsigned getSize() const { return m_boardWidth * m_boardHeight; }
	inline bool isEmpty(int x, int y) { return (*this)(x, y) == this->Empty ? true : false; }
	inline Cell& operator() (int x, int y) { return m_board.at(m_boardWidth * y + x); }
	inline const Cell& operator() (int x, int y) const { return m_board.at(m_boardWidth * y + x); }
	inline Cell& operator() (sf::Vector2i pos) { return (*this)(pos.x, pos.y); }
	inline const Cell& operator() (sf::Vector2i pos) const { return (*this)(pos.x, pos.y); }
	inline sf::Color getColor(sf::Vector2i pos) { return this->getColor(pos.x, pos.y); }

	//Functions
	inline void resetBoard() { std::fill(m_board.begin(), m_board.end(), this->Empty); }
	sf::Color getColor(unsigned x, unsigned y);
	void calcValidPos(sf::Vector2i& pos) const;
};

