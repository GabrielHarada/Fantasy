#pragma once
#include "..\..\header\Entidade\Personagem\Jogador\Jogador.h"
#include "..\..\header\Entidade\Personagem\Personagem.h"
#include <math.h>


Fantasy::Entidade::Personagem::Jogador::Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam):
	Personagem(pos, tam, VELOCIDADE_JOGADOR, IDs::IDs::jogador), noChao(false)
{
	corpo.setFillColor(sf::Color::Green);
	inicializa();
}

void Fantasy::Entidade::Personagem::Jogador::Jogador::inicializa()
{
}

Fantasy::Entidade::Personagem::Jogador::Jogador::~Jogador()
{
}

void Fantasy::Entidade::Personagem::Jogador::Jogador::atualizar()
{
	if (podeAndar) {
		atualizarPosicao();
	}
	relogio.restart();
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
