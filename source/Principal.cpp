#pragma once
#include "..\header\Principal.h"

Fantasy::Gerenciador::GerenciadorGrafico* Fantasy::Principal::pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
Fantasy::Gerenciador::GerenciadorEstado* Fantasy::Principal::pGerenciadorEstado = Gerenciador::GerenciadorEstado::getGerenciadorEstado();
Fantasy::Gerenciador::GerenciadorEvento* Fantasy::Principal::pEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();

Fantasy::Principal::Principal()
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
	inicializa();
}

Fantasy::Principal::~Principal() {

}

void Fantasy::Principal::inicializa() {
	pGerenciadorEstado->addEstado(IDs::IDs::estado_menu_principal);
}

void Fantasy::Principal::executar() {
	while (pGrafico->verificaJanelaAberta()) {
		pEvento->executar();

		pGrafico->limpaJanela();

		pGerenciadorEstado->executar();

		pGrafico->mostraElementos();
	}
}

