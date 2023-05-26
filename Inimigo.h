#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <math.h>

#include "Personagem.h"
#include "Jogador.h"

#define VELOCIDADE_INIMIGO 60.0f

#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f

namespace Jogo {
	namespace Entidade {
		namespace Personagem {
			namespace Inimigo {

				class Inimigo : public Personagem {
				private:
					Jogador::Jogador* jogador;
					float dtAux;
					short moveAleatorio;
					void inicializa();
				public:
					Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador);
					~Inimigo();
					void atualizaMovimentoAleatorio();
					void atualizar();
					void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
				};
			}
		}
	}
}