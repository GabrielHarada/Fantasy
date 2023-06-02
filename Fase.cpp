#include "Fase.h"

Jogo::Fase::Fase::Fase(const IDs::IDs ID_Fase) :
    Ente(ID_Fase), listaPersonagens(), listaObstaculos(),
    pColisao(new Gerenciador::GerenciadorColisao(&listaPersonagens, &listaObstaculos))
{
    if (pColisao == nullptr) {
        std::cout << "Jungle::Fase::nao foi possivel criar um Gerenciador de Colisao" << std::endl;
        exit(1);
    }
}

Jogo::Fase::Fase::~Fase() {
    if (pColisao) {
        delete(pColisao);
        pColisao = nullptr;
    }
    listaObstaculos.limparLista();
    listaPersonagens.limparLista();
}

Jogo::Entidade::Personagem::Jogador::Jogador* Jogo::Fase::Fase::criarJogador(const sf::Vector2f pos) {
    Entidade::Personagem::Jogador::Jogador* jogador = new Entidade::Personagem::Jogador::Jogador(pos, sf::Vector2f(50.0f, 90.0f));
    if (jogador == nullptr) {
        std::cout << "Jungle::Fase::nao foi possivel criar um Jogador" << std::endl;
        exit(1);
    }
    return jogador;
}

Jogo::Entidade::Entidade* Jogo::Fase::Fase::criarPlataforma(const sf::Vector2f pos) {
    Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos, sf::Vector2f(300.0f, 50.0f));
    if (plataforma == nullptr) {
        std::cout << "Jogo::Fase::nao foi possivel criar uma plataforma" << std::endl;
        exit(1);
    }
    return static_cast<Entidade::Entidade*>(plataforma);
}

Jogo::Entidade::Entidade* Jogo::Fase::Fase::criarCaixa(const sf::Vector2f pos) {
    Entidade::Obstaculo::Caixa* caixa = new Entidade::Obstaculo::Caixa(pos, sf::Vector2f(50.0f, 50.0f));
    if (caixa == nullptr) {
        std::cout << "Jogo::Fase::nao foi possivel criar uma caixa" << std::endl;
        exit(1);
    }
    return static_cast<Entidade::Entidade*>(caixa);
}

Jogo::Entidade::Entidade* Jogo::Fase::Fase::criarInimigo(const sf::Vector2f pos, Entidade::Personagem::Jogador::Jogador* jogador) {
    Entidade::Personagem::Inimigo::Inimigo* inimigo = new Entidade::Personagem::Inimigo::Inimigo(pos, sf::Vector2f(50.0f, 90.0f), jogador);
    if (inimigo == nullptr) {
        std::cout << "Jogo::Fase::nao foi possivel criar um inimigo" << std::endl;
        exit(1);
    }
    return static_cast<Entidade::Entidade*>(inimigo);
}

void Jogo::Fase::Fase::desenhar() {
    listaPersonagens.executar();
    listaObstaculos.executar();
}

void Jogo::Fase::Fase::executar() {
    desenhar();
    pColisao->executar();
}