#pragma once
#include "..\header\Principal.h"

Fantasy::Principal::Principal() :
	listaPersonagem(), listaObstaculo(), pGrafico(pGrafico->getGerenciadorGrafico()),
	pEvento(pEvento->getGerenciadorEvento()),
	colisor(&listaPersonagem, &listaObstaculo)
{
	if (pGrafico == nullptr) {
		std::cout << "ERROR::Fantasy::Principal nao foi possivel criar o GerenciadorGrafico" << std::endl;
		exit(1);
	}
	if (pEvento == nullptr) {
		std::cout << "ERROR::Fantasy::Principal nao foi possivel criar o GerenciadorEvento" << std::endl;
		exit(1);
	}

	instanciaEntidades();

	executar();
}

Fantasy::Principal::~Principal() {
	listaObstaculo.limparLista();
	listaPersonagem.limparLista();
}

void Fantasy::Principal::instanciaEntidades() {

	Entidade::Personagem::Jogador::Jogador* jogador = new Entidade::Personagem::Jogador::Jogador(sf::Vector2f(500.0f, 100.0f), sf::Vector2f(50.0f, 90.0f));
	//Entidade::Personagem::Inimigo::Inimigo* i1 = new Entidade::Personagem::Inimigo::Inimigo(sf::Vector2f(500.0f, 100.0f), sf::Vector2f(50.0f, 50.0f), jogador);
	Entidade::Obstaculo::Plataforma* p1 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(0.0f, 550.0f), sf::Vector2f(300.0f, 50.0f));
	Entidade::Obstaculo::Plataforma* p2 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(300.0f, 550.0f), sf::Vector2f(300.0f, 50.0f));
	Entidade::Obstaculo::Plataforma* p3 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(600.0f, 550.0f), sf::Vector2f(300.0f, 50.0f));

	Entidade::Entidade* e1 = static_cast<Entidade::Entidade*>(jogador);
	Entidade::Entidade* e2 = static_cast<Entidade::Entidade*>(p1);
	Entidade::Entidade* e3 = static_cast<Entidade::Entidade*>(p2);
	Entidade::Entidade* e4 = static_cast<Entidade::Entidade*>(p3);

	listaPersonagem.addEntidade(e1);

	listaObstaculo.addEntidade(e2);
	listaObstaculo.addEntidade(e3);
	listaObstaculo.addEntidade(e4);

	pEvento->setJogador(jogador);
}

void Fantasy::Principal::executar() {
	while (pGrafico->verificaJanelaAberta()) {
		pEvento->executar();
		pGrafico->limpaJanela();

		listaPersonagem.executar();
		listaObstaculo.executar();

		colisor.executar();

		pGrafico->mostraElementos();
	}
}