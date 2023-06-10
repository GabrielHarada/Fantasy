#pragma once

#include "Observador.h"
#include "..\Entidade\Personagem\Jogador\Jogador.h"

namespace Fantasy {

    namespace Observador {

        class ObservadorJogador : public Observador {
        private:
            Entidade::Personagem::Jogador::Jogador* pJogador;
        public:
            ObservadorJogador(Entidade::Personagem::Jogador::Jogador* pJogador);
            ~ObservadorJogador();
            void teclaPressionada(const sf::Keyboard::Key tecla);
            void teclaSolta(const sf::Keyboard::Key tecla);
        };

    }

}