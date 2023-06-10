#pragma once 

#include "Observador.h"
#include "..\Menu\MenuOpcao.h"

namespace Fantasy {

    namespace Observador {

        class ObservadorMenuOpcao : public Observador {
        private:
            Menu::MenuOpcao* menuOpcao;
        public:
            ObservadorMenuOpcao(Menu::MenuOpcao* menuOpcao);
            ~ObservadorMenuOpcao();
            void teclaPressionada(const sf::Keyboard::Key tecla);
            void teclaSolta(const sf::Keyboard::Key tecla);
        };

    }

}