#include "..\..\header\Menu\MenuPausa.h"
#include "..\..\header\Observador\ObservadorMenuPausa.h"

Fantasy::Menu::MenuPausa::MenuPausa(Fase::Fase* fase) :
    Menu(IDs::IDs::menu_pausa, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "PAUSA", 100), fase(fase),
    observadorMenuPausa(new Observador::ObservadorMenuPausa(this)), fundoEscuro(tamJanela),
    fundoPainel(sf::Vector2f(tamJanela.x / 2.0f, tamJanela.y)) 
{
    nomeMenu.setCorTexto(sf::Color{ 255,0,0 });
    fundoEscuro.setFillColor(sf::Color{ 0, 0, 0, 180 });
    fundoPainel.setFillColor(sf::Color{ 0, 0, 0, 220 });
    criarBotoes();
}

Fantasy::Menu::MenuPausa::~MenuPausa() {
    if (observadorMenuPausa) {
        delete(observadorMenuPausa);
        observadorMenuPausa = nullptr;
    }
}

void Fantasy::Menu::MenuPausa::criarBotoes() {
    addBotao("Voltar", sf::Vector2f(0.0f, 0.0f), IDs::IDs::botao_voltar, sf::Color{ 255, 0, 0 });
    addBotao("Salvar Jogada", sf::Vector2f(0.0f, 0.0f), IDs::IDs::botao_salvarJogada, sf::Color{ 255, 0, 0 });
    addBotao("Opcao", sf::Vector2f(0.0f, 0.0f), IDs::IDs::botao_opcao, sf::Color{ 255, 0, 0 });
    addBotao("Sair", sf::Vector2f(0.0f, 0.0f), IDs::IDs::botao_sair, sf::Color{ 255, 0, 0 });
    it = listaBotao.begin();
    (*it)->setSelecionado(true);
}

void Fantasy::Menu::MenuPausa::mudarEstadoObservador() {
    observadorMenuPausa->mudarEstadoAtivar();
}

void Fantasy::Menu::MenuPausa::atualizarFundo() {
    atualizarPosicaoFundo();
    sf::Vector2f posFundoEscuro = sf::Vector2f(posFundo.x - tamJanela.x / 2.0f, posFundo.y - tamJanela.y / 2.0f);
    fundoEscuro.setPosition(posFundoEscuro);
    fundoPainel.setPosition(sf::Vector2f(posFundoEscuro.x + tamJanela.x / 4.0f, posFundoEscuro.y));

    pGrafico->desenhaElemento(fundoEscuro);
    pGrafico->desenhaElemento(fundoPainel);
}

void Fantasy::Menu::MenuPausa::atualizarNomeMenu() {
    nomeMenu.setPos(sf::Vector2f(posFundo.x - nomeMenu.getTam().x / 2.1f, posFundo.y - tamJanela.y / 2.0f));

    pGrafico->desenhaElemento(nomeMenu.getTexto());
}

void Fantasy::Menu::MenuPausa::setFase(Fase::Fase* fase) {
    this->fase = fase;
}

void Fantasy::Menu::MenuPausa::atualizarBotoes() {
    std::list<Botao::Botao*>::iterator aux;
    int i = 1;
    for (aux = listaBotao.begin(); aux != listaBotao.end(); aux++, i++) {
        Botao::Botao* botao = *aux;
        botao->atualizarPosicao(sf::Vector2f(posFundo.x - tamJanela.x / 4.6f, posFundo.y / 1.5f + (tamBotao.y + 20.f) * i));
        botao = nullptr;
    }
    desenhar();
}

void Fantasy::Menu::MenuPausa::executar() {
    //somente pinta as entidades
    fase->desenhar();

    //atualiza o menu pausar
    atualizarFundo();
    atualizarNomeMenu();
    atualizarBotoes();
}
