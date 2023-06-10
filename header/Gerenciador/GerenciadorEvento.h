#pragma once

#include "..\Gerenciador\GerenciadorGrafico.h"
#include "..\Entidade\Personagem\Jogador\Jogador.h"
#include "..\Lista\ListaObservador.h"

namespace Fantasy {

    namespace Gerenciador {

        class GerenciadorEstado;

        class GerenciadorEvento {
        private:
            static GerenciadorGrafico* pGrafico;
            static GerenciadorEstado* pGEstado;
            static Lista::ListaObservador* listaObservador;

            //padrão de projeto singleton
            static GerenciadorEvento* pEvento;
            GerenciadorEvento();
        public:
            ~GerenciadorEvento();
            static GerenciadorEvento* getGerenciadorEvento();
            void addObservador(Observador::Observador* observador);
            void removerObservador(Observador::Observador* observador);
            void removerObservador(int pos);
            void executar();
        };

    }

}