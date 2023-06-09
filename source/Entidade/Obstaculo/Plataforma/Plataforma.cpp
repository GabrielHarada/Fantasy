#pragma once
#include "..\..\header\Entidade\Obstaculo\Plataforma\Plataforma.h"

Fantasy::Entidade::Obstaculo::Plataforma::Plataforma(sf::Vector2f pos, int tipoPlataforma) :
    Obstaculo(pos, sf::Vector2f(TAMANHO_PLATAFORMA_X, TAMANHO_PLATAFORMA_Y), IDs::IDs::plataforma, CAMINHO_TEXTURA_PLATAFORMA),
    tipoPlataforma(tipoPlataforma)
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

    if (outraEntidade->getID() == IDs::IDs::jogador || outraEntidade->getID() == IDs::IDs::esqueleto || outraEntidade->getID() == IDs::IDs::minotauro || outraEntidade->getID() == IDs::IDs::ciclope) {
        colisaoObstaculo(ds, static_cast<Personagem::Personagem*>(outraEntidade));
    }
}