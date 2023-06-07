#pragma once

#include <fstream>

#include "..\Ente.h"
#include "..\Parallax\Fundo.h"

#include "..\Entidade\Personagem\Jogador\Jogador.h"
#include "..\Entidade\Personagem\Inimigo\Esqueleto.h"
#include "..\Entidade\Personagem\Inimigo\Chefao\Chefao.h"
#include "..\Entidade\Personagem\Inimigo\Ciclope.h"

#include "..\Entidade\Obstaculo\Caixa\Caixa.h"
#include "..\Entidade\Obstaculo\Plataforma\Plataforma.h"

#include "..\Gerenciador\GerenciadorColisao.h"
#include "..\Gerenciador\GerenciadorEvento.h"

#include "..\Lista\ListaEntidade.h"

namespace Fantasy {

    namespace Fase {

        class Fase : public Ente {
        protected:
            Lista::ListaEntidade listaPersonagens;
            Lista::ListaEntidade listaObstaculos;
            Gerenciador::GerenciadorColisao* pColisao;
            Parallax::Fundo fundo;
        public:
            Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo);
            ~Fase();
            void criarEsqueleto(const sf::Vector2f pos);
            void criarCiclope(const sf::Vector2f pos);
            void criarJogador(const sf::Vector2f pos);
            void criarPlataforma(const sf::Vector2f pos);
            void criarCaixa(const sf::Vector2f pos);
            virtual void criarFundo() = 0;
            virtual void criarMapa() = 0;
            void criarEntidade(char letra, const sf::Vector2i pos);
            void executar();
            void desenhar();
        };

    }

}