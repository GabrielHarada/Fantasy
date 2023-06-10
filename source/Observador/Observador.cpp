#include "..\..\header\Observador\Observador.h"
#include "..\..\header\Gerenciador\GerenciadorEvento.h"

Fantasy::Gerenciador::GerenciadorEvento* Fantasy::Observador::Observador::pEvento = Fantasy::Gerenciador::GerenciadorEvento::getGerenciadorEvento();

Fantasy::Observador::Observador::Observador() :
    ativar(true)
{
    pEvento->addObservador(this);
}

Fantasy::Observador::Observador::~Observador() {

}

void Fantasy::Observador::Observador::removerObservador() {
    pEvento->removerObservador(this);
}

void Fantasy::Observador::Observador::ativarObservador() {
    ativar = true;
}

void Fantasy::Observador::Observador::desativarObservador() {
    ativar = false;
}

const bool Fantasy::Observador::Observador::getAtivar() const {
    return ativar;
}