#include "..\..\header\Animador\Animacao.h"
#include "..\..\header\Animador\Imagem.h"

Fantasy::Animador::Animacao::Animacao(sf::RectangleShape* corpo) :
    corpo(corpo), mapImagem(), imgAtual(""), relogio()
{

}

Fantasy::Animador::Animacao::~Animacao() {
    mapImagem.clear();
}

void Fantasy::Animador::Animacao::atualizar(const bool paraEsquerda, std::string imgAtual) {
    //atualizar animacao;
    if (this->imgAtual != imgAtual) {
        this->imgAtual = imgAtual;
    }
    float dt = relogio.getElapsedTime().asSeconds();
    relogio.restart();
    Imagem* img = mapImagem[this->imgAtual];
    sf::Vector2f tamCorpo = corpo->getSize();
    sf::Vector2u aux = img->getEscala();

    img->atualizar(paraEsquerda, dt);
    sf::IntRect tam = img->getTamanho();
    corpo->setTextureRect(img->getTamanho());
    corpo->setTexture(img->getTextura());
    corpo->setScale(aux.x, aux.y);
    corpo->setOrigin(tamCorpo / 2.0f);
}

void Fantasy::Animador::Animacao::addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, int qtdImagem, const float tempoTroca, const sf::Vector2u escala) {
    Imagem* img = new Imagem(caminhoTextura, qtdImagem, tempoTroca, escala);
    mapImagem.insert(std::pair<std::string, Imagem*>(nomeAnimacao, img));
}