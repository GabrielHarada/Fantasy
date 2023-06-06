#include "..\..\header\Animador\Animacao.h"

Fantasy::Animador::Animacao::Animacao(sf::RectangleShape* corpo) :
    pGrafico(pGrafico->getGerenciadorGrafico()), corpo(corpo), mapTextura()
{

}

Fantasy::Animador::Animacao::~Animacao() {

}

void Fantasy::Animador::Animacao::atualizar() {
    //atualizar animacao;
}