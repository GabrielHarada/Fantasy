#include "..\..\header\Estado\EstadoMenuOpcaoPrincipal.h"

Fantasy::Estado::EstadoMenuOpcaoPrincipal::EstadoMenuOpcaoPrincipal() :
    Estado(IDs::IDs::estado_menu_opcaoPrincipal), menuOpcaoPrincipal()
{

}

Fantasy::Estado::EstadoMenuOpcaoPrincipal::~EstadoMenuOpcaoPrincipal() {

}

void Fantasy::Estado::EstadoMenuOpcaoPrincipal::mudarEstadoObservador() {
    //menuOpcaoPrincipal.mudarEstadoObservador();
}

void Fantasy::Estado::EstadoMenuOpcaoPrincipal::executar() {
    menuOpcaoPrincipal.executar();
}