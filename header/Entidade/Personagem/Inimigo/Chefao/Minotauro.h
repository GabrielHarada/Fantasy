#pragma once 

#include "..\..\Jogador\Jogador.h"
#include "Chefao.h"

namespace Fantasy {

    namespace Entidade {

        namespace Personagem {

            namespace Inimigo {

                namespace Chefao {

                    class Minotauro : public Chefao {
                    private:
                        void inicializa();
                    public:
                        Minotauro(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador);
                        ~Minotauro();
                    };

                }

            }

        }

    }

}