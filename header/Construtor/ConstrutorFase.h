#pragma once

//gerenciadores
#include "..\Gerenciador\GerenciadorEvento.h"

//personagens
#include "..\Entidade\Personagem\Jogador\Jogador.h"
#include "..\Entidade\Personagem\Inimigo\Esqueleto.h"
#include "..\Entidade\Personagem\Inimigo\Ciclope.h"
#include "..\Entidade\Personagem\Inimigo\Chefao\Minotauro.h"

//obstaculos
#include "..\Entidade\Obstaculo\Caixa\Caixa.h"
#include "..\Entidade\Obstaculo\Plataforma\Plataforma.h"

namespace Fantasy {

    namespace Construtor {

        class ConstrutorFase {
        public:
            ConstrutorFase();
            ~ConstrutorFase();
            Entidade::Entidade* criarPlataforma(const sf::Vector2f pos);
            Entidade::Entidade* criarCaixa(const sf::Vector2f pos);
            Entidade::Entidade* criarJogador(const sf::Vector2f pos);
            Entidade::Entidade* criarEsqueleto(const sf::Vector2f pos);
            Entidade::Entidade* criarMinotauro(const sf::Vector2f pos);
            Entidade::Entidade* criarCiclope(const sf::Vector2f pos);
        };

    }

}