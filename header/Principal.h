#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "..\header\Entidade\Personagem\Jogador\Jogador.h"
#include "..\header\Entidade\Personagem\Inimigo\Inimigo.h"
#include "..\header\Entidade\Obstaculo\Plataforma\Plataforma.h"
#include "..\header\Entidade\Obstaculo\Caixa\Caixa.h"

#include "..\header\Gerenciador\GerenciadorGrafico.h"
#include "..\header\Gerenciador\GerenciadorEvento.h"
#include "..\header\Gerenciador\GerenciadorColisao.h"

#include "..\header\Lista\ListaEntidade.h"

#include "Parallax\Fundo.h"


namespace Fantasy {

	class Principal {
	private:
		Gerenciador::GerenciadorGrafico* pGrafico;
		Gerenciador::GerenciadorEvento* pEvento;
		Gerenciador::GerenciadorColisao colisor;
		Lista::ListaEntidade listaPersonagem;
		Lista::ListaEntidade listaObstaculo;
		Parallax::Fundo fundo;

	public:
		Principal();
		~Principal();
		void executar();
		void instanciaEntidades();
		void criaPlataforma(const sf::Vector2f pos);
		void criaCaixa(const sf::Vector2f pos);
		void criaInimigo(const sf::Vector2f pos, Entidade::Personagem::Jogador::Jogador* jogador);
	};
}