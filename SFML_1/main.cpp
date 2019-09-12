#include <SFML/Graphics.hpp>
#include "Application.h"

int main()
{
	//Init game engine
	Config config;
	config.init();
	Application app(config);

	app.init();
	app.run();

	return 0;
}