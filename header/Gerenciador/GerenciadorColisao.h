#pragma once 

#include <SFML\Graphics.hpp>
#include "..\Lista\ListaEntidade.h"
#include <math.h>

namespace Fantasy {

    namespace Gerenciador {

        class GerenciadorColisao {
        private:
            Lista::ListaEntidade* listaPersonagem;
            Lista::ListaEntidade* listaObstaculo;
        public:
            GerenciadorColisao(Lista::ListaEntidade* listaPersonagem, Lista::ListaEntidade* listaObstaculo);
            ~GerenciadorColisao();
            const sf::Vector2f calculaColisao(Entidade::Entidade* ent1, Entidade::Entidade* ent2);
            void executar();
        };
    }
}