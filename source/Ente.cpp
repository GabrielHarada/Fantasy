#include "..\header\Ente.h"

Fantasy::Ente::Ente(const IDs::IDs ID) :
    ID(ID), pGrafico(pGrafico->getGerenciadorGrafico())
{

}

Fantasy::Ente::~Ente() {

}

const IDs::IDs Fantasy::Ente::getID() const {
    return ID;
}