#include "..\..\header\Gerenciador\GerenciadorEvento.h"

Fantasy::Gerenciador::GerenciadorEvento* Fantasy::Gerenciador::GerenciadorEvento::pEvento = nullptr;

Fantasy::Gerenciador::GerenciadorEvento::GerenciadorEvento() :
    pGrafico(pGrafico->getGerenciadorGrafico())
{

}

Fantasy::Gerenciador::GerenciadorEvento::~GerenciadorEvento() {

}

Fantasy::Gerenciador::GerenciadorEvento* Fantasy::Gerenciador::GerenciadorEvento::getGerenciadorEvento() {
    if (pEvento == nullptr) {
        pEvento = new GerenciadorEvento();
    }
    return pEvento;
}
void Fantasy::Gerenciador::GerenciadorEvento::setJogador(Entidade::Personagem::Jogador::Jogador* pJogador) {
    this->pJogador = pJogador;
}

void Fantasy::Gerenciador::GerenciadorEvento::verificaTeclaPressionada(sf::Keyboard::Key tecla) {
    if (tecla == sf::Keyboard::A) {
        pJogador->andar(true);
    }
    else if (tecla == sf::Keyboard::D) {
        pJogador->andar(false);
    }
    else if (tecla == sf::Keyboard::W) {
        pJogador->pular();
    }
    else if (tecla == sf::Keyboard::Space) {
        pJogador->atacar(true);
    }
    else if (tecla == sf::Keyboard::Escape) {
        pGrafico->fecharJanela();
    }
}

void Fantasy::Gerenciador::GerenciadorEvento::verificaTeclaSolta(sf::Keyboard::Key tecla) {
    if (tecla == sf::Keyboard::A || tecla == sf::Keyboard::D) {
        pJogador->parar();
    }
}

void Fantasy::Gerenciador::GerenciadorEvento::executar() {
    sf::Event evento;
    while (pGrafico->getWindow()->pollEvent(evento)) {
        if (evento.type == sf::Event::KeyPressed) {
            verificaTeclaPressionada(evento.key.code);
        }
        else if (evento.type == sf::Event::KeyReleased) {
            verificaTeclaSolta(evento.key.code);
        }
        else if (evento.type == sf::Event::Closed) {
            pGrafico->fecharJanela();
        }
    }
}