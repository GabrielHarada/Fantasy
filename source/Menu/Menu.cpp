#include "..\..\header\Menu\Menu.h"

Fantasy::Menu::Menu::Menu(const IDs::IDs ID, const sf::Vector2f tamBotao, const std::string nome, const unsigned int tamFonte) :
    Ente(ID), listaBotao(), it(), tamBotao(tamBotao), tamJanela(pGrafico->getTamJanela()), posFundo(sf::Vector2f(0.0f, 0.0f)),
    nomeMenu(pGrafico->carregarFonte("image/fonte/menu.ttf"), nome, tamFonte) 
{

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

void Fantasy::Menu::Menu::addBotao(const std::string info, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado) {
    Botao::Botao* botao = new Botao::Botao(info, tamBotao, pos, ID, corSelecionado);
    if (botao == nullptr) {
        throw("ERROR::Fantasy::Menu::nao foi possivel criar um botao");
    }
    listaBotao.push_back(botao);
}

void Fantasy::Menu::Menu::atualizarPosicaoFundo() {
    posFundo = pGrafico->getCamera().getCenter();
}

void Fantasy::Menu::Menu::selecionaCima() {
    Botao::Botao* botao = *it;
    botao->setSelecionado(false);
    if (it == listaBotao.begin()) {
        it = listaBotao.end();
    }
    it--;
    botao = *it;
    botao->setSelecionado(true);
}

void Fantasy::Menu::Menu::selecionaBaixo() {
    Botao::Botao* botao = *it;
    botao->setSelecionado(false);
    it++;
    if (it == listaBotao.end()) {
        it = listaBotao.begin();
    }
    botao = *it;
    botao->setSelecionado(true);
}

const IDs::IDs Fantasy::Menu::Menu::getIDBotaoSelecionado() {
    return (*it)->getID();
}

void Fantasy::Menu::Menu::desenhar() {
    std::list<Botao::Botao*>::iterator aux;
    for (aux = listaBotao.begin(); aux != listaBotao.end(); aux++) {
        Botao::Botao* botao = *aux;
        botao->desenhar();
        botao = nullptr;
    }
}