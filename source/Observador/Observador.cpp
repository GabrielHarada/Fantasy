#include "..\..\header\Observador\Observador.h"
#include "..\..\header\Gerenciador\GerenciadorEvento.h"
#include "..\..\header\Gerenciador\GerenciadorEstado.h"

Fantasy::Gerenciador::GerenciadorEvento* Fantasy::Observador::Observador::pEvento = Fantasy::Gerenciador::GerenciadorEvento::getGerenciadorEvento();
Fantasy::Gerenciador::GerenciadorEstado* Fantasy::Observador::Observador::pGEstado = Gerenciador::GerenciadorEstado::getGerenciadorEstado();


Fantasy::Observador::Observador::Observador() :
    ativar(true)
{
    pEvento->addObservador(this);
}

Fantasy::Observador::Observador::~Observador() {
    removerObservador();
}

void Fantasy::Observador::Observador::removerObservador() {
    pEvento->removerObservador(this);
}

void Fantasy::Observador::Observador::mudarEstadoAtivar() {
    ativar = (ativar) ? false : true;
}

const bool Fantasy::Observador::Observador::getAtivar() const {
    return ativar;
}