#pragma once

#include "..\Obstaculo.h"
#include "..\..\Personagem\Personagem.h"

#define CAMINHO_TEXTURA_PLATAFORMA "image/Obstaculo/plataforma.png"
#define ESCALA_PLATAFORMA_X 1
#define ESCALA_PLATAFORMA_Y 1
#define TAMANHO_PLATAFORMA_X 300.0f
#define TAMANHO_PLATAFORMA_Y 50.0f

namespace Fantasy {

    namespace Entidade {

        namespace Obstaculo {

            class Plataforma : public Obstaculo {
            private:
                int tipoPlataforma;
            public:
                Plataforma(sf::Vector2f pos, int tipoPlataforma = 1);
                ~Plataforma();
                void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
            };

        }

    }

}