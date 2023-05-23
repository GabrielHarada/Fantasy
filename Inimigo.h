#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <math.h>
#include "Personagem.h"
#include "Jogador.h"

#define VELOCIDADE_INIMIGO_X 0.025f
#define VELOCIDADE_INIMIGO_y 0.025f

#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f

namespace Jogo {
	namespace Personagem {
		namespace Inimigo {

			class Inimigo : public Personagem {
			private:
				Jogador::Jogador* jogador;
				sf::Clock relogio;
				short moveAleatorio;
				void inicializa();
			public:
				Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador);
				~Inimigo();
				void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
				void movimentoAleatorio();
				void move();
			};
		}
	}
}