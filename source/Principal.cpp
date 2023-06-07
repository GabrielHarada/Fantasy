#pragma once
#include "..\header\Principal.h"

Fantasy::Principal::Principal() :
	listaPersonagem(), listaObstaculo(), pGrafico(pGrafico->getGerenciadorGrafico()),
	pEvento(pEvento->getGerenciadorEvento()),
	colisor(&listaPersonagem, &listaObstaculo),
	fundo() {
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

void Fantasy::Principal::criaPlataforma(const sf::Vector2f pos) {
	Entidade::Obstaculo::Plataforma* p = new Entidade::Obstaculo::Plataforma(pos, sf::Vector2f(300.0f, 50.0f));
	Entidade::Entidade* e = static_cast<Entidade::Entidade*>(p);
	listaObstaculo.addEntidade(e);
}

void Fantasy::Principal::criaCaixa(const sf::Vector2f pos) {
	Entidade::Obstaculo::Caixa* c = new Entidade::Obstaculo::Caixa(pos, sf::Vector2f(50.0f, 50.0f));
	Entidade::Entidade* e = static_cast<Entidade::Entidade*>(c);
	listaObstaculo.addEntidade(e);
}

void Fantasy::Principal::criaInimigo(const sf::Vector2f pos, Entidade::Personagem::Jogador::Jogador* jogador) {
	Entidade::Personagem::Inimigo::Inimigo* i = new Entidade::Personagem::Inimigo::Inimigo(pos, sf::Vector2f(50.0f, 90.0f), jogador);
	Entidade::Entidade* e = static_cast<Entidade::Entidade*>(i);
	listaPersonagem.addEntidade(e);
}

void Fantasy::Principal::instanciaEntidades() {

	Entidade::Personagem::Jogador::Jogador* jogador = new Entidade::Personagem::Jogador::Jogador(sf::Vector2f(100.0f, 400.0f), sf::Vector2f(50.0f, 90.0f));

	Entidade::Entidade* e1 = static_cast<Entidade::Entidade*>(jogador);
	listaPersonagem.addEntidade(e1);

	for (int i = 0; i < 10; i++) {
		criaPlataforma(sf::Vector2f(i * 300.0f, 550.0f));
	}

	for (int i = 0; i < 2; i++) {
		criaInimigo(sf::Vector2f(500.0f * (i + 1), 0.0f), jogador);
	}

	criaPlataforma(sf::Vector2f(500.0f, 400.0f));
	criaPlataforma(sf::Vector2f(900.0f, 400.0f));
	criaPlataforma(sf::Vector2f(1200.0f, 400.0f));
	criaPlataforma(sf::Vector2f(1100.0f, 250.0f));

	criaCaixa(sf::Vector2f(400.0f, 500.0f));
	criaCaixa(sf::Vector2f(1000.0f, 350.0f));

	pEvento->setJogador(jogador);
}

void Fantasy::Principal::executar() {
	while (pGrafico->verificaJanelaAberta()) {
		pEvento->executar();
		pGrafico->limpaJanela();
		//pGrafico->carregarTextura("image/Background.png");

		fundo.executar();

		listaPersonagem.executar();
		listaObstaculo.executar();

		colisor.executar();

		pGrafico->mostraElementos();
	}
}

