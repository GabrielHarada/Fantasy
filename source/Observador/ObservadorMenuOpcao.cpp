#include "..\..\header\Observador\ObservadorMenuOpcao.h"
#include "..\..\header\Gerenciador\GerenciadorEstado.h"

Fantasy::Observador::ObservadorMenuOpcao::ObservadorMenuOpcao(Menu::MenuOpcao* menuOpcao) :
    Observador(), menuOpcao(menuOpcao)
{

}

Fantasy::Observador::ObservadorMenuOpcao::~ObservadorMenuOpcao() {

}

void Fantasy::Observador::ObservadorMenuOpcao::teclaPressionada(const sf::Keyboard::Key tecla) {
    switch (tecla)
    {
        /*case (sf::Keyboard::Left):
        {
            menuOpcao->alterarVolume(false);
        }
        break;
        case (sf::Keyboard::Right):
        {
            menuOpcao->alterarVolume(true);
        }
        break;*/
        case (sf::Keyboard::Enter):
        {
            if (menuOpcao->getIDBotaoSelecionado() == IDs::IDs::botao_voltar) {
                pGEstado->removerEstado();
            }
        }
    }
}

void Fantasy::Observador::ObservadorMenuOpcao::teclaSolta(const sf::Keyboard::Key tecla) {
    switch (tecla)
    {
    case (sf::Keyboard::Up):
    {
        menuOpcao->selecionaCima();
    }
    break;
    case (sf::Keyboard::Down):
    {
        menuOpcao->selecionaBaixo();
    }
    break;
    }
}