#include "..\..\header\Entidade\Entidade.h"

Jogo::Entidade::Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID) :
    Ente(ID), corpo(sf::RectangleShape(tam)), pos(pos), tam(tam)
{
    corpo.setPosition(pos);
}

Jogo::Entidade::Entidade::~Entidade() {

}
    
const sf::RectangleShape Jogo::Entidade::Entidade::getCorpo() {
    return corpo;
}

void Jogo::Entidade::Entidade::setPos(sf::Vector2f pos) {
    corpo.setPosition(pos);
    this->pos = pos;
}

const sf::Vector2f Jogo::Entidade::Entidade::getPos() {
    return pos;
}

const sf::Vector2f Jogo::Entidade::Entidade::getTam() {
    return tam;
}

void Jogo::Entidade::Entidade::desenhar() {
    pGrafico->desenhaElemento(corpo);
}