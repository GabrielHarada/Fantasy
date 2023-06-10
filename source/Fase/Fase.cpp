#include "..\..\header\Fase\Fase.h"

Fantasy::Fase::Fase::Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo) :
    Ente(ID_Fase), fundo(ID_Fundo), listaPersonagens(), listaObstaculos(),
    pColisao(new Gerenciador::GerenciadorColisao(&listaPersonagens, &listaObstaculos)),
    construtorEntidade() {
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

void Fantasy::Fase::Fase::criarEntidade(char letra, const sf::Vector2i pos) {
    sf::Vector2f posAux = sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f);
    switch (letra)
    {
        case ('e'):
        {
            listaPersonagens.addEntidade(construtorEntidade.criarEsqueleto(posAux));
        }
        break;
        case('b'):
        {
            listaObstaculos.addEntidade(construtorEntidade.criarCaixa(posAux));
        }
        break;
        case('#'):
        {
            listaObstaculos.addEntidade(construtorEntidade.criarPlataforma(posAux));
        }
        break;
        case('j'): {
            listaPersonagens.addEntidade(construtorEntidade.criarJogador(posAux));
        }
        break;
        case ('c'):
        {
            listaPersonagens.addEntidade(construtorEntidade.criarCiclope(posAux));
        }
        break;
        case('m'): {
            listaPersonagens.addEntidade(construtorEntidade.criarMinotauro(posAux));
        }
        break;
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

Fantasy::Entidade::Personagem::Jogador::Jogador* Fantasy::Fase::Fase::getJogador() {
    for (int i = 0; i < listaPersonagens.getTam(); i++) {
        Entidade::Entidade* ent = listaPersonagens.operator[](i);
        if (ent->getID() == IDs::IDs::jogador) {
            return static_cast<Entidade::Personagem::Jogador::Jogador*>(ent);
        }
    }
    return nullptr;
}