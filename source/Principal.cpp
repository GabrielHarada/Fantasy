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

	//cria personagens e obstaculos
	Entidade::Personagem::Jogador::Jogador* jogador = new Entidade::Personagem::Jogador::Jogador(sf::Vector2f(500.0f, 50.0f), sf::Vector2f(20.0f, 20.0f));
	Entidade::Personagem::Inimigo::Inimigo* i1 = new Entidade::Personagem::Inimigo::Inimigo(sf::Vector2f(500.0f, 50.0f), sf::Vector2f(20.0f, 20.0f), jogador);
	Entidade::Obstaculo::Plataforma* p1 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(300.0f, 100.0f), sf::Vector2f(400.0f, 20.0f));
	Entidade::Obstaculo::Plataforma* p2 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(0.0f, 225.0f), sf::Vector2f(600.0f, 20.0f));
	Entidade::Obstaculo::Plataforma* p3 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(350.0f, 375.0f), sf::Vector2f(700.0f, 20.0f));
	Entidade::Obstaculo::Plataforma* p4 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(250.0f, 525.0f), sf::Vector2f(400.0f, 20.0f));
	//Entidade::Obstaculo::Plataforma* p5 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(0.0f, 675.0f), sf::Vector2f(900.0f, 20.0f));
	//Entidade::Obstaculo::Plataforma* p6 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(200.0f, 825.0f), sf::Vector2f(1000.0f, 20.0f));
	//Entidade::Obstaculo::Plataforma* p7 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(0.0f, 950.0f), sf::Vector2f(1000.0f, 20.0f));
	Entidade::Obstaculo::Caixa* c1 = new Entidade::Obstaculo::Caixa(sf::Vector2f(330.0f, 895.0f), sf::Vector2f(15.0f, 15.0f));
	//Entidade::Obstaculo::Caixa* c2 = new Entidade::Obstaculo::Caixa(sf::Vector2f(400.0f, 85.0f), sf::Vector2f(15.0f, 15.0f));
	//Entidade::Obstaculo::Caixa* c3 = new Entidade::Obstaculo::Caixa(sf::Vector2f(380.0f, 360.0f), sf::Vector2f(15.0f, 15.0f));


	//transforma eles em entidades
	Entidade::Entidade* e1 = static_cast<Entidade::Entidade*>(jogador);
	Entidade::Entidade* e2 = static_cast<Entidade::Entidade*>(p1);
	Entidade::Entidade* e3 = static_cast<Entidade::Entidade*>(p2);
	Entidade::Entidade* e4 = static_cast<Entidade::Entidade*>(p3);
	Entidade::Entidade* e5 = static_cast<Entidade::Entidade*>(p4);
	//Entidade::Entidade* e7 = static_cast<Entidade::Entidade*>(p5);
	//Entidade::Entidade* e8 = static_cast<Entidade::Entidade*>(p6);
	//Entidade::Entidade* e9 = static_cast<Entidade::Entidade*>(p7);
	Entidade::Entidade* e10 = static_cast<Entidade::Entidade*>(c1);
	//Entidade::Entidade* e11 = static_cast<Entidade::Entidade*>(c2);
	//Entidade::Entidade* e12 = static_cast<Entidade::Entidade*>(c3);

	Entidade::Entidade* e6 = static_cast<Entidade::Entidade*>(i1);

	//adiciona na lista de entidades
	listaPersonagem.addEntidade(e1);
	listaPersonagem.addEntidade(e6);

	listaObstaculo.addEntidade(e2);
	listaObstaculo.addEntidade(e3);
	listaObstaculo.addEntidade(e4);
	listaObstaculo.addEntidade(e5);
	/*listaObstaculo.addEntidade(e7);
	listaObstaculo.addEntidade(e8);
	listaObstaculo.addEntidade(e9);
	listaObstaculo.addEntidade(e10);
	listaObstaculo.addEntidade(e11);
	listaObstaculo.addEntidade(e12);*/

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