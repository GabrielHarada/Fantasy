#include "..\..\header\Observador\ObservadorFase.h"
#include "..\..\header\Gerenciador\GerenciadorEstado.h"

Fantasy::Observador::ObservadorFase::ObservadorFase(Fase::Fase* fase) :
    Observador(), fase(fase)
{

}

Fantasy::Observador::ObservadorFase::~ObservadorFase() {

}

void Fantasy::Observador::ObservadorFase::teclaPressionada(const sf::Keyboard::Key tecla) {
    //terminar..
}

void Fantasy::Observador::ObservadorFase::teclaSolta(const sf::Keyboard::Key tecla) {
    switch (tecla)
    {
    case (sf::Keyboard::Escape):
    {
        pGEstado->addEstado(IDs::IDs::estado_menu_pausa);
    }
    break;
    }
}