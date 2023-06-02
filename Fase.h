#pragma once

#include "Ente.h"
#include "Entidade.h"

//Personagens
#include "Jogador.h"
#include "Inimigo.h"

//Obstaculos
#include "Caixa.h"
#include "Plataforma.h"

//Gerenciadores
#include "GerenciadorColisao.h"
#include "GerenciadorEvento.h"

//Listas
#include "ListaEntidade.h"

namespace Jogo {

    namespace Fase {

        class Fase : public Ente {
        protected:
            Lista::ListaEntidade listaPersonagens;
            Lista::ListaEntidade listaObstaculos;
            Gerenciador::GerenciadorColisao* pColisao;
        public:
            Fase(const IDs::IDs ID_Fase);
            ~Fase();
            virtual void criarEntidades() = 0;
            void executar();
            Entidade::Personagem::Jogador::Jogador* criarJogador(const sf::Vector2f pos);
            Entidade::Entidade* criarPlataforma(const sf::Vector2f pos);
            Entidade::Entidade* criarCaixa(const sf::Vector2f pos);
            Entidade::Entidade* criarInimigo(const sf::Vector2f pos, Entidade::Personagem::Jogador::Jogador* jogador);
            void desenhar();
        };

    }

}