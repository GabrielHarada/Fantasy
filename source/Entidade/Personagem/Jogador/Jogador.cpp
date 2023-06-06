#pragma once
#include "..\..\header\Entidade\Personagem\Jogador\Jogador.h"
#include "..\..\header\Entidade\Personagem\Personagem.h"
#include <math.h>


Fantasy::Entidade::Personagem::Jogador::Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam):
    Personagem(pos, tam, VELOCIDADE_JOGADOR, IDs::IDs::jogador), noChao(false), animacao(&corpo)
{
    //corpo.setFillColor(sf::Color::Green);
	inicializa();
    //animacao.addAnimacao("image/Jogador/Anda.png", "Anda", 6, 0.5f, sf::Vector2u(2, 2));
}

void Fantasy::Entidade::Personagem::Jogador::Jogador::inicializa() {
    animacao.addAnimacao("image/Jogador/Anda.png", "Anda", 10, 0.12f, sf::Vector2u(6, 2));
    animacao.addAnimacao("image/Jogador/Ataca.png", "Ataca", 10, 0.3f, sf::Vector2u(6, 2));
    animacao.addAnimacao("image/Jogador/Parado.png", "Parado", 10, 0.15f, sf::Vector2u(6, 2));
}

Fantasy::Entidade::Personagem::Jogador::Jogador::~Jogador() {
}

void Fantasy::Entidade::Personagem::Jogador::Jogador::atualizar() {
    atualizarPosicao();
    if (podeAndar == false) {
        animacao.atualizar(paraEsquerda, "Parado");
    }
    else {
        animacao.atualizar(paraEsquerda, "Anda");
    }
}

void Fantasy::Entidade::Personagem::Jogador::Jogador::colisao(Entidade* outraEntidade, sf::Vector2f ds) {
    switch (outraEntidade->getID()) {
        case (IDs::IDs::inimigo):
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
