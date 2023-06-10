#include "..\header\Ente.h"

Fantasy::Gerenciador::GerenciadorGrafico* Fantasy::Ente::pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

Fantasy::Ente::Ente(const IDs::IDs ID) :
    ID(ID)
{

}

Fantasy::Ente::~Ente() {

}

const IDs::IDs Fantasy::Ente::getID() const {
    return ID;
}