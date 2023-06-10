#pragma once 

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

        class ConstrutorEntidade {
        private:
            Entidade::Personagem::Jogador::Jogador* pJogador;
            void verificaJogador();
        public:
            ConstrutorEntidade(Entidade::Personagem::Jogador::Jogador* pJogador);
            ConstrutorEntidade();
            ~ConstrutorEntidade();
            Entidade::Entidade* criarPlataforma(const sf::Vector2f pos);
            Entidade::Entidade* criarCaixa(const sf::Vector2f pos);
            Entidade::Entidade* criarEsqueleto(const sf::Vector2f pos);
            Entidade::Entidade* criarMinotauro(const sf::Vector2f pos);
            Entidade::Entidade* criarCiclope(const sf::Vector2f pos);
            Entidade::Entidade* criarJogador(const sf::Vector2f pos);



        };

    }

}