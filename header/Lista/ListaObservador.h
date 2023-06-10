#pragma once

#include "SFML\Graphics.hpp"
#include "Lista.h"
#include "..\Observador\Observador.h"

namespace Fantasy {

    namespace Lista {

        class ListaObservador {
        private:
            Lista<Observador::Observador> objListaObservador;
        public:
            ListaObservador();
            ~ListaObservador();
            void addObservador(Observador::Observador* observador);
            void removerObservador(Observador::Observador* observador);
            void removerObservador(int pos);
            int getTam();
            Observador::Observador* operator[](int pos);
            void notificarTeclaPressionada(const sf::Keyboard::Key tecla);
            void notificarTeclaSolta(const sf::Keyboard::Key tecla);
        };

    }

}