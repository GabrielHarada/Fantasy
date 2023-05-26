#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Jogador.h"
#include "Inimigo.h"
#include "Plataforma.h"
#include "Caixa.h"

#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include "GerenciadorColisao.h"

#include "ListaEntidade.h"

namespace Jogo {

	class Principal {
	private:
		Gerenciador::GerenciadorGrafico* pGrafico;
		Gerenciador::GerenciadorEvento* pEvento;
		Gerenciador::GerenciadorColisao colisor;
		Lista::ListaEntidade listaPersonagem;
		Lista::ListaEntidade listaObstaculo;
	public:
		Principal();
		~Principal();
		void executar();
		void instanciaEntidades();
	};
}