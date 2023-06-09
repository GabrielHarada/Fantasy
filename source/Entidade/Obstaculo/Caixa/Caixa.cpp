#pragma once
#include "..\..\header\Entidade\Obstaculo\Caixa\Caixa.h"

Fantasy::Entidade::Obstaculo::Caixa::Caixa(sf::Vector2f pos) :
    Obstaculo(pos, sf::Vector2f(TAMANHO_CAIXA_X, TAMANHO_CAIXA_Y), IDs::IDs::caixa, CAMINHO_TEXTURA_CAIXA), lentidao(0.25f)
{

}

Fantasy::Entidade::Obstaculo::Caixa::~Caixa() {

}

void Fantasy::Entidade::Obstaculo::Caixa::colisao(Entidade* outraEntidade, sf::Vector2f ds) {
    sf::Vector2f posOutro = outraEntidade->getPos();
    sf::Vector2f tamOutro = outraEntidade->getTam();

    if (outraEntidade->getID() == IDs::IDs::jogador || outraEntidade->getID() == IDs::IDs::esqueleto || outraEntidade->getID() == IDs::IDs::ciclope ||
        outraEntidade->getID() == IDs::IDs::minotauro) {
        colisaoObstaculo(ds, static_cast<Personagem::Personagem*>(outraEntidade));
    }
}

void Fantasy::Entidade::Obstaculo::Caixa::colisaoObstaculo(sf::Vector2f ds, Personagem::Personagem* pPersonagem) {
    sf::Vector2f posOutro = pPersonagem->getPos();
    sf::Vector2f tamOutro = pPersonagem->getTam();
    sf::Vector2f velFinal = pPersonagem->getVelFinal();
    if (ds.x < 0.0f && ds.y < 0.0f) { //houve colisao
        if (ds.x > ds.y) {
            if (pPersonagem->getID() == IDs::IDs::jogador) {
                velFinal.x *= lentidao;
                if (posOutro.x < pos.x) { //colis�o em x
                    pos.x -= ds.x;
                }
                else {
                    pos.x += ds.x;
                }
                setPos(pos);
            }
            else {
                if (posOutro.x < pos.x) { //colis�o em x
                    posOutro.x += ds.x;
                }
                else {
                    posOutro.x -= ds.x;
                }
            }
        }
        else {
            if (posOutro.y < pos.y) { //colis�o em y
                posOutro.y += ds.y;
                if (pPersonagem->getID() == IDs::IDs::jogador) {
                    Personagem::Jogador::Jogador* pJogador = static_cast<Personagem::Jogador::Jogador*>(pPersonagem);
                    pJogador->podePular();
                }
            }
            else {
                posOutro.y -= ds.y;
            }
            velFinal.y = 0.0f;
        }
    }
    pPersonagem->setPos(posOutro);
    pPersonagem->setVelFinal(velFinal);
}