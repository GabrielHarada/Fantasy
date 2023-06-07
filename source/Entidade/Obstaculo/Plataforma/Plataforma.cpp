#pragma once
#include "..\..\header\Entidade\Obstaculo\Plataforma\Plataforma.h"

Fantasy::Entidade::Obstaculo::Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, int tipoPlataforma) :
    Obstaculo(pos, tam, IDs::IDs::plataforma, CAMINHO_TEXTURA_PLATAFORMA), tipoPlataforma(tipoPlataforma)
{
    //textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_PLATAFORMA);
    //corpo.setTexture(&textura);
    //corpo.setFillColor(sf::Color::Cyan);
}

Fantasy::Entidade::Obstaculo::Plataforma::~Plataforma() {

}

void Fantasy::Entidade::Obstaculo::Plataforma::colisao(Entidade* outraEntidade, sf::Vector2f ds) {
    sf::Vector2f posOutro = outraEntidade->getPos();
    sf::Vector2f tamOutro = outraEntidade->getTam();

    if (outraEntidade->getID() == IDs::IDs::jogador || outraEntidade->getID() == IDs::IDs::inimigo) {
        colisaoObstaculo(ds, static_cast<Personagem::Personagem*>(outraEntidade));
    }
}