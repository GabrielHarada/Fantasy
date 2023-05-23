#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Jogo {
	namespace Personagem {

		class Personagem {
		protected:
			sf::RectangleShape corpo;
			sf::Vector2f vel;
		public:
			Personagem(const sf::Vector2f pos, const sf::Vector2f tam);
			~Personagem();
			const sf::RectangleShape getCorpo();
			virtual void move() = 0;
		};
	}
}