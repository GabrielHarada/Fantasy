#pragma once 

#include "Obstaculo.h"

//textura
#define CAMINHO_TEXTURA_CAIXA "Jogo++/img/Obstaculo/caixa.png"
#define ESCALA_CAIXA_X 1
#define ESCALA_CAIXA_Y 1

namespace Jogo {

    namespace Entidade {

        namespace Obstaculo {

            class Caixa : public Obstaculo {
            private:
                bool podeEmpurrar;
            public:
                Caixa(sf::Vector2f pos, sf::Vector2f tam);
                ~Caixa();
                void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void atualizar();
            };

        }

    }

}