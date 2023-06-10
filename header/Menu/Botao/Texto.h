#pragma once 

#include <SFML\Graphics.hpp>

namespace Fantasy {

    namespace Menu {

        namespace Botao {

            class Texto {
            private:
                sf::Font fonte;
                std::string info;

            protected:
                sf::Text texto;
                sf::Vector2f tam;
                sf::Color corTexto;
                sf::Color corBorda;
                unsigned int tamFonte;

                void inicializa();
            public:
                Texto(sf::Font fonte, const std::string texto, const unsigned int tamFonte = 50);
                ~Texto();
                const sf::Text getTexto() const;
                void setPos(const sf::Vector2f pos);
                sf::Vector2f getTam();
                void setCorTexto(const sf::Color corTexto);
            };

        }

    }

}