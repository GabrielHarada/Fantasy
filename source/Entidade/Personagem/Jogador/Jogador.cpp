#pragma once
#include "..\..\header\Entidade\Personagem\Jogador\Jogador.h"
#include "..\..\header\Entidade\Personagem\Personagem.h"
#include <math.h>


Fantasy::Entidade::Personagem::Jogador::Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam):
    Personagem(pos, tam, VELOCIDADE_JOGADOR, IDs::IDs::jogador), noChao(false)
{
    //corpo.setFillColor(sf::Color::Green);
	inicializa();
    //animacao.addAnimacao("image/Jogador/Anda.png", "Anda", 6, 0.5f, sf::Vector2u(2, 2));
}

void Fantasy::Entidade::Personagem::Jogador::Jogador::inicializa() {
    animacao.addAnimacao("image/Jogador/Anda.png", "Anda", 10, 0.12f, sf::Vector2f(6, 2));
    animacao.addAnimacao("image/Jogador/Ataca.png", "Ataca", 10, 0.1f, sf::Vector2f(6, 2));
    animacao.addAnimacao("image/Jogador/Parado.png", "Parado", 10, 0.15f, sf::Vector2f(6, 2));
    animacao.addAnimacao("image/Jogador/Pula.png", "Pula", 3, 0.15f, sf::Vector2f(6, 2));
    animacao.addAnimacao("image/Jogador/Cai.png", "Cai", 3, 0.15f, sf::Vector2f(6, 2));
    animacao.addAnimacao("image/Jogador/Morre.png", "Morre", 10, 0.15f, sf::Vector2f(6, 2));
    animacao.addAnimacao("image/Jogador/tomaDano.png", "TomaDano", 1, 0.15f, sf::Vector2f(6, 2));
    corpo.setOrigin(sf::Vector2f(tam.x / 2.5f, tam.y / 2.0f));
}

Fantasy::Entidade::Personagem::Jogador::Jogador::~Jogador() {
}

void Fantasy::Entidade::Personagem::Jogador::Jogador::atualizar() {
    atualizarPosicao();
    atualizarAnimacao();
    pGrafico->atualizarCamera(pos);
}

void Fantasy::Entidade::Personagem::Jogador::Jogador::colisao(Entidade* outraEntidade, sf::Vector2f ds) {
    switch (outraEntidade->getID()) {
        case (IDs::IDs::esqueleto):
    {
            //std::cout << "Pode bater no inimigo e inimigo pode bater no jogador" << std::endl;
        }
        break;
        case(IDs::IDs::plataforma):
        {

        }
    }
}

void Fantasy::Entidade::Personagem::Jogador::Jogador::pular() {
    if (noChao) {
        velFinal.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
        noChao = false;
    }
}

void Fantasy::Entidade::Personagem::Jogador::Jogador::podePular() {
    noChao = true;
}

void Fantasy::Entidade::Personagem::Jogador::Jogador::atualizarAnimacao() {
    if (!noChao && velFinal.y > 0.0f) {
        animacao.atualizar(paraEsquerda, "Cai");
    }
    else if (!noChao) {
        animacao.atualizar(paraEsquerda, "Pula");
    }
    else if (atacando) {
        animacao.atualizar(paraEsquerda, "Ataca");
    }
    else if (podeAndar) {
        animacao.atualizar(paraEsquerda, "Anda");
    }
    else {
        animacao.atualizar(paraEsquerda, "Parado");
    }
}