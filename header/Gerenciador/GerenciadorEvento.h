#pragma once

#include "..\Gerenciador\GerenciadorGrafico.h"
#include "..\Entidade\Personagem\Jogador\Jogador.h"

namespace Jogo {

    namespace Gerenciador {

        class GerenciadorEvento {
        private:
            GerenciadorGrafico* pGrafico;
            Entidade::Personagem::Jogador::Jogador* pJogador;

            //padrão de projeto singleton
            static GerenciadorEvento* pEvento;
            GerenciadorEvento();
        public:
            ~GerenciadorEvento();
            static GerenciadorEvento* getGerenciadorEvento();
            void setJogador(Entidade::Personagem::Jogador::Jogador* pJogador);
            void verificaTeclaPressionada(sf::Keyboard::Key tecla);
            void verificaTeclaSolta(sf::Keyboard::Key tecla);
            void executar();
        };

    }

}