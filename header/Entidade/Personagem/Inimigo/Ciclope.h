#pragma once 

#include "..\Jogador\Jogador.h"
#include "..\Inimigo\Inimigo.h"

namespace Fantasy {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {


                class Ciclope : public Inimigo {
                private:
                    void inicializa();
                public:
                    Ciclope(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador);
                    ~Ciclope();
                };

            }

        }

    }

}