#include "..\..\header\Lista\ListaObservador.h"

Fantasy::Lista::ListaObservador::ListaObservador() :
    objListaObservador()
{

}

Fantasy::Lista::ListaObservador::~ListaObservador() {
    objListaObservador.limparLista();
}

void Fantasy::Lista::ListaObservador::addObservador(Observador::Observador* observador) {
    objListaObservador.addElemento(observador);
}

void Fantasy::Lista::ListaObservador::removerObservador(Observador::Observador* observador) {
    objListaObservador.removerElemento(observador);
}

void Fantasy::Lista::ListaObservador::removerObservador(int pos) {
    objListaObservador.removerElemento(pos);
}

int Fantasy::Lista::ListaObservador::getTam() {
    return objListaObservador.getTam();
}

Fantasy::Observador::Observador* Fantasy::Lista::ListaObservador::operator[](int pos) {
    return objListaObservador.operator[](pos);
}

void Fantasy::Lista::ListaObservador::notificarTeclaPressionada(const sf::Keyboard::Key tecla) {
    for (int i = 0; i < objListaObservador.getTam(); i++) {
        Observador::Observador* observador = objListaObservador.operator[](i);
        if (observador->getAtivar()) {
            observador->teclaPressionada(tecla);
        }        
        observador = nullptr;
    }
}

void Fantasy::Lista::ListaObservador::notificarTeclaSolta(const sf::Keyboard::Key tecla) {
    for (int i = 0; i < objListaObservador.getTam(); i++) {
        Observador::Observador* observador = objListaObservador.operator[](i);
        if (observador->getAtivar()) {
            observador->teclaSolta(tecla);
        }
        observador = nullptr;
    }
}