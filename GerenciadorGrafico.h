#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Personagem.h"
#include "Jogador.h"

namespace Jogo{
  namespace Gerenciador{
    class GerenciadorGrafico
    {
    private:
      sf::RenderWindow* window;
      static GerenciadorGrafico* pGrafico;
      GerenciadorGrafico();
    public:
      ~GerenciadorGrafico();
      static GerenciadorGrafico* getGerenciadorGrafico();
      sf::RenderWindow* getWindow();
      void limpaJanela();
      void desenhaElementos(sf::RectangleShape corpo);
      void fechaJanela();
      void mostraElementos();
      const bool verificaJanelaAberta();
    };
  }
}