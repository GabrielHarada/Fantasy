#pragma once 
#include "GerenciadorGrafico.h"

Jogo::Gerenciador::GerenciadorGrafico* Jogo::Gerenciador::GerenciadorGrafico::pGrafico =  nullptr;

Jogo::Gerenciador::GerenciadorGrafico::GerenciadorGrafico():
  window(new sf::RenderWindow(sf::VideoMode(800.0f,600.0f),"Jogo"))
{
  if(window = nullptr)
  {
    std::cout <<"ERROR::Jogo::Gerenciador::GerenciadorGrafico nao conseguiu criar uma janela grafica"<< std::endl;
    exit(1);
  }
}

Jogo::Gerenciador::GerenciadorGrafico::~GerenciadorGrafico(){
  if(window){
    delete(window);
    window = nullptr;
  }
}
sf::RenderWindow* Jogo::Gerenciador::GerenciadorGrafico::getWindow(){
  return window;
}
Jogo::Gerenciador::GerenciadorGrafico* Jogo::Gerenciador::GerenciadorGrafico::getGerenciadorGrafico(){
  if (pGrafico = nullptr)
  {
    return new Jogo::Gerenciador::GerenciadorGrafico();
  }
  
}
void Jogo::Gerenciador::GerenciadorGrafico::limpaJanela(){
  window->clear();
}
void Jogo::Gerenciador::GerenciadorGrafico::fechaJanela(){
  window->close();
}
void Jogo::Gerenciador::GerenciadorGrafico::desenhaElementos(sf::RectangleShape corpo){
  window->draw(corpo);
}
const bool Jogo::Gerenciador::GerenciadorGrafico::verificaJanelaAberta(){
  if(window->isOpen()){
    return true;
  }
  return false;
}