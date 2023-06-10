#include "..\..\header\Menu\MenuOpcaoPrincipal.h"
#include "..\..\header\Observador\ObservadorMenuOpcao.h"

Fantasy::Menu::MenuOpcaoPrincipal::MenuOpcaoPrincipal() :
    MenuOpcao(), fundo(IDs::IDs::fundo_florestaNegra), observadorMenuOpcao(new Observador::ObservadorMenuOpcao(this))
{
    nomeMenu.setCorTexto(sf::Color{ 0,255,0 });
    nomeMenu.setPos(sf::Vector2f(tamJanela.x / 2.0f - nomeMenu.getTam().x / 2.0f, 25.0f));
    criarFundo();
    criarBotoes();
}

Fantasy::Menu::MenuOpcaoPrincipal::~MenuOpcaoPrincipal() {
    if (observadorMenuOpcao) {
        delete(observadorMenuOpcao);
        observadorMenuOpcao = nullptr;
    }
}

void Fantasy::Menu::MenuOpcaoPrincipal::criarBotoes() {
    Menu::addBotao("Voltar", sf::Vector2f(tamJanela.x / 2.0f - tamBotao.x / 2.0f, 450.0f), IDs::IDs::botao_voltar, sf::Color{ 0,255,0 });
    it = listaBotao.begin();
    (*it)->setSelecionado(true);
}

void Fantasy::Menu::MenuOpcaoPrincipal::criarFundo() {
    fundo.addCamada("image/Fase/FlorestaNegra/camada1.png", 0.0f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada2.png", 0.05f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada3.png", 0.1f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada4.png", 0.15f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada5.png", 0.2f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada6.png", 0.4f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada7.png", 0.6f);
}

void Fantasy::Menu::MenuOpcaoPrincipal::executar() {
    posFundo = sf::Vector2f(posFundo.x + 0.05f, posFundo.y);
    pGrafico->atualizarCamera(sf::Vector2f(posFundo.x + tamJanela.x / 2.0f, posFundo.y + tamJanela.y / 2.0f));
    fundo.executar();
    pGrafico->resetarJanela();

    desenhar();
    pGrafico->desenhaElemento(nomeMenu.getTexto());
}