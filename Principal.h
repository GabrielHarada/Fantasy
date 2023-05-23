#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Jogador.h"

namespace Jogo {

	class Principal {
	private:
		sf::RenderWindow window;
		Jogador::Jogador jogador;
	public:
		Principal();
		~Principal();
		void executar();
	};
}