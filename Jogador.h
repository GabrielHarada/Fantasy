#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Personagem.h"

namespace Jogo {
	namespace Personagem {
		namespace Jogador {

			class Jogador : public Personagem {
			private:
				sf::RectangleShape corpo;
				sf::Vector2f vel;
				void inicializa();
			public:
				Jogador(const sf::Vector2f pos, const sf::Vector2f tam);
				~Jogador();
				void move();
			};
		}
	}
}