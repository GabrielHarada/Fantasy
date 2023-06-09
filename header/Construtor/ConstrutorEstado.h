#pragma once 

#include "..\Estado\EstadoJogar.h"
#include "..\Fase\FlorestaBranca.h"
#include "..\Fase\FlorestaVermelha.h"

namespace Fantasy {

    namespace Construtor {

        class ConstrutorEstado {
        public:
            ConstrutorEstado();
            ~ConstrutorEstado();
            Estado::Estado* addEstadoJogar(const IDs::IDs ID);
        };

    }

}