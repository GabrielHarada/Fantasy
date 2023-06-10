#pragma once 

#include "..\Estado\EstadoJogar.h"
#include "..\Construtor\ConstrutorFase.h"
#include "..\Estado\EstadoMenuPausa.h"
#include "..\Estado\EstadoMenuPrincipal.h"
#include "..\Estado\EstadoMenuOpcaoPrincipal.h"

namespace Fantasy {

    namespace Construtor {

        class ConstrutorEstado {
        private:
            Estado::Estado* criarEstadoJogar(const IDs::IDs ID);
            Estado::Estado* criarMenuPrincipal();
            Estado::Estado* criarMenuPausar();
            Estado::Estado* criarMenuOpcaoPrincipal();
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