#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "..\Personagem.h"

#define VELOCIDADE_JOGADOR 200.0f
#define TAMANHO_PULO 0.03f

namespace Fantasy {
	namespace Entidade {
		namespace Personagem {
			namespace Jogador {

				class Jogador : public Personagem {
				private:
					void inicializa();
					bool noChao;
					Animador::Animacao animacao;
				public:
					Jogador(const sf::Vector2f pos, const sf::Vector2f tam);
					~Jogador();
					void atualizar();
					void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
					void pular();
					void podePular();
				};
			}
		}
	}
}