#include "..\..\..\..\..\header\Entidade\Personagem\Inimigo\Chefao\Minotauro.h"

Fantasy::Entidade::Personagem::Inimigo::Chefao::Minotauro::Minotauro(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador) :
    Chefao(pos, tam, jogador, IDs::IDs::minotauro)
{
    inicializa();
}

Fantasy::Entidade::Personagem::Inimigo::Chefao::Minotauro::~Minotauro()
{
}

void Fantasy::Entidade::Personagem::Inimigo::Chefao::Minotauro::inicializa() {
    animacao.addAnimacao("image/Inimigo/Minotauro/Parado.png", "Parado", 5, 0.15f, sf::Vector2f(4.0f, 2.1f));
    animacao.addAnimacao("image/Inimigo/Minotauro/abc.png", "Anda", 5, 0.2f, sf::Vector2f(4.0f, 2.07f));
    corpo.setOrigin(sf::Vector2f(tam.x / 3.0f, tam.y / 6.0f));
}

