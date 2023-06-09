#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "..\Personagem.h"

#define VELOCIDADE_JOGADOR 200.0f
#define TAMANHO_PULO 0.1f
#define TAMANHO_JOGADOR_X 50.0f
#define TAMANHO_JOGADOR_Y 90.0f

namespace Fantasy {
	namespace Entidade {
		namespace Personagem {
			namespace Jogador {

				class Jogador : public Personagem {
				private:
					void inicializa();
					bool noChao;
				public:
					Jogador(const sf::Vector2f pos);
					~Jogador();
					void atualizar();
					void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
					void pular();
					void podePular();
					void atualizarAnimacao();
				};
			}
		}
	}
}