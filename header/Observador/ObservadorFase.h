#pragma once

#include "Observador.h"
#include "..\Fase\Fase.h"

namespace Fantasy {

    namespace Observador {

        class ObservadorFase : public Observador {
        private:
            Fase::Fase* fase;
        public:
            ObservadorFase(Fase::Fase* fase);
            ~ObservadorFase();
            void teclaPressionada(const sf::Keyboard::Key tecla);
            void teclaSolta(const sf::Keyboard::Key tecla);
        };

    }

}