#include "..\..\header\Fase\FlorestaBranca.h"

Fantasy::Fase::FlorestaBranca::FlorestaBranca() :
    Fase(IDs::IDs::fase_florestaBranca, IDs::IDs::fundo_florestaBranca)
{
}

Fantasy::Fase::FlorestaBranca::~FlorestaBranca() {

}

void Fantasy::Fase::FlorestaBranca::criarFundo() {
    fundo.addCamada("image/Fase/FlorestaBranca/camada1.png", 0.0f);
    fundo.addCamada("image/Fase/FlorestaBranca/camada2.png", 0.1f);
    fundo.addCamada("image/Fase/FlorestaBranca/camada3.png", 0.3f);
    fundo.addCamada("image/Fase/FlorestaBranca/camada4.png", 0.5f);
    fundo.addCamada("image/Fase/FlorestaBranca/camada5.png", 1.0f);
}

void Fantasy::Fase::FlorestaBranca::criarMapa() {
    listaPersonagens.addEntidade(construtorEntidade.criarJogador(sf::Vector2f(100.0f, 400.0f)));

    for (int i = 0; i < 10; i++) {
        listaObstaculos.addEntidade(construtorEntidade.criarPlataforma(sf::Vector2f(i * 300.0f, 550.0f)));
    }

    for (int i = 0; i < 1; i++) {
        listaPersonagens.addEntidade(construtorEntidade.criarEsqueleto(sf::Vector2f(500.0f * (i + 1), 0.0f)));
    }

    listaPersonagens.addEntidade(construtorEntidade.criarCiclope(sf::Vector2f(300.0f * (1), 0.0f)));

    listaObstaculos.addEntidade(construtorEntidade.criarPlataforma(sf::Vector2f(500.0f, 400.0f)));
    listaObstaculos.addEntidade(construtorEntidade.criarPlataforma(sf::Vector2f(900.0f, 400.0f)));
    listaObstaculos.addEntidade(construtorEntidade.criarPlataforma(sf::Vector2f(1200.0f, 400.0f)));
    listaObstaculos.addEntidade(construtorEntidade.criarPlataforma(sf::Vector2f(1100.0f, 250.0f)));
    listaObstaculos.addEntidade(construtorEntidade.criarCaixa(sf::Vector2f(400.0f, 500.0f)));
    listaObstaculos.addEntidade(construtorEntidade.criarCaixa(sf::Vector2f(1000.0f, 350.0f)));
}