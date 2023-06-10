#pragma once

#include <fstream>

#include "..\Ente.h"
#include "..\Parallax\Fundo.h"

#include "..\Gerenciador\GerenciadorColisao.h"

#include "..\Lista\ListaEntidade.h"

#include "..\Construtor\ConstrutorEntidade.h"

namespace Fantasy {

    namespace Fase {

        class Fase : public Ente {
        protected:
            Lista::ListaEntidade listaPersonagens;
            Lista::ListaEntidade listaObstaculos;
            Construtor::ConstrutorEntidade construtorEntidade;
            Gerenciador::GerenciadorColisao* pColisao;
            Parallax::Fundo fundo;
        public:
            Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo);
            ~Fase();
            virtual void criarFundo() = 0;
            virtual void criarMapa() = 0;
            void criarEntidade(char letra, const sf::Vector2i pos);
            void executar();
            void desenhar();
            Entidade::Personagem::Jogador::Jogador* getJogador();
        };

    }

}