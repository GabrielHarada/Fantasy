#pragma once

#include "Estado.h"

#include "..\Gerenciador\GerenciadorGrafico.h"

#include "..\Fase\FlorestaBranca.h"
#include "..\Fase\FlorestaVermelha.h"

#include "..\Entidade\Personagem\Jogador\Jogador.h"

#include "..\Construtor\ConstrutorEstado.h"

namespace Fantasy {

    namespace Estado {

        class EstadoJogar : public Estado {
        private:
            Fase::Fase* fase;
        public:
            EstadoJogar(const IDs::IDs ID, Fase::Fase* fase);
            ~EstadoJogar();
            void executar();
            Entidade::Personagem::Jogador::Jogador* getJogador();
        };

    }

}