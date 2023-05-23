#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Jogador.h"
#include "Inimigo.h"
#include <vector>

namespace Jogo {

	class Principal {
	private:
		sf::RenderWindow window;
		std::vector<Jogo::Personagem::Personagem*> personagens;
	public:
		Principal();
		~Principal();
		void executar();
	};
}