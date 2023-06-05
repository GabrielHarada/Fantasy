#pragma once

#include "..\Lista\Lista.h"
#include "..\Entidade\Entidade.h"

namespace Fantasy {

    namespace Lista {

        class ListaEntidade {
        private:
            Lista<Entidade::Entidade> objListaEntidade;
        public:
            ListaEntidade();
            ~ListaEntidade();
            void addEntidade(Entidade::Entidade* entidade);
            void removerEntidade(Entidade::Entidade* entidade);
            void removerEntidade(int pos);
            int getTam();
            Entidade::Entidade* operator[](int pos);
            void executar();
            void limparLista();
        };

    }

}