#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <math.h>

#include "..\Personagem.h"
#include "..\Jogador\Jogador.h"

#define VELOCIDADE_INIMIGO 60.0f

#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f

namespace Fantasy {
	namespace Entidade {
		namespace Personagem {
			namespace Inimigo {

				class Inimigo : public Personagem {
				private:
					Jogador::Jogador* jogador;
					float dtAux;
					short moveAleatorio;

					virtual void inicializa() = 0;
					void moveInimigo();
					void atualizaMovimentoAleatorio();
				public:
					Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador, const IDs::IDs ID);
					~Inimigo();
					virtual void atualizar();
					void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
				};
			}
		}
	}
}