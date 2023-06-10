#pragma once 

#include "..\..\Ente.h"
#include "TextoAnimado.h"
#include <string>

#define CAMINHO_FONTE "image/fonte/menu.ttf"
#define TEMPO_TROCAR_COR 0.01f

namespace Fantasy {

    namespace Menu {

        namespace Botao {

            class Botao : public Ente {
            private:
                sf::RectangleShape caixaTexto;
                TextoAnimado texto;
                sf::Vector2f pos;
                sf::Vector2f tam;
                bool selecionado;
                sf::Clock relogio;
                const float tempoTrocaCor;
                float tempo;
            public:
                Botao(const std::string texto, const sf::Vector2f tam, const sf::Vector2f pos, const IDs::IDs ID);
                ~Botao();
                void desenhar();
                void atualizarTexto();
                void setSelecionado(const bool selecionado = true);
                const bool getSelecionado() const;
            };

        }

    }

}