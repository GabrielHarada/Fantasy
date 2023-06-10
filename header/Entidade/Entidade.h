#pragma once

#include <SFML\Graphics.hpp>
#include "..\Gerenciador\GerenciadorGrafico.h"
#include <iostream>
#include "..\IDs.h"
#include "..\Ente.h"

namespace Fantasy{

    namespace Entidade {

        class Entidade : public Ente {
        protected:
            sf::RectangleShape corpo;
            sf::Vector2f pos;
            sf::Vector2f tam;
        public:
            Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
            virtual ~Entidade();
            const sf::RectangleShape getCorpo();
            void setPos(sf::Vector2f pos);
            sf::Vector2f getPos();
            const sf::Vector2f getTam();
            virtual void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
            virtual void atualizar() = 0;
            void desenhar();
        };

    }

}