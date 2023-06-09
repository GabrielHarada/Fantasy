#pragma once

#include "Menu.h"
#include "..\Fase\Fase.h"

#define TAMANHO_BOTAO_X 350.0f
#define TAMANHO_BOTAO_Y 50.0f

namespace Fantasy {

    namespace Observador {
        class ObservadorMenuPausa;
    }

    namespace Menu {

        class MenuPausa : public Menu {
        private:
            Fase::Fase* fase;
            Observador::ObservadorMenuPausa* observadorMenuPausa;
            sf::RectangleShape fundoEscuro;
            sf::RectangleShape fundoPainel;

            void criarBotoes();
            void atualizarFundo();
            void atualizarNomeMenu();
            void atualizarBotoes();
        public:
            MenuPausa(Fase::Fase* fase = nullptr);
            ~MenuPausa();
            void setFase(Fase::Fase* fase);
            void mudarEstadoObservador();
            void executar();
        };

    }

}