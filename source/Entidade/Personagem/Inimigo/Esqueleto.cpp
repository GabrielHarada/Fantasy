#include "..\..\..\..\header\Entidade\Personagem\Inimigo\Esqueleto.h"

Fantasy::Entidade::Personagem::Inimigo::Esqueleto::Esqueleto(const sf::Vector2f pos, Jogador::Jogador* jogador) :
    Inimigo(pos, sf::Vector2f(TAMANHO_ESQUELETO_X, TAMANHO_ESQUELETO_Y), jogador, IDs::IDs::esqueleto)
{
    inicializa();
}

Fantasy::Entidade::Personagem::Inimigo::Esqueleto::~Esqueleto() {

}

void Fantasy::Entidade::Personagem::Inimigo::Esqueleto::inicializa() {
    animacao.addAnimacao("image/Inimigo/Esqueleto/Parado.png", "Parado", 11, 0.12f, sf::Vector2f(1.0f, 1.10f));
    animacao.addAnimacao("image/Inimigo/Esqueleto/Anda.png", "Anda", 13, 0.15f, sf::Vector2f(1.0f, 1.10f));
    corpo.setOrigin(sf::Vector2f(tam.x / 12.0f, tam.y / 8.5f));
}