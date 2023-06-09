#pragma once

#include <fstream>

#include "..\Ente.h"
#include "..\Parallax\Fundo.h"

#include "..\Construtor\ConstrutorFase.h"

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
            Construtor::ConstrutorFase construtor;
        public:
            Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo);
            ~Fase();
            virtual void criarFundo() = 0;
            virtual void criarMapa() = 0;
            void criarEntidade(char letra, const sf::Vector2i pos);
            void executar();
            void desenhar();
        };

    }

}