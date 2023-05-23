#pragma once
#include "Jogador.h"

void Jogo::Jogador::Jogador::inicializa()
{
	vel = sf::Vector2f(0.1f, 0.1f);
}

Jogo::Jogador::Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam):
	corpo(sf::RectangleShape(tam))
{
	corpo.setPosition(pos);
	corpo.setFillColor(sf::Color::Green);
	inicializa();
}

Jogo::Jogador::Jogador::Jogador(const sf::RectangleShape corpo):
	corpo(corpo)
{
	inicializa();
}

Jogo::Jogador::Jogador::Jogador():
	corpo()
{
	inicializa();
}

Jogo::Jogador::Jogador::~Jogador()
{
}

const sf::RectangleShape Jogo::Jogador::Jogador::getCorpo()
{
	return corpo;
}

void Jogo::Jogador::Jogador::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		corpo.move(-vel.x, 0.0f);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		corpo.move(vel.x, 0.0f);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		corpo.move(0.0f, -vel.y);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		corpo.move(0.0f, vel.y);
	}
}
