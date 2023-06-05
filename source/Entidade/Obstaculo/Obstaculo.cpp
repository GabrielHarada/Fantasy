#pragma once
#include "..\..\header\Entidade\Obstaculo\Obstaculo.h"

Jogo::Entidade::Obstaculo::Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID) :
    Entidade(pos, tam, ID)
{

}

Jogo::Entidade::Obstaculo::Obstaculo::~Obstaculo() {

}

void Jogo::Entidade::Obstaculo::Obstaculo::atualizar() {
    desenhar();
}