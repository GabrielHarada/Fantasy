#pragma once
#include "Principal.h"

Jogo::Principal::Principal() :
	window(sf::VideoMode(1280.0f, 1024.0f), "Jogo++"), personagens()
{
	Personagem::Jogador::Jogador* jogador = new Personagem::Jogador::Jogador(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(50.0f, 50.0f));
	Personagem::Inimigo::Inimigo* inimigo = new Personagem::Inimigo::Inimigo(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(50.0f, 50.0f), jogador);

	Personagem::Personagem* p1 = static_cast<Personagem::Personagem*>(jogador);
	Personagem::Personagem* p2 = static_cast<Personagem::Personagem*>(inimigo);

	personagens.push_back(p1);
	personagens.push_back(p2);

	executar();

	delete p1;
	delete p2;
}

Jogo::Principal::~Principal() {

}

void Jogo::Principal::executar() {
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
		for (int i = 0; i < personagens.size(); i++) {
			personagens.at(i)->move();
		}
		for (int i = 0; i < personagens.size(); i++) {
			window.draw(personagens.at(i)->getCorpo());
		}
		window.display();
	}
	personagens.clear();
}