#pragma once

#include "..\Ente.h"
#include "..\IDs.h"
#include "Camada.h"

namespace Fantasy {

    namespace Parallax {

        class Fundo : public Ente {
        private:
            sf::Vector2f posAnteriorCamera;
            std::vector<Camada*> camadas;


        public:
            Fundo();
            ~Fundo();
            void desenhar();
            void addCamada(const char* caminhoTextura, const float vel);
            void executar();
        };

    }

}