#pragma once
#include "ball.h"
#include <vector>
#include <math.h>

class BallManager 
{

public:


	BallManager();
	BallManager(sf::Vector2f spawnPoint, Input* in);
	~BallManager();

	void spawn(); 
	void update(float dt); 
	void deathCheck();
	void render(sf::RenderWindow* window);

	void updateSpawn(sf::Vector2f usp) { spawnPoint = usp; }
	void setFired(bool val) { isFired = val; }

	private:

		bool isFired;

		std::vector<Baw> baws;
		sf::Vector2f spawnPoint; 
		sf::Texture texture;
		sf::Text count;

		Input* input;
};