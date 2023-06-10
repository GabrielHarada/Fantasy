#include "..\..\header\Estado\Estado.h"

Fantasy::Estado::Estado::Estado(const IDs::IDs ID) :
    Ente(ID), remover(false)
{

}

Fantasy::Estado::Estado::~Estado() {

}

void Fantasy::Estado::Estado::desenhar() {

}

void Fantasy::Estado::Estado::setRemover(const bool remover) {
    this->remover = remover;
}

const bool Fantasy::Estado::Estado::getRemover() const {
    return remover;
}