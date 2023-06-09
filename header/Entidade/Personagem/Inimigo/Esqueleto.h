#pragma once

#include "Inimigo.h"

#define TAMANHO_ESQUELETO_X 50.0f
#define TAMANHO_ESQUELETO_Y 90.0f

namespace Fantasy {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                class Esqueleto : public Inimigo {
                private:
                    void inicializa();
                public:
                    Esqueleto(const sf::Vector2f pos, Jogador::Jogador* jogador);
                    ~Esqueleto();
                };

            }

        }

    }

}