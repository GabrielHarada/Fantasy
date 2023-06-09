#include "..\..\header\Gerenciador\GerenciadorEstado.h"

Fantasy::Gerenciador::GerenciadorEstado* Fantasy::Gerenciador::GerenciadorEstado::pGerenciadorEstado = nullptr;

Fantasy::Gerenciador::GerenciadorEstado::GerenciadorEstado() :
    pilhaEstados(), construtor()
{

}

Fantasy::Gerenciador::GerenciadorEstado* Fantasy::Gerenciador::GerenciadorEstado::getGerenciadorEstado() {
    if (pGerenciadorEstado == nullptr) {
        pGerenciadorEstado = new GerenciadorEstado();
    }
    return pGerenciadorEstado;
}

Fantasy::Gerenciador::GerenciadorEstado::~GerenciadorEstado() {
    //deleta todos os estados da minha pilha
    while (!pilhaEstados.empty()) {
        delete(pilhaEstados.top());
        pilhaEstados.top() = nullptr;
        pilhaEstados.pop();
    }
    if (pGerenciadorEstado) {
        delete(pGerenciadorEstado);
        pGerenciadorEstado = nullptr;
    }
}

void Fantasy::Gerenciador::GerenciadorEstado::addEstado(const IDs::IDs ID){
    Estado::Estado* estado = nullptr;
    if (ID == IDs::IDs::jogar_florestaBranca || ID == IDs::IDs::jogar_florestaVermelha) {
        estado = construtor.addEstadoJogar(ID);
    }
    pilhaEstados.push(estado);
}

void Fantasy::Gerenciador::GerenciadorEstado::removerEstado() {
    delete(pilhaEstados.top());
    pilhaEstados.top() = nullptr;
    pilhaEstados.pop();

    if (pilhaEstados.empty()) {
        Gerenciador::GerenciadorGrafico::getGerenciadorGrafico()->fecharJanela();
    }
}

void Fantasy::Gerenciador::GerenciadorEstado::executar() {
    //executa o estado que está no topo da minha pilha
    if (!pilhaEstados.empty()) {
        pilhaEstados.top()->executar();
    }
}