#include "..\..\header\Estado\EstadoJogar.h"

Fantasy::Estado::EstadoJogar::EstadoJogar(const IDs::IDs ID, Fase::Fase* fase) :
    Estado(ID), fase(fase)
{

}

Fantasy::Estado::EstadoJogar::~EstadoJogar() {
    /*if (fase) {
        delete(fase);
        fase = nullptr;
    }*/
}

Fantasy::Fase::Fase* Fantasy::Estado::EstadoJogar::getFase() {
    return fase;
}

void Fantasy::Estado::EstadoJogar::EstadoJogar::mudarEstadoObservador() {
    fase->getJogador()->mudarEstadoObservador();
}

void Fantasy::Estado::EstadoJogar::executar() {
    fase->executar();
}