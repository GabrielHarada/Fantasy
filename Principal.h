#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Jogador.h"
#include "Inimigo.h"
#include "GerenciadorGrafico.h"

namespace Jogo {

	class Principal {
	private:
		Gerenciador::GerenciadorGrafico* pGrafico;
		std::vector<Jogo::Personagem::Personagem*> personagens;
	public:
		Principal();
		~Principal();
		void executar();
	};
}