#include "GerenciadorGrafico.h"

Jogo::Gerenciador::GerenciadorGrafico* Jogo::Gerenciador::GerenciadorGrafico::pGrafico = nullptr;

Jogo::Gerenciador::GerenciadorGrafico::GerenciadorGrafico():
    window(new sf::RenderWindow(sf::VideoMode(800.0f, 600.0f), "Jogo++"))
{
    if(window == nullptr){
        std::cout << "ERROR::Jogo::Gerenciador::GerenciadorGrafico nao foi possivel criar uma janela grafica" << std::endl;
        exit(1);
    }
}

Jogo::Gerenciador::GerenciadorGrafico::~GerenciadorGrafico(){
    if(window){
        delete(window);
        window = nullptr;
    }
}

Jogo::Gerenciador::GerenciadorGrafico* Jogo::Gerenciador::GerenciadorGrafico::getGerenciadorGrafico(){
    /**
     * @ return GerenciadorGrafico*
     * 
     * Padr�o de Projeto Singleton: garante que eu tenha apenas uma inst�ncia no meu projeto como um todo, isto �,
     * n�o � poss�vel criar dois objetos diferentes deste tipo.
     */

    if(pGrafico == nullptr){
        pGrafico = new GerenciadorGrafico();
    }
    return pGrafico;
}

sf::RenderWindow* Jogo::Gerenciador::GerenciadorGrafico::getWindow(){
    return window;
}

sf::Texture Jogo::Gerenciador::GerenciadorGrafico::carregarTextura(const char* caminhoTextura){
    //terminar...
    return sf::Texture();
}

void Jogo::Gerenciador::GerenciadorGrafico::limpaJanela(){
    window->clear();
}

void Jogo::Gerenciador::GerenciadorGrafico::desenhaElemento(sf::RectangleShape corpo){
    window->draw(corpo);
}

void Jogo::Gerenciador::GerenciadorGrafico::mostraElementos(){
    window->display();
}

void Jogo::Gerenciador::GerenciadorGrafico::fecharJanela(){
    window->close();
}

const bool Jogo::Gerenciador::GerenciadorGrafico::verificaJanelaAberta(){
    return window->isOpen();
}