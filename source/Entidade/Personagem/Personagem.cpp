#include "..\..\header\Entidade\Personagem\Personagem.h"

Fantasy::Entidade::Personagem::Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID) :
	Entidade(pos, tam, ID), podeAndar(false), paraEsquerda(false), relogio(),
    dt(0.0f), velFinal(sf::Vector2f(vel, 0.0f)), velMax(vel), atacando(false),
    animacao(&corpo)
{
	corpo.setPosition(pos);
}

Fantasy::Entidade::Personagem::Personagem::~Personagem()
{
}

void Fantasy::Entidade::Personagem::Personagem::andar(const bool paraEsquerda)
{
    atacando = false;
	podeAndar = true;
	this->paraEsquerda = paraEsquerda;
}

void Fantasy::Entidade::Personagem::Personagem::parar()
{
	podeAndar = false;
}

void Fantasy::Entidade::Personagem::Personagem::atacar(const bool atacando) {
    podeAndar = false;
    this->atacando = atacando;
}


void Fantasy::Entidade::Personagem::Personagem::atualizarPosicao() {
    dt = relogio.getElapsedTime().asSeconds();
    relogio.restart();
    sf::Vector2f ds(0.0f, 0.0f);

    //move na horizontal
    if (podeAndar) {
        ds.x = velFinal.x * dt;
        if (paraEsquerda) {
            ds.x *= -1;
        }
    }

    //sofre o efeito da gravidade
    velFinal.y += GRAVIDADE * dt;
    ds.y = velFinal.y * GRAVIDADE;

    //atualiza posi��o
    setPos(sf::Vector2f(pos.x + ds.x, pos.y + ds.y));

    //atualiza velocidade na horizontal
    velFinal.x = velMax;

    desenhar();
}

void Fantasy::Entidade::Personagem::Personagem::setVelFinal(sf::Vector2f velFinal) {
    this->velFinal = velFinal;
}

const sf::Vector2f Fantasy::Entidade::Personagem::Personagem::getVelFinal() const {
    return velFinal;
}

void Fantasy::Entidade::Personagem::Personagem::atualizarAnimacao() {
    if (podeAndar) {
        animacao.atualizar(paraEsquerda, "Anda");
    }
    else {
        animacao.atualizar(paraEsquerda, "Parado");
    }
}