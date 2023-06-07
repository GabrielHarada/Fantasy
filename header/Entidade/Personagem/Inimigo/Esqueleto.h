#pragma once

#include "Inimigo.h"

namespace Fantasy {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                class Esqueleto : public Inimigo {
                private:
                    void inicializa();
                public:
                    Esqueleto(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador);
                    ~Esqueleto();
                };

            }

        }

    }

}