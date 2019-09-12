#include "Application.h"


Application::Application(const Config& config)  
	: m_window( { config.windowSize.x, config.windowSize.y }, config.title)
	, m_pConfig(&config)
{
	this->resetView();
	m_window.setFramerateLimit(config.fps);
}

void Application::init()
{
	m_game = std::make_unique<CreaturesManager>(*m_pConfig);
	m_game->init();
}

void Application::run()
{
	while (m_window.isOpen()) {
		m_game->update();
		render();
		pollEvents();
	}
}

const sf::RenderWindow& Application::getWindow() const
{
	return m_window;
}

void Application::pollEvents()
{
	sf::Event e;
	while (m_window.pollEvent(e)) {
		m_game->input(e);
		m_keyboard.update(e);
		switch (e.type)
		{
		case sf::Event::Closed:
			m_window.close();
		}
	}
}

void Application::input()
{
	float speed = 250;
	sf::Vector2f change;
	if (m_keyboard.isKeyDown(sf::Keyboard::W)) {
		change.y -= speed;
	}
	else if (m_keyboard.isKeyDown(sf::Keyboard::S)) {
		change.y += speed;
	}
	if (m_keyboard.isKeyDown(sf::Keyboard::A)) {
		change.x -= speed;
	}
	else if (m_keyboard.isKeyDown(sf::Keyboard::D)) {
		change.x += speed;
	}
}

void Application::render()
{
	m_window.clear(m_pConfig->bgColour);

	m_game->render(m_window);

	m_window.display();
}

void Application::resetView()
{

}
