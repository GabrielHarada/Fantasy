#include "..\..\header\Entidade\Personagem\Inimigo\Inimigo.h"

Fantasy::Entidade::Personagem::Inimigo::Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* jogador, const IDs::IDs ID) :
	Personagem(pos, tam, VELOCIDADE_INIMIGO, ID), jogador(jogador), dtAux(0.0f)
{
	srand(time(NULL));
	moveAleatorio = rand() % 3;
	if (moveAleatorio == 0) {
		parar();
	}
	else if (moveAleatorio == 1) {
		andar(true);
	}
	else {
		andar(false);
	}
}

Fantasy::Entidade::Personagem::Inimigo::Inimigo::~Inimigo()
{
}

void Fantasy::Entidade::Personagem::Inimigo::Inimigo::atualizaMovimentoAleatorio()
{
	if (dtAux > 1.0f) {
		moveAleatorio = rand() % 3;
		if (moveAleatorio == 0) {
			parar();
		}
		else if (moveAleatorio == 1) {
			andar(true);
		}
		else {
			andar(false);
		}
		dtAux = 0.0f;
	}
}

void Fantasy::Entidade::Personagem::Inimigo::Inimigo::moveInimigo() {
	sf::Vector2f posJogador = jogador->getPos();
	sf::Vector2f posInimigo = getPos();
	if (fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X && fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y) {
		if (posJogador.x - posInimigo.x > 0.0f) {
			andar(false);
		}
		else {
			andar(true);
		}
	}
	else {
		atualizaMovimentoAleatorio();
	}
}
void Fantasy::Entidade::Personagem::Inimigo::Inimigo::atualizar() {
	moveInimigo();
	atualizarPosicao();
	dtAux += relogio.getElapsedTime().asSeconds() * 100;
	relogio.restart();
	atualizarAnimacao();
}

void Fantasy::Entidade::Personagem::Inimigo::Inimigo::colisao(Entidade* outraEntidade, sf::Vector2f ds) {
	switch (outraEntidade->getID()) {
	case (IDs::IDs::jogador):
	{
		//std::cout << "Bate jogador e jogador pode bater no inimigo" << std::endl;
	}
	break;
	case (IDs::IDs::minotauro):
	{
		//std::cout << "Empurra inimigo" << std::endl;
	}
	break;
	case(IDs::IDs::esqueleto):
	{

	}
	break;
	}
}