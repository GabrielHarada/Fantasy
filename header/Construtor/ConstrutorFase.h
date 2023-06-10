#pragma once

//gerenciadores
#include "..\Gerenciador\GerenciadorEvento.h"

#include "..\Fase\FlorestaBranca.h"
#include "..\Fase\FlorestaVermelha.h"

namespace Fantasy {

    namespace Construtor {

        class ConstrutorFase {
        private:
            Fase::Fase* criarFlorestaBranca();
            Fase::Fase* criarFlorestaVermelha();
        public:
            ConstrutorFase();
            ~ConstrutorFase();
            Fase::Fase* criarFase(const IDs::IDs ID);
        };

    }

}