#pragma once 

#include "..\Jogador\Jogador.h"
#include "..\Inimigo\Inimigo.h"

#define TAMANHO_ESQUELETO_X 50.0f
#define TAMANHO_ESQUELETO_Y 90.0f

namespace Fantasy {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {


                class Ciclope : public Inimigo {
                private:
                    void inicializa();
                public:
                    Ciclope(const sf::Vector2f pos, Jogador::Jogador* jogador);
                    ~Ciclope();
                };

            }

        }

    }

}