#pragma once
#include "Framework/GameObject.h"
#include "BallManager.h"

class Player : public GameObject
{
public:

	Player();
	Player(Input* input);
	~Player();

	void handleInput(float dt) override;
	void update(float dt) override;

	BallManager* GetBawManager() { return ballmanager; }

private:

	void fire();

	sf::Texture playerTex;

	Input* input;
	BallManager* ballmanager;
};