#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Jogo {

	class Principal {
	private:
		sf::RenderWindow window;
	public:
		Principal();
		~Principal();
		void executar();
	};
}