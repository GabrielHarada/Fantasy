#pragma once

#include "..\Estado\EstadoJogar.h"
#include "..\Construtor\ConstrutorEstado.h"
#include "GerenciadorGrafico.h"
#include <stack>

namespace Fantasy {

    namespace Gerenciador {

        class GerenciadorEstado {
        private:
            std::stack<Estado::Estado*> pilhaEstados;
            Construtor::ConstrutorEstado construtorEstado;

            //padrão de projeto singleton
            static GerenciadorEstado* pGerenciadorEstado;
            GerenciadorEstado();
            void desativarObservadores();
            void ativarObservadores();
        public:
            ~GerenciadorEstado();
            static GerenciadorEstado* getGerenciadorEstado();
            void executar();
            void addEstado(const IDs::IDs ID);
            void removerEstado();
            Estado::Estado* getEstadoAtual();
        };

    }

}