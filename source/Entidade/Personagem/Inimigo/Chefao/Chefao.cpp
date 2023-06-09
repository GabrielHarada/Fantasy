#pragma once 

#include "..\..\..\..\..\header\Entidade\Personagem\Inimigo\Chefao\Chefao.h"

Fantasy::Entidade::Personagem::Inimigo::Chefao::Chefao::Chefao(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador, const IDs::IDs ID) :
    Inimigo(pos, tam, jogador, ID)
{
}

Fantasy::Entidade::Personagem::Inimigo::Chefao::Chefao::~Chefao()
{
}