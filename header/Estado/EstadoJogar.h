#pragma once

#include "Estado.h"

#include "..\Gerenciador\GerenciadorGrafico.h"

#include "..\Fase\FlorestaBranca.h"
#include "..\Fase\FlorestaVermelha.h"

#include "..\Construtor\ConstrutorEstado.h"

namespace Fantasy {

    namespace Estado {

        class EstadoJogar : public Estado {
        private:
            Fase::Fase* fase;
        public:
            EstadoJogar(const IDs::IDs ID, Fase::Fase* fase);
            ~EstadoJogar();
            Fase::Fase* getFase();
            void executar();
            void mudarEstadoObservador();
        };

    }

}