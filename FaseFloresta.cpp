#include "FaseFloresta.h"

Jogo::Fase::FaseFloresta::FaseFloresta() :
    Fase(IDs::IDs::faseFloresta)
{
}

Jogo::Fase::FaseFloresta::~FaseFloresta() {

}

void Jogo::Fase::FaseFloresta::criarEntidades() {
    Entidade::Personagem::Jogador::Jogador* jogador = criarJogador(sf::Vector2f(100.0f, 400.0f));
    Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    pEvento->setJogador(jogador);
    listaPersonagens.addEntidade(static_cast<Entidade::Entidade*>(jogador));

    /*
    for (int i = 0; i < 10; i++) {
        listaObstaculos.addEntidade(criarPlataforma(sf::Vector2f((i - 2) * 300.0f, 550.0f)));
    }

    for (int i = 0; i < 4; i++) {
        listaPersonagens.addEntidade(criarInimigo(sf::Vector2f(500.0f * (i + 1), 0.0f), jogador));
    }


    listaObstaculos.addEntidade(criarPlataforma(sf::Vector2f(200.0f, 400.0f)));
    listaObstaculos.addEntidade(criarPlataforma(sf::Vector2f(500.0f, 400.0f)));
    listaObstaculos.addEntidade(criarPlataforma(sf::Vector2f(600.0f, 250.0f)));
    listaObstaculos.addEntidade(criarCaixa(sf::Vector2f(0.0f, 500.0f)));
    listaObstaculos.addEntidade(criarCaixa(sf::Vector2f(300.0f, 350.0f)));
    */
}