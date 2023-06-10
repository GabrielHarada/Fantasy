#include "..\..\header\Observador\ObservadorMenuPausa.h"
#include "..\..\header\Gerenciador\GerenciadorEstado.h"

Fantasy::Observador::ObservadorMenuPausa::ObservadorMenuPausa(Menu::MenuPausa* menuPausa) :
    Observador(), menuPausa(menuPausa)
{

}

Fantasy::Observador::ObservadorMenuPausa::~ObservadorMenuPausa() {

}

void Fantasy::Observador::ObservadorMenuPausa::teclaPressionada(const sf::Keyboard::Key tecla) {
    switch (tecla)
    {
    case (sf::Keyboard::Enter):
    {
        switch (menuPausa->getIDBotaoSelecionado())
        {
        case (IDs::IDs::botao_voltar):
        {
            pGEstado->removerEstado();
        }
        break;
        case (IDs::IDs::botao_sair):
        {
            pGEstado->removerEstado();
            pGEstado->removerEstado();
        }
        break;
        }
    }
    break;
    }
}

void Fantasy::Observador::ObservadorMenuPausa::teclaSolta(const sf::Keyboard::Key tecla) {
    switch (tecla)
    {
    case (sf::Keyboard::Up):
    {
        menuPausa->selecionaCima();
    }
    break;
    case (sf::Keyboard::Down):
    {
        menuPausa->selecionaBaixo();
    }
    break;
    }
}