#pragma once

#include "Menu.h"

#define TAMANHO_BOTAO_MENU_OPCAO_X 350.0f
#define TAMANHO_BOTAO_MENU_OPCAO_Y 80.0f

namespace Fantasy {

    namespace Menu {

        class MenuOpcao : public Menu {
        protected:
            //const float velocidadeBotao;

            void addBotao(const std::string info, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado, const float posInicioFundo);
        public:
            MenuOpcao();
            ~MenuOpcao();
            void executar() = 0;
        };

    }

}