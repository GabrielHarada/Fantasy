#pragma once

#include "Observador.h"
#include "..\Menu\Botao\Botao.h"

namespace Fantasy {

    namespace Menu {
        class MenuPrincipal;
    }

    namespace Gerenciador {
        class GerenciadorEstado;
    }

    namespace Observador {

        class ObservadorMenuPrincipal : public Observador {
        private:
            Menu::MenuPrincipal* menuPrincipal;
            static Gerenciador::GerenciadorEstado* pGEstado;
        public:
            ObservadorMenuPrincipal(Menu::MenuPrincipal* menuPrincipal);
            ~ObservadorMenuPrincipal();
            void teclaPressionada(const sf::Keyboard::Key tecla);
            void teclaSolta(const sf::Keyboard::Key tecla);
        };

    }

}