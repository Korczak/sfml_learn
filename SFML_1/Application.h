#pragma once

#include "Config.h"
#include "Game.h"
#include "CreaturesManager.h"

class Application
{

public:
	//Constructors / Destructors
	Application(const Config& config);
	Application(const Application& app) = delete;
	Application operator= (Application& app2) = delete;

	//Methods
	void init();
	void run();

	//Accessor
	const sf::RenderWindow& getWindow() const;
private:
	void pollEvents();
	void input();
	void render();
	void resetView();

	sf::RenderWindow m_window;
	std::unique_ptr<Game> m_game;
	const Config* m_pConfig;
	Keyboard    m_keyboard;
	float m_zoom = 1;

}; 
	
