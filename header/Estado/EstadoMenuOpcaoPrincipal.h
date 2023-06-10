#pragma once

#include "Estado.h"
#include "..\Menu\MenuOpcaoPrincipal.h"

namespace Fantasy {

    namespace Estado {

        class EstadoMenuOpcaoPrincipal : public Estado {
        private:
            Menu::MenuOpcaoPrincipal menuOpcaoPrincipal;
        public:
            EstadoMenuOpcaoPrincipal();
            ~EstadoMenuOpcaoPrincipal();
            void mudarEstadoObservador();
            void executar();
        };

    }

}