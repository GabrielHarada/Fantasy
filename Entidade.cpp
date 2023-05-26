#include "Entidade.h"

Jogo::Entidade::Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID) :
    corpo(sf::RectangleShape(tam)), ID(ID), pos(pos), tam(tam)
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

const IDs::IDs Jogo::Entidade::Entidade::getID() const {
    return ID;
}