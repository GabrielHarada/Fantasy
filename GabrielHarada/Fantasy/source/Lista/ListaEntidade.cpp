#include "..\..\header\Lista\ListaEntidade.h"

Fantasy::Lista::ListaEntidade::ListaEntidade() :
    objListaEntidade()
{

}

Fantasy::Lista::ListaEntidade::~ListaEntidade() {

}

void Fantasy::Lista::ListaEntidade::addEntidade(Entidade::Entidade* entidade) {
    objListaEntidade.addElemento(entidade);
}

void Fantasy::Lista::ListaEntidade::removerEntidade(Entidade::Entidade* entidade) {
    objListaEntidade.removerElemento(entidade);
}

void Fantasy::Lista::ListaEntidade::removerEntidade(int pos) {
    objListaEntidade.removerElemento(pos);
}

int Fantasy::Lista::ListaEntidade::getTam() {
    return objListaEntidade.getTam();
}

Fantasy::Entidade::Entidade* Fantasy::Lista::ListaEntidade::operator[](int pos) {
    return objListaEntidade.operator[](pos);
}

void Fantasy::Lista::ListaEntidade::executar() {
    int tam = objListaEntidade.getTam();
    Entidade::Entidade* aux = nullptr;
    for (int i = 0; i < tam; i++) {
        aux = objListaEntidade.operator[](i);
        aux->atualizar();
    }
}

void Fantasy::Lista::ListaEntidade::limparLista() {
    objListaEntidade.limparLista();
}