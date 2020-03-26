#pragma once

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include <SFML/Graphics.hpp>

namespace entity
{
	class Entity
	{
	private:
		sf::RectangleShape shape;
		float speed;

	protected:




	public:
		Entity();
		virtual ~Entity();

		virtual void move(const float& dt, const float x, const float y);

		virtual void update(const float& dt);
		virtual void render(sf::RenderTarget* _target);
	};

}


