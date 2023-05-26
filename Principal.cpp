#pragma once
#include "Principal.h"

Jogo::Principal::Principal() :
	pGrafico(pGrafico->getGerenciadorGrafico()), personagens()
{
	if (pGrafico == nullptr) {
		std::cout << "ERROR::Jogo::Principal nao foi possivel criar o GerenciadorGrafico" << std::endl;
		exit(1);
	}
	Personagem::Jogador::Jogador* jogador = new Personagem::Jogador::Jogador(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(50.0f, 50.0f));
	Personagem::Inimigo::Inimigo* inimigo1 = new Personagem::Inimigo::Inimigo(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(50.0f, 50.0f), jogador);
	Personagem::Inimigo::Inimigo* inimigo2 = new Personagem::Inimigo::Inimigo(sf::Vector2f(400.0f, 400.0f), sf::Vector2f(50.0f, 50.0f), jogador);

	Personagem::Personagem* p1 = static_cast<Personagem::Personagem*>(jogador);
	Personagem::Personagem* p2 = static_cast<Personagem::Personagem*>(inimigo1);
	Personagem::Personagem* p3 = static_cast<Personagem::Personagem*>(inimigo2);

	personagens.push_back(p1);
	personagens.push_back(p2);
	personagens.push_back(p3);

	executar();

	delete p1;
	delete p2;
	delete p3;
}

Jogo::Principal::~Principal() {

}

void Jogo::Principal::executar() {
	while (pGrafico->verificaJanelaAberta()){
		sf::Event evento;
		if (pGrafico->getWindow()->pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				pGrafico->fecharJanela();
			}
			else if (evento.type == sf::Event::KeyPressed) {
				if (evento.key.code == sf::Keyboard::Escape) {
					pGrafico->fecharJanela();
				}
			}
		}

		pGrafico->limpaJanela();
		for (int i = 0; i < personagens.size(); i++) {
			personagens.at(i)->move();
		}
		for (int i = 0; i < personagens.size(); i++) {
			pGrafico->desenhaElemento(personagens.at(i)->getCorpo());
		}
		pGrafico->mostraElementos();
	}
	personagens.clear();
}