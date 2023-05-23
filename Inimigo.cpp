#include "Inimigo.h"

void Jogo::Personagem::Inimigo::Inimigo::inicializa()
{
	vel = sf::Vector2f(VELOCIDADE_INIMIGO_X, VELOCIDADE_INIMIGO_y);
}

Jogo::Personagem::Inimigo::Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador):
		Personagem(pos, tam), relogio(), jogador(jogador)
{
	corpo.setFillColor(sf::Color::Cyan);
	corpo.setPosition(300.0f, 300.0f);
	inicializa();
	srand(time(NULL));
	moveAleatorio = rand()%4;
}

Jogo::Personagem::Inimigo::Inimigo::~Inimigo()
{
}

void Jogo::Personagem::Inimigo::Inimigo::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
	if (posJogador.x - posInimigo.x > 0.0f) {
		corpo.move(vel.x, 0.0f);
	} else{
		corpo.move(-vel.x, 0.0f);
	}
	if (posJogador.y - posInimigo.y > 0.0f) {
		corpo.move(0.0f, vel.y);
	} else {
		corpo.move(0.0f, -vel.y);
	}
}

void Jogo::Personagem::Inimigo::Inimigo::movimentoAleatorio()
{
	if (moveAleatorio == 0) {
		corpo.move(vel.x, 0.0f);
	} else if (moveAleatorio == 1) {
		corpo.move(-vel.x, 0.0f);
	} else if (moveAleatorio == 2) {
		corpo.move(0.0f, vel.y);
	} else {
		corpo.move(0.0f, -vel.y);
	}

	float dt = relogio.getElapsedTime().asSeconds();
	if (dt >= 1.0f) {
		moveAleatorio = rand() % 4;
		relogio.restart();
	}
}


void Jogo::Personagem::Inimigo::Inimigo::move()
{
	sf::Vector2f posJogador = jogador->getCorpo().getPosition();
	sf::Vector2f posInimigo = corpo.getPosition();

	if (fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X && fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y) {
		persegueJogador(posJogador, posInimigo);
	} else {
		movimentoAleatorio();
	}

}