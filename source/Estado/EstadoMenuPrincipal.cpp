#include "..\..\header\Estado\EstadoMenuPrincipal.h"

Fantasy::Estado::EstadoMenuPrincipal::EstadoMenuPrincipal() :
    Estado(IDs::IDs::estado_menu_principal), menuPrincipal()
{

}

Fantasy::Estado::EstadoMenuPrincipal::~EstadoMenuPrincipal() {

}

void Fantasy::Estado::EstadoMenuPrincipal::EstadoMenuPrincipal::mudarEstadoObservador() {
    menuPrincipal.mudarEstadoObservador();
}

void Fantasy::Estado::EstadoMenuPrincipal::executar() {
    menuPrincipal.executar();
}