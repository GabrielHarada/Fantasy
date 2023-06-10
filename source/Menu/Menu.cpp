#include "..\..\header\Menu\Menu.h"

Fantasy::Menu::Menu::Menu(const IDs::IDs ID, const sf::Vector2f tamBotao, const IDs::IDs ID_Fundo) :
    Ente(ID), listaBotao(), it(), tamBotao(tamBotao), tamJanela(pGrafico->getTamJanela()),//, textura()
    posFundo(0.0f, 0.0f), fundo(ID_Fundo)
{
    fundo.addCamada("image/Fase/FlorestaNegra/camada1.png", 0.0f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada2.png", 0.05f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada3.png", 0.1f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada4.png", 0.15f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada5.png", 0.2f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada6.png", 0.4f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada7.png", 0.6f);
}

Fantasy::Menu::Menu::~Menu() {
    if (!listaBotao.empty()) {
        for (it = listaBotao.begin(); it != listaBotao.end(); it++) {
            delete(*it);
            *it = nullptr;
        }
        listaBotao.clear();
    }
}

void Fantasy::Menu::Menu::addBotao(const std::string texto, const sf::Vector2f pos, const IDs::IDs ID){
Botao::Botao* botao = new Botao::Botao(texto, tamBotao, pos, ID);
    if (botao == nullptr) {
        throw("ERROR::Fantasy::Menu::nao foi possivel criar um botao");
    }
    listaBotao.push_back(botao);
}

void Fantasy::Menu::Menu::desenhar() {
    posFundo = sf::Vector2f(posFundo.x + 0.05f, posFundo.y);
    pGrafico->atualizarCamera(sf::Vector2f(posFundo.x + tamJanela.x / 2.0f, posFundo.y + tamJanela.y / 2.0f));
    fundo.executar();
    pGrafico->resetarJanela();
    std::list<Botao::Botao*>::iterator aux;
    for (aux = listaBotao.begin(); aux != listaBotao.end(); aux++) {
        Botao::Botao* botao = *aux;
        botao->desenhar();
        botao = nullptr;
    }
}