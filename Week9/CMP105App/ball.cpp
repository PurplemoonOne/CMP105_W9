#include "ball.h"

Baw::Baw()
{
	setVelocity(100, 100);
}

Baw::~Baw()
{
}

void Baw::update(float dt)
{
	sf::Vector2f dir = mouseCoordinates - getPosition();
	Vector::normalise(dir);
	setPosition(getPosition().x + velocity.x + dir.x * dt, getPosition().y + velocity.y + dir.y * dt);
}
