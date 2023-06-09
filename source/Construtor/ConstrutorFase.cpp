#include "..\..\header\Construtor\ConstrutorFase.h"


Fantasy::Construtor::ConstrutorFase::ConstrutorFase() {

}

Fantasy::Construtor::ConstrutorFase::~ConstrutorFase() {

}

Fantasy::Entidade::Entidade* Fantasy::Construtor::ConstrutorFase::criarPlataforma(const sf::Vector2f pos) {
    Fantasy::Entidade::Obstaculo::Plataforma* plataforma = new Fantasy::Entidade::Obstaculo::Plataforma(pos);
    if (plataforma == nullptr) {
        std::cout << "Fantasy::Construtor::ConstrutorFase::nao foi possivel criar uma plataforma" << std::endl;
        exit(1);
    }
    return static_cast<Entidade::Entidade*>(plataforma);
}

Fantasy::Entidade::Entidade* Fantasy::Construtor::ConstrutorFase::criarCaixa(const sf::Vector2f pos) {
    Fantasy::Entidade::Obstaculo::Caixa* caixa = new Entidade::Obstaculo::Caixa(pos);
    if (caixa == nullptr) {
        std::cout << "Fantasy::Construtor::ConstrutorFase::nao foi possivel criar uma caixa" << std::endl;
        exit(1);
    }
    return static_cast<Entidade::Entidade*>(caixa);
}

Fantasy::Entidade::Entidade* Fantasy::Construtor::ConstrutorFase::criarJogador(const sf::Vector2f pos) {
    Entidade::Personagem::Jogador::Jogador* jogador = new Entidade::Personagem::Jogador::Jogador(pos);
    if (jogador == nullptr) {
        std::cout << "Fantasy::Construtor::ConstrutorFase::nao foi possivel criar um Jogador" << std::endl;
        exit(1);
    }
    Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    pEvento->setJogador(jogador);
    return static_cast<Entidade::Entidade*>(jogador);
}

Fantasy::Entidade::Entidade* Fantasy::Construtor::ConstrutorFase::criarEsqueleto(const sf::Vector2f pos) {
    Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    Entidade::Personagem::Jogador::Jogador* pJogador = pEvento->getJogador();
    Entidade::Personagem::Inimigo::Esqueleto* esqueleto = new Entidade::Personagem::Inimigo::Esqueleto(pos, pJogador);
    if (esqueleto == nullptr) {
        std::cout << "Fantasy::Construtor::ConstrutorFase::nao foi possivel criar um esqueleto" << std::endl;
        exit(1);
    }
    return static_cast<Entidade::Entidade*>(esqueleto);
}

Fantasy::Entidade::Entidade* Fantasy::Construtor::ConstrutorFase::criarMinotauro(const sf::Vector2f pos) {
    Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    Entidade::Personagem::Jogador::Jogador* pJogador = pEvento->getJogador();
    Entidade::Personagem::Inimigo::Chefao::Minotauro* minotauro = new Entidade::Personagem::Inimigo::Chefao::Minotauro(pos, pJogador);
    if (minotauro == nullptr) {
        std::cout << "Fantasy::Construtor::ConstrutorFase::nao foi possivel criar um minotauro" << std::endl;
        exit(1);
    }
    return static_cast<Entidade::Entidade*>(minotauro);
}

Fantasy::Entidade::Entidade* Fantasy::Construtor::ConstrutorFase::criarCiclope(const sf::Vector2f pos) {
    Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    Entidade::Personagem::Jogador::Jogador* pJogador = pEvento->getJogador();
    Entidade::Personagem::Inimigo::Ciclope* ciclope = new Entidade::Personagem::Inimigo::Ciclope(pos, pJogador);
    if (ciclope == nullptr) {
        std::cout << "Fantasy::Construtor::ConstrutorFase::nao foi possivel criar um ciclope" << std::endl;
        exit(1);
    }
    return static_cast<Entidade::Entidade*>(ciclope);
}
