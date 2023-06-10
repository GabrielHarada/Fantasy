#include "..\..\header\Gerenciador\GerenciadorEvento.h"
#include "..\..\header\Gerenciador\GerenciadorEstado.h"

Fantasy::Gerenciador::GerenciadorEvento* Fantasy::Gerenciador::GerenciadorEvento::pEvento = nullptr;
Fantasy::Gerenciador::GerenciadorGrafico* Fantasy::Gerenciador::GerenciadorEvento::pGrafico = GerenciadorGrafico::getGerenciadorGrafico();
Fantasy::Gerenciador::GerenciadorEstado* Fantasy::Gerenciador::GerenciadorEvento::pGEstado = GerenciadorEstado::getGerenciadorEstado();
Fantasy::Lista::ListaObservador* Fantasy::Gerenciador::GerenciadorEvento::listaObservador = nullptr;

Fantasy::Gerenciador::GerenciadorEvento::GerenciadorEvento()
{
    listaObservador = new Lista::ListaObservador();
    if (listaObservador == nullptr) {
        std::cout << "ERROR::Fantasy::Gerenciador::GerenciadorEvento::nao foi possivel criar uma Lista de Observadores" << std::endl;
        exit(1);
    }
}

Fantasy::Gerenciador::GerenciadorEvento::~GerenciadorEvento() {
    if (listaObservador) {
        delete(listaObservador);
        listaObservador = nullptr;
    }
}

Fantasy::Gerenciador::GerenciadorEvento* Fantasy::Gerenciador::GerenciadorEvento::getGerenciadorEvento() {
    if (pEvento == nullptr) {
        pEvento = new GerenciadorEvento();
    }
    return pEvento;
}

void Fantasy::Gerenciador::GerenciadorEvento::addObservador(Observador::Observador* observador) {
    listaObservador->addObservador(observador);
}

void Fantasy::Gerenciador::GerenciadorEvento::removerObservador(Observador::Observador* observador) {
    listaObservador->removerObservador(observador);
}

void Fantasy::Gerenciador::GerenciadorEvento::removerObservador(int pos) {
    listaObservador->removerObservador(pos);
}

void Fantasy::Gerenciador::GerenciadorEvento::executar() {
    sf::Event evento;
    while (pGrafico->getWindow()->pollEvent(evento)) {
        if (evento.type == sf::Event::KeyPressed) {
            if (evento.key.code == sf::Keyboard::P) {
                pGEstado->addEstado(IDs::IDs::jogar_florestaBranca);
            }
            else if (evento.key.code == sf::Keyboard::Escape) {
                pGEstado->removerEstado();
            }
            else {
                listaObservador->notificarTeclaPressionada(evento.key.code);
            }
        }
        else if (evento.type == sf::Event::KeyReleased) {
            listaObservador->notificarTeclaSolta(evento.key.code);
        }
        else if (evento.type == sf::Event::Closed) {
            pGrafico->fecharJanela();
        }
    }
}