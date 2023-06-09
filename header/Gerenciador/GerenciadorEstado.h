#pragma once

#include "..\Estado\EstadoJogar.h"
#include "..\Construtor\ConstrutorEstado.h"
#include <stack>

namespace Fantasy {

    namespace Gerenciador {

        class GerenciadorEstado {
        private:
            std::stack<Estado::Estado*> pilhaEstados;
            Construtor::ConstrutorEstado construtor;

            //padrão de projeto singleton
            static GerenciadorEstado* pGerenciadorEstado;
            GerenciadorEstado();
        public:
            ~GerenciadorEstado();
            static GerenciadorEstado* getGerenciadorEstado();
            void executar();
            void addEstado(const IDs::IDs ID);
            void removerEstado();
        };

    }

}