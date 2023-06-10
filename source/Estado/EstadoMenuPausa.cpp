#include "..\..\header\Estado\EstadoMenuPausa.h"
//#include "..\..\include\Estado\EstadoJogar.hpp"
#include "..\..\header\Gerenciador\GerenciadorEstado.h"

Fantasy::Gerenciador::GerenciadorEstado* Fantasy::Estado::EstadoMenuPausa::pGEstado = Gerenciador::GerenciadorEstado::getGerenciadorEstado();

Fantasy::Estado::EstadoMenuPausa::EstadoMenuPausa() :
    Estado(IDs::IDs::estado_menu_pausa), estadoJogar(nullptr), menuPausa()
{
    Estado* estadoAtual = pGEstado->getEstadoAtual();
    if (estadoAtual->getID() != IDs::IDs::jogar_florestaBranca && estadoAtual->getID() != IDs::IDs::jogar_florestaVermelha) {
        std::cout << "ERRO::Estado::EstadoMenuPausa::Estado atual não é uma fase!" << std::endl;
        exit(1);
    }
    estadoJogar = static_cast<EstadoJogar*>(estadoAtual);
    menuPausa.setFase(estadoJogar->getFase());
}

Fantasy::Estado::EstadoMenuPausa::~EstadoMenuPausa() {

}

void Fantasy::Estado::EstadoMenuPausa::mudarEstadoObservador() {
    menuPausa.mudarEstadoObservador();
}

void Fantasy::Estado::EstadoMenuPausa::executar() {
    menuPausa.executar();
}