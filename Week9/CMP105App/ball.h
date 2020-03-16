#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class Baw : public GameObject
{
public:

	Baw();
	~Baw();

	void update(float dt) override;

	void setMouseCoords(sf::Vector2f coord) { mouseCoordinates = coord; }

private:

	sf::Vector2f mouseCoordinates;


};