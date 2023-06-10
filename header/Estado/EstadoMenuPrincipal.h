#pragma once

#include "..\Menu\MenuPrincipal.h"
#include "Estado.h"

namespace Fantasy {

    namespace Estado {

        class EstadoMenuPrincipal : public Estado {
        private:
            Menu::MenuPrincipal menuPrincipal;
        public:
            EstadoMenuPrincipal();
            ~EstadoMenuPrincipal();
            void mudarEstadoObservador();
            void executar();
        };

    }

}