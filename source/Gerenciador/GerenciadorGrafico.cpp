#include "..\..\header\Gerenciador\GerenciadorGrafico.h"

Fantasy::Gerenciador::GerenciadorGrafico* Fantasy::Gerenciador::GerenciadorGrafico::pGrafico = nullptr;

Fantasy::Gerenciador::GerenciadorGrafico::GerenciadorGrafico():
    window(new sf::RenderWindow(sf::VideoMode(TELA_X, TELA_Y), "Fantasy++")),
    camera(sf::Vector2f(TELA_X / 2.0f, TELA_Y / 2.0f), sf::Vector2f(TELA_X, TELA_Y))
{
    if(window == nullptr){
        std::cout << "ERROR::Fantasy::Gerenciador::GerenciadorGrafico nao foi possivel criar uma janela grafica" << std::endl;
        exit(1);
    }
}

Fantasy::Gerenciador::GerenciadorGrafico::~GerenciadorGrafico(){
    if(window){
        delete(window);
        window = nullptr;
    }
}

Fantasy::Gerenciador::GerenciadorGrafico* Fantasy::Gerenciador::GerenciadorGrafico::getGerenciadorGrafico(){
    /**
     * @ return GerenciadorGrafico*
     * 
     * Padrão de Projeto Singleton: garante que eu tenha apenas uma instância no meu projeto como um todo, isto é,
     * não é possível criar dois objetos diferentes deste tipo.
     */

    if(pGrafico == nullptr){
        pGrafico = new GerenciadorGrafico();
    }
    return pGrafico;
}

sf::RenderWindow* Fantasy::Gerenciador::GerenciadorGrafico::getWindow(){
    return window;
}

sf::Texture Fantasy::Gerenciador::GerenciadorGrafico::carregarTextura(const char* caminhoTextura){
    sf::Texture textura;
    if (!textura.loadFromFile(caminhoTextura)) {
        std::cout << "ERRO::Fantasy::Gerenciador::GerenciadorGrafico::nao foi possivel encontrar o caminho da textura - " << caminhoTextura << std::endl;
        exit(1);
    }
    return textura;
}

sf::Font Fantasy::Gerenciador::GerenciadorGrafico::carregarFonte(const char* caminhoFonte) {
    sf::Font fonte;
    if (!fonte.loadFromFile(caminhoFonte)) {
        throw("ERROR::Fantasy::Gerenciador::GerenciadorGrafico::nao foi possivel encontrar o caminho da fonte");
    }
    return fonte;
}

void Fantasy::Gerenciador::GerenciadorGrafico::limpaJanela(){
    window->clear();
}

void Fantasy::Gerenciador::GerenciadorGrafico::desenhaElemento(sf::RectangleShape corpo){
    window->draw(corpo);
}

void Fantasy::Gerenciador::GerenciadorGrafico::desenhaElemento(sf::Text texto) {
    window->draw(texto);
}

void Fantasy::Gerenciador::GerenciadorGrafico::mostraElementos(){
    window->display();
}

void Fantasy::Gerenciador::GerenciadorGrafico::fecharJanela(){
    window->close();
}

const bool Fantasy::Gerenciador::GerenciadorGrafico::verificaJanelaAberta(){
    return window->isOpen();
}

void Fantasy::Gerenciador::GerenciadorGrafico::atualizarCamera(const sf::Vector2f pos) {
    camera.setCenter(pos);
    window->setView(camera);
}

const sf::View Fantasy::Gerenciador::GerenciadorGrafico::getCamera() {
    return camera;
}

void Fantasy::Gerenciador::GerenciadorGrafico::resetarJanela() {
    camera.setCenter(TELA_X / 2.0f, TELA_Y / 2.0f);
    window->setView(camera);
}

const sf::Vector2f Fantasy::Gerenciador::GerenciadorGrafico::getTamJanela() const {
    return (sf::Vector2f)window->getSize();
}