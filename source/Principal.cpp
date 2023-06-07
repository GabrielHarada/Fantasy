#pragma once
#include "..\header\Principal.h"

Fantasy::Principal::Principal() :
	pGrafico(pGrafico->getGerenciadorGrafico()),
	pEvento(pEvento->getGerenciadorEvento()),
	fase(nullptr)
{
	if (pGrafico == nullptr) {
		std::cout << "ERROR::Fantasy::Principal nao foi possivel criar o GerenciadorGrafico" << std::endl;
		exit(1);
	}
	if (pEvento == nullptr) {
		std::cout << "ERROR::Fantasy::Principal nao foi possivel criar o GerenciadorEvento" << std::endl;
		exit(1);
	}

	//inicializa();
	criarFase();
	executar();
}

Fantasy::Principal::~Principal() {
	if (fase) {
		delete(fase);
		fase = nullptr;
	}
}

void Fantasy::Principal::criarFase() {
	Fase::FlorestaBranca* aux = new Fase::FlorestaBranca();
	//Fase::FlorestaVermelha* aux = new Fase::FlorestaVermelha();
	if (aux == nullptr) {
		std::cout << "Fantasy::Principal::nao foi possivel criar fase" << std::endl;
		exit(1);
	}
	fase = static_cast<Fase::Fase*>(aux);
	fase->criarFundo();
	fase->criarMapa();
}

void Fantasy::Principal::executar() {
	while (pGrafico->verificaJanelaAberta()) {
		pEvento->executar();

		pGrafico->limpaJanela();

		fase->executar();

		pGrafico->mostraElementos();
	}
}

