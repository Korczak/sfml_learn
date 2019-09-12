#pragma once
#include <list>
#include "Creatures.h"
#include "Game.h"
#include "Prey.h"
#include "Predator.h"

class CreaturesManager : public Game
{
public:
	CreaturesManager(const Config& config);
	
	virtual void init();
	virtual void input(const sf::Event e);
	virtual void pollEvents();
	virtual void update();	
	virtual void onRender();

private:
	const Config& m_config;
	std::list<Creature*> m_creatures;
	unsigned int m_numPreys;
	unsigned int m_numPredators;
};