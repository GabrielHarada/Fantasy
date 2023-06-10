#include "..\..\..\header\Menu\Botao\TextoAnimado.h"

Fantasy::Menu::Botao::TextoAnimado::TextoAnimado(const sf::Font fonte, const std::string info) :
    Texto(fonte, info), clareando(true), transparente(255)
{

}

Fantasy::Menu::Botao::TextoAnimado::~TextoAnimado() {

}

void Fantasy::Menu::Botao::TextoAnimado::mudarClareando() {
    clareando = (clareando) ? false : true;
}

const bool Fantasy::Menu::Botao::TextoAnimado::getClareando() const {
    return clareando;
}

const int Fantasy::Menu::Botao::TextoAnimado::getTransparente() const {
    return transparente;
}

void Fantasy::Menu::Botao::TextoAnimado::setTransparente(const int transparente) {
    this->transparente = transparente;
    atualizar();
}

void Fantasy::Menu::Botao::TextoAnimado::resetar() {
    transparente = 255;
    atualizar();
}

void Fantasy::Menu::Botao::TextoAnimado::atualizar() {
    corBorda = sf::Color{ 0, 0, 0, (sf::Uint8)this->transparente };
    corTexto = sf::Color{ corTexto.r, corTexto.g, corTexto.b, (sf::Uint8)this->transparente };
    texto.setOutlineColor(corBorda);
    texto.setFillColor(corTexto);
}