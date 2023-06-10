#pragma once

#include "..\Menu\MenuPrincipal.h"
#include "Estado.h"

namespace Fantasy {

    namespace Estado {

        class EstadoMenuPrincipal : public Estado {
        private:
            Menu::MenuPrincipal menuPrincipal;
        public:
            EstadoMenuPrincipal(const IDs::IDs ID = IDs::IDs::estado_menu_principal);
            ~EstadoMenuPrincipal();
            void executar();
        };

    }

}