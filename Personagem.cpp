#include "Personagem.h"

Jogo::Personagem::Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam):
	corpo(sf::RectangleShape(tam))
{
	corpo.setPosition(pos);
}

Jogo::Personagem::Personagem::~Personagem()
{
}

const sf::RectangleShape Jogo::Personagem::Personagem::getCorpo()
{
	return corpo;
}
