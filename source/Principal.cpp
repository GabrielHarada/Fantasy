#pragma once
#include "..\header\Principal.h"

Fantasy::Principal::Principal() :
	pGrafico(pGrafico->getGerenciadorGrafico()),
	pEvento(pEvento->getGerenciadorEvento()),
	maquinaEstado()
{
	if (pGrafico == nullptr) {
		std::cout << "ERROR::Fantasy::Principal nao foi possivel criar o GerenciadorGrafico" << std::endl;
		exit(1);
	}
	if (pEvento == nullptr) {
		std::cout << "ERROR::Fantasy::Principal nao foi possivel criar o GerenciadorEvento" << std::endl;
		exit(1);
	}

	maquinaEstado.addEstado(IDs::IDs::jogar_florestaBranca);
	executar();
}

Fantasy::Principal::~Principal() {

}

void Fantasy::Principal::executar() {
	while (pGrafico->verificaJanelaAberta()) {
		pEvento->executar();

		pGrafico->limpaJanela();

		maquinaEstado.executar();

		pGrafico->mostraElementos();
	}
}

