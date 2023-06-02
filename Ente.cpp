#include "Ente.h"

Jogo::Ente::Ente(const IDs::IDs ID) :
    ID(ID), pGrafico(pGrafico->getGerenciadorGrafico())
{

}

Jogo::Ente::~Ente() {

}

const IDs::IDs Jogo::Ente::getID() const {
    return ID;
}