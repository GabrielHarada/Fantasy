#pragma once

#include "Estado.h"

#include "..\Gerenciador\GerenciadorGrafico.h"

#include "..\Fase\FlorestaBranca.h"
#include "..\Fase\FlorestaVermelha.h"

namespace Fantasy {

    namespace Estado {

        class EstadoJogar : public Estado {
        private:
            Fase::Fase* fase;
        public:
            EstadoJogar(Fase::Fase* fase);
            ~EstadoJogar();
            void executar();
        };

    }

}