#include "..\..\..\header\Menu\Botao\Texto.h"

Fantasy::Menu::Botao::Texto::Texto(const sf::Font fonte, const std::string info, const unsigned int tamFonte) :
    fonte(fonte), texto(), info(info), corTexto(sf::Color::White),
    corBorda(sf::Color::Black), tamFonte(tamFonte)
{
    //this->texto.setString(texto);
    inicializa();
}

Fantasy::Menu::Botao::Texto::~Texto() {

}

void Fantasy::Menu::Botao::Texto::inicializa() {
    texto.setString(info);
    texto.setCharacterSize(tamFonte);
    texto.setFont(fonte);
    texto.setOutlineThickness(5);
    texto.setOutlineColor(corBorda);
    texto.setFillColor(corTexto);
    tam = sf::Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
}

void Fantasy::Menu::Botao::Texto::setCorTexto(const sf::Color corTexto) {
    this->corTexto = corTexto;
    texto.setFillColor(corTexto);
}

const sf::Text Fantasy::Menu::Botao::Texto::getTexto() const {
    return texto;
}

void Fantasy::Menu::Botao::Texto::setPos(const sf::Vector2f pos) {
    texto.setPosition(pos);
}

sf::Vector2f Fantasy::Menu::Botao::Texto::getTam() {
    return tam;
}
