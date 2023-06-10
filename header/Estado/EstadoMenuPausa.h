#pragma once

#include "..\Menu\MenuPausa.h"
#include "Estado.h"

namespace Fantasy {

    namespace Gerenciador {
        class GerenciadorEstado;
    }

    namespace Estado {

        class EstadoJogar;

        class EstadoMenuPausa : public Estado {
        private:
            Menu::MenuPausa menuPausa;
            EstadoJogar* estadoJogar;
            static Gerenciador::GerenciadorEstado* pGEstado;

        public:
            EstadoMenuPausa();
            ~EstadoMenuPausa();
            void mudarEstadoObservador();
            void executar();
        };

    }

}