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
            protected:
                sf::RectangleShape caixaTexto;
                TextoAnimado texto;
                sf::Vector2f pos;
                sf::Vector2f tam;
                bool selecionado;
                const sf::Color corSelecionado;
                sf::Clock relogio;
                const float tempoTrocaCor;
                float tempo;

                const sf::Vector2f getTamTexto() const;
            public:
                Botao(const std::string info, const sf::Vector2f tam, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado);
                virtual ~Botao();
                virtual void desenhar();
                void atualizarTexto();
                void setSelecionado(const bool selecionado = true);
                const bool getSelecionado() const;
                void atualizarPosicao(const sf::Vector2f pos);
                const sf::Vector2f getPos() const;
            };

        }

    }

}