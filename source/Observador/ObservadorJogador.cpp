#include "..\..\header\Observador\ObservadorJogador.h"

Fantasy::Observador::ObservadorJogador::ObservadorJogador(Entidade::Personagem::Jogador::Jogador* pJogador) :
    Observador(), pJogador(pJogador)
{

}

Fantasy::Observador::ObservadorJogador::~ObservadorJogador() {

}

void Fantasy::Observador::ObservadorJogador::teclaPressionada(const sf::Keyboard::Key tecla) {
    switch (tecla)
    {
        case (sf::Keyboard::A):
        {
            pJogador->andar(true);
        }
        break;
        case (sf::Keyboard::D):
        {
            pJogador->andar(false);
        }
        break;
        case(sf::Keyboard::W):
        {
            pJogador->pular();
        }
        break;
        case(sf::Keyboard::Space):
        {
            pJogador->atacar(true);
        }
        break;;
    }
}

void Fantasy::Observador::ObservadorJogador::teclaSolta(const sf::Keyboard::Key tecla) {
    switch (tecla)
    {
        case (sf::Keyboard::A):
        {
            pJogador->parar();
        }
        break;
        case(sf::Keyboard::D):
        {
            pJogador->parar();
        }
        break;
    }
}