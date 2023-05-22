#pragma once
#include "Principal.h"

Jogo::Principal::Principal():
	window(sf::VideoMode(800.0f, 600.0f), "Jogo++")
{
	executar();
}

Jogo::Principal::~Principal() {

}

void Jogo::Principal::executar() {
	sf::RectangleShape jogador(sf::Vector2f(50.0f, 50.0f));
	jogador.setFillColor(sf::Color::Blue);
	jogador.setPosition(50.0f, 50.0f);

	while (window.isOpen()){
		sf::Event evento;
		if (window.pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				window.close();
			}
			else if (evento.type == sf::Event::KeyPressed) {
				if (evento.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}
		}

		window.clear();
		window.draw(jogador);
		window.display();
	}
}