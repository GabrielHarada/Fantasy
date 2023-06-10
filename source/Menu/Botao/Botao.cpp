#include "..\..\..\header\Menu\Botao\Botao.h"

Fantasy::Menu::Botao::Botao::Botao(const std::string info, const sf::Vector2f tam, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado) :
    Ente(ID), texto(pGrafico->carregarFonte(CAMINHO_FONTE), info),
    selecionado(false), pos(pos), tam(tam), relogio(),
    tempoTrocaCor(TEMPO_TROCAR_COR), tempo(0.0f), corSelecionado(corSelecionado)
{
    caixaTexto.setPosition(pos);
    caixaTexto.setSize(tam);
    sf::Vector2f tamTexto = this->texto.getTam();
    sf::Vector2f posTexto = sf::Vector2f(
        pos.x + tam.x / 2.0f - tamTexto.x / 2.05f,
        pos.y + tam.y / 2.0f - tamTexto.y * 1.2f
    );
    this->texto.setPos(posTexto);
    caixaTexto.setFillColor(sf::Color::Transparent);
}

Fantasy::Menu::Botao::Botao::~Botao() {

}

void Fantasy::Menu::Botao::Botao::desenhar() {
    atualizarTexto();
    //pGrafico->desenhaElemento(caixaTexto);
    pGrafico->desenhaElemento(texto.getTexto());
}

void Fantasy::Menu::Botao::Botao::setSelecionado(const bool selecionado) {
    if (selecionado) {
        texto.setCorTexto(corSelecionado);
    }
    else {
        texto.setCorTexto(sf::Color::White);
    }
    this->selecionado = selecionado;
    texto.resetar();
}

void Fantasy::Menu::Botao::Botao::atualizarTexto() {
    const float dt = relogio.getElapsedTime().asSeconds();
    relogio.restart();
    tempo += dt;
    if (selecionado) {
        if (tempo > tempoTrocaCor) {
            int transparente = texto.getTransparente();
            if (texto.getClareando()) {
                //texto clareando
                transparente += 5;
                if (transparente > 255) {
                    transparente = 255;
                    texto.mudarClareando();
                }
            }
            else {
                //texto escurecendo
                transparente -= 5;
                if (transparente < 0) {
                    transparente = 0;
                    texto.mudarClareando();
                }
            }
            texto.setTransparente(transparente);
            tempo = 0.0f;
        }
    }
    else {
        tempo = 0.0f;
    }
}

const bool Fantasy::Menu::Botao::Botao::getSelecionado() const {
    return selecionado;
}

void Fantasy::Menu::Botao::Botao::atualizarPosicao(const sf::Vector2f pos) {
    this->pos = pos;
    caixaTexto.setPosition(pos);
    sf::Vector2f tamTexto = this->texto.getTam();
    sf::Vector2f posTexto = sf::Vector2f(
        pos.x + tam.x / 2.0f - tamTexto.x / 2.05f,
        pos.y + tam.y / 2.0f - tamTexto.y * 1.2f
    );
    this->texto.setPos(posTexto);
}


const sf::Vector2f Fantasy::Menu::Botao::Botao::getPos() const {
    return caixaTexto.getPosition();
}

const sf::Vector2f Fantasy::Menu::Botao::Botao::getTamTexto() const {
    return sf::Vector2f(texto.getTexto().getGlobalBounds().width, texto.getTexto().getGlobalBounds().height);
}