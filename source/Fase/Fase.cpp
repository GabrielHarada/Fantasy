#include "..\..\header\Fase\Fase.h"

Fantasy::Fase::Fase::Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo) :
    Ente(ID_Fase), fundo(ID_Fundo), listaPersonagens(), listaObstaculos(),
    pColisao(new Gerenciador::GerenciadorColisao(&listaPersonagens, &listaObstaculos))
{
    if (pColisao == nullptr) {
        std::cout << "Fantasy::Fase::nao foi possivel criar um Gerenciador de Colisao" << std::endl;
        exit(1);
    }
}

Fantasy::Fase::Fase::~Fase() {
    if (pColisao) {
        delete(pColisao);
        pColisao = nullptr;
    }
    listaObstaculos.limparLista();
    listaPersonagens.limparLista();
}

void Fantasy::Fase::Fase::criarPlataforma(const sf::Vector2f pos) {
    Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos, sf::Vector2f(300.0f, 50.0f));
    if (plataforma == nullptr) {
        std::cout << "Fantasy::Fase::nao foi possivel criar uma plataforma" << std::endl;
        exit(1);
    }
    listaObstaculos.addEntidade(static_cast<Entidade::Entidade*>(plataforma));
}

void Fantasy::Fase::Fase::criarCaixa(const sf::Vector2f pos) {
    Entidade::Obstaculo::Caixa* caixa = new Entidade::Obstaculo::Caixa(pos, sf::Vector2f(50.0f, 50.0f));
    if (caixa == nullptr) {
        std::cout << "Fantasy::Fase::nao foi possivel criar uma caixa" << std::endl;
        exit(1);
    }
    listaObstaculos.addEntidade(static_cast<Entidade::Entidade*>(caixa));
}

void Fantasy::Fase::Fase::criarEsqueleto(const sf::Vector2f pos) {
    Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    Entidade::Personagem::Jogador::Jogador* pJogador = pEvento->getJogador();
    Entidade::Personagem::Inimigo::Ciclope* ciclope = new Entidade::Personagem::Inimigo::Ciclope(pos, sf::Vector2f(50.0f, 90.0f), pJogador);
    if (ciclope == nullptr) {
        std::cout << "Fantasy::Fase::nao foi possivel criar um ciclope" << std::endl;
        exit(1);
    }
    listaPersonagens.addEntidade(static_cast<Entidade::Entidade*>(ciclope));
}

void Fantasy::Fase::Fase::criarCiclope(const sf::Vector2f pos) {
    Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    Entidade::Personagem::Jogador::Jogador* pJogador = pEvento->getJogador();
    Entidade::Personagem::Inimigo::Esqueleto* esqueleto = new Entidade::Personagem::Inimigo::Esqueleto(pos, sf::Vector2f(50.0f, 90.0f), pJogador);
    if (esqueleto == nullptr) {
        std::cout << "Fantasy::Fase::nao foi possivel criar um esqueleto" << std::endl;
        exit(1);
    }
    listaPersonagens.addEntidade(static_cast<Entidade::Entidade*>(esqueleto));
}

void Fantasy::Fase::Fase::criarJogador(const sf::Vector2f pos) {
    Entidade::Personagem::Jogador::Jogador* jogador = new Entidade::Personagem::Jogador::Jogador(pos, sf::Vector2f(50.0f, 90.0f));
    if (jogador == nullptr) {
        std::cout << "Fantasy::Fase::nao foi possivel criar um Jogador" << std::endl;
        exit(1);
    }
    Gerenciador::GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    pEvento->setJogador(jogador);
    listaPersonagens.addEntidade(static_cast<Entidade::Entidade*>(jogador));
}

void Fantasy::Fase::Fase::criarEntidade(char letra, const sf::Vector2i pos) {
    switch (letra)
    {
        case ('i'):
        {
            criarEsqueleto(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
        }
        break;
        case('c'):
        {
            criarCaixa(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
        }
        break;
        case('#'):
        {
            criarPlataforma(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
        }
        break;
        case('j'): {
            criarJogador(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
        }
    }
}

void Fantasy::Fase::Fase::desenhar() {
    listaPersonagens.executar();
    listaObstaculos.executar();
}

void Fantasy::Fase::Fase::executar() {
    fundo.executar();
    desenhar();
    pColisao->executar();
}