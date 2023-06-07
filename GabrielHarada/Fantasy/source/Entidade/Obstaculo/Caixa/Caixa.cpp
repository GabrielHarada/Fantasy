#pragma once
#include "..\..\header\Entidade\Obstaculo\Caixa\Caixa.h"

Fantasy::Entidade::Obstaculo::Caixa::Caixa(sf::Vector2f pos, sf::Vector2f tam) :
    Obstaculo(pos, tam, IDs::IDs::caixa), podeEmpurrar(false)
{

}

Fantasy::Entidade::Obstaculo::Caixa::~Caixa() {

}

void Fantasy::Entidade::Obstaculo::Caixa::colisao(Entidade* outraEntidade, sf::Vector2f ds) {

}