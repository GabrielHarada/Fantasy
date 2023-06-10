#pragma once 

#include "MenuOpcao.h"
#include "..\Parallax\Fundo.h"


namespace Fantasy {

    namespace Observador {
        class ObservadorMenuOpcao;
    }

    namespace Menu {

        class MenuOpcaoPrincipal : public MenuOpcao {
        private:
            Parallax::Fundo fundo;
            Observador::ObservadorMenuOpcao* observadorMenuOpcao;

            void criarFundo();
            void criarBotoes();
        public:
            MenuOpcaoPrincipal();
            ~MenuOpcaoPrincipal();
            void executar();
        };

    }

}