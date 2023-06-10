#pragma once

#include "Menu.h"
#include "Botao\Texto.h"
#include "..\Observador\ObservadorMenuPrincipal.h"

#define CAMINHO_TEXTURA_MENU_PRINCIPAL "image/Menu/menuPrincipal.png"
#define TAMANHO_BOTAO_X 350.0f
#define TAMANHO_BOTAO_Y 50.0f

namespace Fantasy {

    namespace Menu {

        class MenuPrincipal : public Menu {
        private:
            bool sair;
            Botao::Texto nomeJogo;
            Observador::ObservadorMenuPrincipal* observadorMenuPrincipal;

            void criarFundo();
            void criarBotoes();
        public:
            MenuPrincipal();
            ~MenuPrincipal();
            void setSair(const bool sair = true);
            const bool getSair() const;
            void selecionaCima();
            void selecionaBaixo();
            const IDs::IDs getIDBotaoSelecionado();
            void executar();
        };

    }

}