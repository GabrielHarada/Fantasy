#include "..\..\header\Gerenciador\GerenciadorGrafico.h"

Fantasy::Gerenciador::GerenciadorGrafico* Fantasy::Gerenciador::GerenciadorGrafico::pGrafico = nullptr;

Fantasy::Gerenciador::GerenciadorGrafico::GerenciadorGrafico():
    window(new sf::RenderWindow(sf::VideoMode(1280.0f, 1024.0f), "Fantasy++"))
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
        std::cout << "ERRO::Jungle::Gerenciador::GerenciadorGrafico::nao foi possivel encontrar o caminho da textura - " << caminhoTextura << std::endl;
        exit(1);
    }
    return textura;
}

void Fantasy::Gerenciador::GerenciadorGrafico::limpaJanela(){
    window->clear();
}

void Fantasy::Gerenciador::GerenciadorGrafico::desenhaElemento(sf::RectangleShape corpo){
    window->draw(corpo);
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