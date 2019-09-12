#include "Game.h"



//Constructors
Game::Game(const Config& config) : config(config)
{
	m_board = std::make_shared<Board>(config);
	m_cellVertexPoints.reserve(config.simSize.x * config.simSize.y * 4);

	for (unsigned y = 0; y < config.simSize.y; y++) {
		for (unsigned x = 0; x < config.simSize.x; x++) {
			addQuad(x, y);
		}
	}
}

void Game::render(sf::RenderWindow& window)
{
	onRender();
	window.draw(m_cellVertexPoints.data(), m_cellVertexPoints.size(), sf::Quads);
	//std::cout << "DRAWING " << m_cellVertexPoints.at(0).color.r << "\n";
	//std::cout << "DRAWING "  << "\n";
}



unsigned Game::getCellIndex(unsigned x, unsigned y) const
{
	return x + y * config.simSize.x;
}

void Game::setCellColour(int x, int y, sf::Color colour)
{
	//std::cout << "A\n";
	auto index = (y * config.simSize.x + x) * 4;
	for (int i = 0; i < 4; i++)
	{
		m_cellVertexPoints.at(index + i).color = colour;
	}
}

void Game::addQuad(unsigned xIndex, unsigned yIndex)
{
	float cellSize = (float)config.cellSize;
	sf::Vertex topLeft;
	sf::Vertex topRight;
	sf::Vertex bottomLeft;
	sf::Vertex bottomRight;

	float pixelX = xIndex * cellSize;
	float pixelY = yIndex * cellSize;

	topLeft.position = { pixelX,               pixelY };
	topRight.position = { pixelX + cellSize,    pixelY };
	bottomLeft.position = { pixelX,               pixelY + cellSize };
	bottomRight.position = { pixelX + cellSize,    pixelY + cellSize };

	topLeft.color = config.fgColour;
	topRight.color = config.fgColour;
	bottomLeft.color = config.fgColour;
	bottomRight.color = config.fgColour;

	m_cellVertexPoints.push_back(topLeft);
	m_cellVertexPoints.push_back(bottomLeft);
	m_cellVertexPoints.push_back(bottomRight);
	m_cellVertexPoints.push_back(topRight);
}
