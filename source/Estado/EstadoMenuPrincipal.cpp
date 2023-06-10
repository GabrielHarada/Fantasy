#include "..\..\header\Estado\EstadoMenuPrincipal.h"

Fantasy::Estado::EstadoMenuPrincipal::EstadoMenuPrincipal(const IDs::IDs ID) :
    Estado(ID), menuPrincipal()
{

}

Fantasy::Estado::EstadoMenuPrincipal::~EstadoMenuPrincipal() {

}

void Fantasy::Estado::EstadoMenuPrincipal::executar() {
    menuPrincipal.executar();
}