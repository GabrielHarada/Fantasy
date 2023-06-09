#pragma once
#include "..\header\Principal.h"

Fantasy::Principal::Principal() :
	pGrafico(pGrafico->getGerenciadorGrafico()),
	pEvento(pEvento->getGerenciadorEvento()),
	pGerenciadorEstado(pGerenciadorEstado->getGerenciadorEstado())
{
	if (pGrafico == nullptr) {
		std::cout << "ERROR::Fantasy::Principal nao foi possivel criar o GerenciadorGrafico" << std::endl;
		exit(1);
	}
	if (pEvento == nullptr) {
		std::cout << "ERROR::Fantasy::Principal nao foi possivel criar um GerenciadorEvento" << std::endl;
		exit(1);
	}
	if (pGerenciadorEstado == nullptr) {
		std::cout << "ERROR::Fantasy::Principal::nao foi possivel criar um GerenciadorEstado" << std::endl;
		exit(1);
	}
	pGerenciadorEstado->addEstado(IDs::IDs::jogar_florestaBranca);
	inicializa();
}

Fantasy::Principal::~Principal() {

}

void Fantasy::Principal::inicializa() {
	pGerenciadorEstado->addEstado(IDs::IDs::jogar_florestaVermelha);
}

void Fantasy::Principal::executar() {
	while (pGrafico->verificaJanelaAberta()) {
		pEvento->executar();

		pGrafico->limpaJanela();

		pGerenciadorEstado->executar();

		pGrafico->mostraElementos();
	}
}

