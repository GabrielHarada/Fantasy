#pragma once
#include "..\..\header\Entidade\Obstaculo\Obstaculo.h"

Fantasy::Entidade::Obstaculo::Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID) :
    Entidade(pos, tam, ID)
{

}

Fantasy::Entidade::Obstaculo::Obstaculo::~Obstaculo() {

}

void Fantasy::Entidade::Obstaculo::Obstaculo::atualizar() {
    desenhar();
}