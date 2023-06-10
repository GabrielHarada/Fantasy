#include "..\..\header\Observador\ObservadorMenuPrincipal.h"
#include "..\..\header\Menu\MenuPrincipal.h"
#include "..\..\header\Gerenciador\GerenciadorEstado.h"

Fantasy::Observador::ObservadorMenuPrincipal::ObservadorMenuPrincipal(Menu::MenuPrincipal* menuPrincipal) :
    Observador(), menuPrincipal(menuPrincipal)
{

}

Fantasy::Observador::ObservadorMenuPrincipal::~ObservadorMenuPrincipal() {

}

void Fantasy::Observador::ObservadorMenuPrincipal::teclaPressionada(const sf::Keyboard::Key tecla) {
    switch (tecla)
    {
    case (sf::Keyboard::Enter):
    {
        switch (menuPrincipal->getIDBotaoSelecionado())
        {
        case (IDs::IDs::botao_novoJogo):
        {
            pGEstado->addEstado(IDs::IDs::jogar_florestaBranca);
        }
        break;
        case (IDs::IDs::botao_sair):
        {
            pGEstado->removerEstado();
        }
        break;
        case (IDs::IDs::botao_opcao):
        {
            pGEstado->addEstado(IDs::IDs::estado_menu_opcaoPrincipal);
        }
        break;
        }
    }
    break;
    }
}

void Fantasy::Observador::ObservadorMenuPrincipal::teclaSolta(const sf::Keyboard::Key tecla) {
    switch (tecla)
    {
    case (sf::Keyboard::Up):
    {
        menuPrincipal->selecionaCima();
    }
    break;
    case (sf::Keyboard::Down):
    {
        menuPrincipal->selecionaBaixo();
    }
    break;
    }
}