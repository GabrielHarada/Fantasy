#include "..\..\header\Construtor\ConstrutorEntidade.h"
#include "..\..\header\Fase\Fase.h"

Fantasy::Construtor::ConstrutorEntidade::ConstrutorEntidade(Entidade::Personagem::Jogador::Jogador* pJogador) :
    pJogador(pJogador)
{

}

Fantasy::Construtor::ConstrutorEntidade::ConstrutorEntidade() :
    pJogador(nullptr)
{

}

Fantasy::Construtor::ConstrutorEntidade::~ConstrutorEntidade() {

}

void Fantasy::Construtor::ConstrutorEntidade::verificaJogador() {
    if (pJogador == nullptr) {
        throw "ERROR::Fantasy::Construtor::ConctrutorEntidade::pJogador eh nullptr";
    }
}

Fantasy::Entidade::Entidade* Fantasy::Construtor::ConstrutorEntidade::criarPlataforma(const sf::Vector2f pos) {
    Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos);
    if (plataforma == nullptr) {
        std::cout << "Fantasy::Construtor::ConstrutorFase::nao foi possivel criar uma plataforma" << std::endl;
        exit(1);
    }
    return static_cast<Entidade::Entidade*>(plataforma);
}

Fantasy::Entidade::Entidade* Fantasy::Construtor::ConstrutorEntidade::criarCaixa(const sf::Vector2f pos) {
    Entidade::Obstaculo::Caixa* caixa = new Entidade::Obstaculo::Caixa(pos);
    if (caixa == nullptr) {
        std::cout << "Fantasy::Construtor::ConstrutorFase::nao foi possivel criar uma caixa" << std::endl;
        exit(1);
    }
    return static_cast<Entidade::Entidade*>(caixa);
}

Fantasy::Entidade::Entidade* Fantasy::Construtor::ConstrutorEntidade::criarEsqueleto(const sf::Vector2f pos) {
    verificaJogador();
    Entidade::Personagem::Inimigo::Esqueleto* esqueleto = new Entidade::Personagem::Inimigo::Esqueleto(pos, pJogador);
    if (esqueleto == nullptr) {
        std::cout << "Fantasy::Construtor::ConstrutorFase::nao foi possivel criar um esqueleto" << std::endl;
        exit(1);
    }
    return static_cast<Entidade::Entidade*>(esqueleto);
}

Fantasy::Entidade::Entidade* Fantasy::Construtor::ConstrutorEntidade::criarCiclope(const sf::Vector2f pos) {
    verificaJogador();
    Entidade::Personagem::Inimigo::Ciclope* ciclope = new Entidade::Personagem::Inimigo::Ciclope(pos, pJogador);
    if (ciclope == nullptr) {
        std::cout << "Fantasy::Construtor::ConstrutorFase::nao foi possivel criar um ciclope" << std::endl;
        exit(1);
    }
    return static_cast<Entidade::Entidade*>(ciclope);
}

Fantasy::Entidade::Entidade* Fantasy::Construtor::ConstrutorEntidade::criarMinotauro(const sf::Vector2f pos) {
    verificaJogador();
    Entidade::Personagem::Inimigo::Chefao::Minotauro* minotauro = new Entidade::Personagem::Inimigo::Chefao::Minotauro(pos, pJogador);
    if (minotauro == nullptr) {
        std::cout << "Fantasy::Construtor::ConstrutorFase::nao foi possivel criar um minotauro" << std::endl;
        exit(1);
    }
    return static_cast<Entidade::Entidade*>(minotauro);
}

Fantasy::Entidade::Entidade* Fantasy::Construtor::ConstrutorEntidade::criarJogador(const sf::Vector2f pos) {
    Entidade::Personagem::Jogador::Jogador* jogador = new Entidade::Personagem::Jogador::Jogador(pos);
    if (jogador == nullptr) {
        std::cout << "Fantasy::Construtor::ConstrutorFase::nao foi possivel criar um Jogador" << std::endl;
        exit(1);
    }
    if (pJogador == nullptr) {
        pJogador = jogador;
    }
    return static_cast<Entidade::Entidade*>(jogador);
}