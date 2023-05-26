#include "GerenciadorEvento.h"

Jogo::Gerenciador::GerenciadorEvento* Jogo::Gerenciador::GerenciadorEvento::pEvento = nullptr;

Jogo::Gerenciador::GerenciadorEvento::GerenciadorEvento() :
    pGrafico(pGrafico->getGerenciadorGrafico())
{

}

Jogo::Gerenciador::GerenciadorEvento::~GerenciadorEvento() {

}

Jogo::Gerenciador::GerenciadorEvento* Jogo::Gerenciador::GerenciadorEvento::getGerenciadorEvento() {
    if (pEvento == nullptr) {
        pEvento = new GerenciadorEvento();
    }
    return pEvento;
}
void Jogo::Gerenciador::GerenciadorEvento::setJogador(Entidade::Personagem::Jogador::Jogador* pJogador) {
    this->pJogador = pJogador;
}

void Jogo::Gerenciador::GerenciadorEvento::verificaTeclaPressionada(sf::Keyboard::Key tecla) {
    if (tecla == sf::Keyboard::A) {
        pJogador->andar(true);
    }
    else if (tecla == sf::Keyboard::D) {
        pJogador->andar(false);
    }
    else if (tecla == sf::Keyboard::W) {
        pJogador->pular();
    }
    else if (tecla == sf::Keyboard::Escape) {
        pGrafico->fecharJanela();
    }
}

void Jogo::Gerenciador::GerenciadorEvento::verificaTeclaSolta(sf::Keyboard::Key tecla) {
    if (tecla == sf::Keyboard::A || tecla == sf::Keyboard::D) {
        pJogador->parar();
    }
}

void Jogo::Gerenciador::GerenciadorEvento::executar() {
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