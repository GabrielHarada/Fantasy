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

Fantasy::Entidade::Personagem::Jogador::Jogador* Fantasy::Estado::EstadoJogar::EstadoJogar::getJogador() {
    return fase->getJogador();
}

void Fantasy::Estado::EstadoJogar::executar() {
    fase->executar();
}