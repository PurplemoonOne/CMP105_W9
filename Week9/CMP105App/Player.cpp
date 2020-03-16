#include "Player.h"

Player::Player()
{
}

Player::Player(Input* in)
	: input(in)
{
	playerTex.loadFromFile("gfx/Goomba.png");
	setTexture(&playerTex);
	setSize(sf::Vector2f(256 / 2, 256 / 2));
	setPosition(100, 100);
	setVelocity(100, 100);
	setInput(input);
	ballmanager = new BallManager(getPosition(), input);
}

Player::~Player()
{
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		setPosition(getPosition().x, getPosition().y - velocity.y * dt);
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		setPosition(getPosition().x, getPosition().y + velocity.y * dt);
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		setPosition(getPosition().x - velocity.x * dt, getPosition().y);
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		setPosition(getPosition().x + velocity.x * dt, getPosition().y);
	}
	if (input->isMouseLDown())
	{
		fire();
	}
}

void Player::update(float dt)
{
	ballmanager->update(dt);
	
	ballmanager->updateSpawn(getPosition());
}

void Player::fire()
{
	ballmanager->setFired(true);
	ballmanager->spawn();
	ballmanager->setFired(false);
}
