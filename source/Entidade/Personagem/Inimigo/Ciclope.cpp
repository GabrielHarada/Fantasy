#include "..\..\header\Entidade\Personagem\Inimigo\Ciclope.h"

Fantasy::Entidade::Personagem::Inimigo::Ciclope::Ciclope(const sf::Vector2f pos, Jogador::Jogador* jogador) :
    Inimigo(pos, sf::Vector2f(TAMANHO_ESQUELETO_X, TAMANHO_ESQUELETO_Y), jogador, IDs::IDs::ciclope)
{
    inicializa();
}

Fantasy::Entidade::Personagem::Inimigo::Ciclope::~Ciclope()
{
}

void Fantasy::Entidade::Personagem::Inimigo::Ciclope::inicializa() {
    animacao.addAnimacao("image/Inimigo/Ciclope/Paradob.png", "Parado", 15, 0.12f, sf::Vector2f(1.5f, 1.60f));
    animacao.addAnimacao("image/Inimigo/Ciclope/Anda.png", "Anda", 12, 0.15f, sf::Vector2f(1.5f, 1.60f));
    corpo.setOrigin(sf::Vector2f(tam.x / 12.0f, tam.y / 8.5f));
}

