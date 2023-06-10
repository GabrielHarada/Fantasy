#include "..\..\header\Menu\MenuPrincipal.h"

Fantasy::Menu::MenuPrincipal::MenuPrincipal() :
    Menu(IDs::IDs::menu_principal, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "Fantasy++", 180),
    sair(false), observadorMenuPrincipal(new Observador::ObservadorMenuPrincipal(this)),
    fundo(IDs::IDs::fundo_florestaNegra)
{
    if (observadorMenuPrincipal == nullptr) {
        std::cout << "ERROR::Fantasy::Menu::MenuPrincipal::nao foi possivel criar um Observador Menu Principal" << std::endl;
        exit(1);
    }
    nomeMenu.setPos(sf::Vector2f(tamJanela.x / 2.0f - nomeMenu.getTam().x / 2.0f, 25.0f));
    nomeMenu.setCorTexto(sf::Color{ 0,200,0 });
    criarFundo();
    criarBotoes();
}

Fantasy::Menu::MenuPrincipal::~MenuPrincipal() {
    if (observadorMenuPrincipal) {
        delete(observadorMenuPrincipal);
        observadorMenuPrincipal = nullptr;
    }
}

void Fantasy::Menu::MenuPrincipal::criarFundo() {
    fundo.addCamada("image/Fase/FlorestaNegra/camada1.png", 0.0f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada2.png", 0.05f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada3.png", 0.1f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada4.png", 0.15f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada5.png", 0.2f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada6.png", 0.4f);
    fundo.addCamada("image/Fase/FlorestaNegra/camada7.png", 0.6f);
}

void Fantasy::Menu::MenuPrincipal::criarBotoes() {
    const float posBotaoX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
    addBotao("Novo Jogo", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f), IDs::IDs::botao_novoJogo, sf::Color{ 0, 255, 0 });
    addBotao("Carregar Jogo", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 1.2f), IDs::IDs::botao_carregarJogo, sf::Color{ 0, 255, 0 });
    addBotao("Colocacao", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 2.4f), IDs::IDs::botao_colocacao, sf::Color{ 0, 255, 0 });
    addBotao("Opcao", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 3.6f), IDs::IDs::botao_opcao, sf::Color{ 0, 255, 0 });
    addBotao("Sair", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 4.8f), IDs::IDs::botao_sair, sf::Color{ 0, 255, 0 });
    it = listaBotao.begin();
    (*it)->setSelecionado(true);
}

void Fantasy::Menu::MenuPrincipal::setSair(const bool sair) {
    this->sair = sair;
}

const bool Fantasy::Menu::MenuPrincipal::getSair() const {
    return sair;
}

void Fantasy::Menu::MenuPrincipal::mudarEstadoObservador() {
    observadorMenuPrincipal->mudarEstadoAtivar();
}

void Fantasy::Menu::MenuPrincipal::executar() {
    //conteúdo do efeito Parallax
    posFundo = sf::Vector2f(posFundo.x + 0.05f, posFundo.y);
    pGrafico->atualizarCamera(sf::Vector2f(posFundo.x + tamJanela.x / 2.0f, posFundo.y + tamJanela.y / 2.0f));
    fundo.executar();
    pGrafico->resetarJanela();

    //desenha todo o conteúdo do menu principal na tela
    desenhar();
    pGrafico->desenhaElemento(nomeMenu.getTexto());
}