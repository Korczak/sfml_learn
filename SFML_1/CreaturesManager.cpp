#include "CreaturesManager.h"



CreaturesManager::CreaturesManager(const Config& config)
	: Game(config)
	, m_numPredators(config.numPredators)
	, m_numPreys(config.numPreys)
	, m_config(config)
{
	m_creatures = std::list<Creature*>();
}

void CreaturesManager::init()
{
	cellForEach([&](unsigned x, unsigned y) {
		auto n = Random::get().intInRange(0, 10000);
		sf::Vector2i pos(x, y);

		if (n > 100) {
			(*m_board)(x, y) = Board::Cell::Empty;
		}
		else if (n > 90) {
			m_creatures.push_back(new Prey(pos));
			(*m_board)(x, y) = Board::Cell::Prey;
		}
		else {
			m_creatures.push_back(new Predator(pos));
			(*m_board)(x, y) = Board::Cell::Predator;
		}

		setCellColour(x, y, (*m_board).getColor(pos));
	});
}
		

void CreaturesManager::input(const sf::Event e)
{
}

void CreaturesManager::pollEvents()
{
}

void CreaturesManager::update()
{
	for (std::list<Creature*>::iterator itr = m_creatures.begin(); itr != m_creatures.end(); ++itr) {
		(*itr)->update(*m_board, m_creatures);

		if ((*itr)->getHealth() <= 0) { //Destroy object with less than 0 hp (Predator)
			(*m_board)((*itr)->getPosition()) = Board::Cell::Empty;
			delete* itr;
			itr = m_creatures.erase(itr);
			if (itr == m_creatures.end()) //Erase predator and check list
				return;
		}
		else if ((*itr)->isReproducing()) { //Reproduce Prey
			Prey* prey = dynamic_cast<Prey*>(*itr)->reproduce((*m_board));
			m_creatures.push_back(prey);
			(*m_board)(m_creatures.back()->getPosition()) = Board::Cell::Prey;
		}
		else if ((*itr)->isEatingPrey()) { //Eat Prey
			auto itr_found = std::find_if(m_creatures.begin(), m_creatures.end(), [&](Creature* creature) {
				if (creature->getPosition() == (*itr)->getPosition() && creature != *itr)
					return true;
				else 
					return false;
			});

			if (itr_found != m_creatures.end()) {
				(*itr)->eatPrey((*itr_found)->getHealth());
				delete* itr_found;
				itr = m_creatures.erase(itr_found); //Erase prey and check list
				if (itr == m_creatures.end())
					return;
			}
		}
	}
}

void CreaturesManager::onRender()
{
	cellForEach([&](unsigned x, unsigned y) {
		setCellColour(x, y, (*m_board).getColor(x, y));
	});
}

