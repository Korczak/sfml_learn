#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Keyboard.h"
#include "Board.h"
#include "Config.h"

/*
	Class that acts as the game engine.
	Wrapper class
*/
class Game
{
public:
	//Constructors / Destructors
	Game(const Config& config);
	virtual ~Game() = default;

	//Accessors

	//Functions
	virtual void init() = 0;
	virtual void input(const sf::Event e) = 0;
	virtual void pollEvents() = 0;
	virtual void update() = 0;
	virtual void onRender() = 0;
	void render(sf::RenderWindow& window);

protected:
	//Variables
	Keyboard m_keys;
	std::shared_ptr<Board> m_board;
	const Config& config;

	template<typename Func>
	void cellForEach(Func function);

	unsigned getCellIndex(unsigned x, unsigned y) const;
	void setCellColour(int x, int y, sf::Color colour);
	void addQuad(unsigned xIndex, unsigned yIndex);
	std::vector<sf::Vertex> m_cellVertexPoints;
};


template<typename Func>
void Game::cellForEach(Func function)
{
	for (size_t x = 0; x < m_board->getWidth(); x++) {
		for (size_t y = 0; y < m_board->getHeight(); y++) {
			function(x, y);
		}
	}
}