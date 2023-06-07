#include "..\..\header\Entidade\Entidade.h"

Fantasy::Entidade::Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID) :
    Ente(ID), corpo(sf::RectangleShape(tam)), pos(pos), tam(tam)
{
    corpo.setPosition(pos);
}

Fantasy::Entidade::Entidade::~Entidade() {

}
    
const sf::RectangleShape Fantasy::Entidade::Entidade::getCorpo() {
    return corpo;
}

void Fantasy::Entidade::Entidade::setPos(sf::Vector2f pos) {
    corpo.setPosition(pos);
    this->pos = pos;
}

sf::Vector2f Fantasy::Entidade::Entidade::getPos() {
    return pos;
}

const sf::Vector2f Fantasy::Entidade::Entidade::getTam() {
    return tam;
}

void Fantasy::Entidade::Entidade::desenhar() {
    pGrafico->desenhaElemento(corpo);
}