#pragma once 

#include "..\Estado\EstadoJogar.h"
#include "..\Construtor\ConstrutorFase.h"
#include "..\Estado\EstadoMenuPrincipal.h"

namespace Fantasy {

    namespace Construtor {

        class ConstrutorEstado {
        private:
            Estado::Estado* criarEstadoJogar(const IDs::IDs ID);
            Estado::Estado* criarMenuPrincipal(const IDs::IDs ID = IDs::IDs::estado_menu_principal);
            //Estado::Estado* criarMenuPausar();
            //Estado::Estado* criarMenuSalvar();
            //Estado::Estado* criarMenuOpcao();
            //Estado::Estado* criarColocao();
        public:
            ConstrutorEstado();
            ~ConstrutorEstado();
            Estado::Estado* criarEstado(const IDs::IDs ID);
        };

    }

}