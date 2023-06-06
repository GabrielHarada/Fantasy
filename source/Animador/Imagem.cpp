#include "..\..\header\Animador\Imagem.h"

Fantasy::Animador::Imagem::Imagem(const char* caminhoTextura, const unsigned int qtdImagem, const float tempoTroca, const sf::Vector2u escala) :
    pGrafico(pGrafico->getGerenciadorGrafico()), qtdImagem(qtdImagem), tempoTroca(tempoTroca),
    tempoTotal(0.0f), tamanho(0, 0, 0, 0), imgAtual(0), textura(pGrafico->carregarTextura(caminhoTextura)),
    escala(escala)
{
    tamanho.width = textura.getSize().x / (float)qtdImagem;
    tamanho.height = textura.getSize().y;
}

Fantasy::Animador::Imagem::~Imagem() {

}

void Fantasy::Animador::Imagem::atualizar(const bool paraEsquerda, const float dt) {
    tempoTotal = tempoTotal + dt;
    if (tempoTotal >= tempoTroca) {
        tempoTotal -= tempoTroca;
        imgAtual++;
        if (imgAtual >= qtdImagem) {
            imgAtual = 0;
        }
    }
    if (paraEsquerda) {
        tamanho.left = (imgAtual + 1) * abs(tamanho.width);
        tamanho.width = -abs(tamanho.width);
    }
    else {
        tamanho.left = imgAtual * tamanho.width;
        tamanho.width = abs(tamanho.width);
    }
}

const sf::IntRect Fantasy::Animador::Imagem::getTamanho() const {
    return tamanho;
}

const sf::Texture* Fantasy::Animador::Imagem::getTextura() const {
    return &textura;
}

const sf::Vector2u Fantasy::Animador::Imagem::getEscala() const {
    return escala;
}