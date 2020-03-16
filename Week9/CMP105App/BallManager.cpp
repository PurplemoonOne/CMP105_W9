#include "BallManager.h"

BallManager::BallManager()
{
	spawnPoint = sf::Vector2f(350, 250);
	texture.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 20; i++) 
	{ 
		baws.push_back(Baw());
		baws[i].setAlive(false); 
		baws[i].setTexture(&texture); 
		baws[i].setSize(sf::Vector2f(100, 100)); 
	}
}

BallManager::BallManager(sf::Vector2f sp, Input* in)
	:spawnPoint(sp), input(in)
{
	spawnPoint = sf::Vector2f(350, 250);
	texture.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 20; i++)
	{
		baws.push_back(Baw());
		baws[i].setAlive(false);
		baws[i].setTexture(&texture);
		baws[i].setSize(sf::Vector2f(100, 100));
	}
	isFired = false;
}

BallManager::~BallManager()
{
}

void BallManager::spawn()
{
	if(isFired)
	for (int i = 0; i < baws.size(); i++) 
	{ 
		if (!baws[i].isAlive()) 
		{ 
			baws[i].setMouseCoords(sf::Vector2f(input->getMouseX(), input->getMouseY()));
			baws[i].setAlive(true);

			baws[i].setPosition(spawnPoint); 
			return; 
		} 
	}
}

void BallManager::update(float dt)
{

	for (int i = 0; i < baws.size(); i++)
	{ 
		if (baws[i].isAlive()) 
		{ 
			baws[i].update(dt); 
		} 
	}
	deathCheck();
}

void BallManager::deathCheck()
{
	for (int i = 0; i < baws.size(); i++) 
	{ 
		if (baws[i].isAlive()) 
		{ 
			if (baws[i].getPosition().x < -100) 
			{ 
				baws[i].setAlive(false); 
			}
			if (baws[i].getPosition().x > 800) 
			{ 
				baws[i].setAlive(false);
			}
			if (baws[i].getPosition().y < -100) 
			{ 
				baws[i].setAlive(false); 
			}
			if (baws[i].getPosition().y > 600) 
			{ 
				baws[i].setAlive(false); 
			} 
		} 
	}
}

void BallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < baws.size(); i++) 
	{ 
		if (baws[i].isAlive()) 
		{ 
			window->draw(baws[i]);
		}
	}
}
