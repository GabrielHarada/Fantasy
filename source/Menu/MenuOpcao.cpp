#include "..\..\header\Menu\MenuOpcao.h"

Fantasy::Menu::MenuOpcao::MenuOpcao() :
    Menu(IDs::IDs::menu_opcao, sf::Vector2f(TAMANHO_BOTAO_MENU_OPCAO_X, TAMANHO_BOTAO_MENU_OPCAO_Y), "Opcoes", 100)
{

}

Fantasy::Menu::MenuOpcao::~MenuOpcao() {

}

void Fantasy::Menu::MenuOpcao::addBotao(const std::string info, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado, const float posInicioFundo) {
    /* Botao::BotaoVolume* botaoVolume = new Botao::BotaoVolume(info, tamBotao, pos, ID, corSelecionado, posInicioFundo);
    if (botaoVolume == nullptr) {
        throw("ERROR::Jungle::Menu::nao foi possivel criar um botao");
    }
    listaBotao.push_back(static_cast<Botao::Botao*>(botaoVolume));*/
}