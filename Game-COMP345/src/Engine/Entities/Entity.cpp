#include "Entity.h"

entity::Entity::Entity()
{
	shape.setSize(sf::Vector2f(50.f, 50.f));
	speed = 100.f;
}

entity::Entity::~Entity()
{
}

void entity::Entity::move(const float& dt, const float x, const float y)
{
	shape.move(dt*speed*sf::Vector2f(x, y));
}

void entity::Entity::update(const float& dt)
{


}

void entity::Entity::render(sf::RenderTarget* _target)
{
	_target->draw(shape);
}
