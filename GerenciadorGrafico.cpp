#include "GerenciadorGrafico.h"


namespace Jogo {

    namespace Gerenciador {

        GerenciadorGrafico* GerenciadorGrafico::pGrafico = nullptr;

        GerenciadorGrafico::GerenciadorGrafico() :
            window(new sf::RenderWindow(sf::VideoMode(TELA_X, TELA_Y), "Jungle++")),
            camera(sf::Vector2f(TELA_X / 2.0f, TELA_Y / 2.0f), sf::Vector2f(TELA_X, TELA_Y))
        {
            if (window == nullptr) {
                std::cout << "ERROR::Jungle::Gerenciador::GerenciadorGrafico nao foi possivel criar uma janela grafica" << std::endl;
                exit(1);
            }
        }

        GerenciadorGrafico::~GerenciadorGrafico() {
            if (window) {
                delete(window);
                window = nullptr;
            }
        }

        GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico() {
            /**
             * @ return GerenciadorGrafico*
             *
             * Padrão de Projeto Singleton: garante que eu tenha apenas uma instância no meu projeto como um todo, isto é,
             * não é possível criar dois objetos diferentes deste tipo.
             */

            if (pGrafico == nullptr) {
                pGrafico = new GerenciadorGrafico();
            }
            return pGrafico;
        }

        sf::RenderWindow* GerenciadorGrafico::getWindow() {
            return window;
        }

        void GerenciadorGrafico::limpaJanela() {
            window->clear();
        }

        void GerenciadorGrafico::desenhaElemento(sf::RectangleShape corpo) {
            window->draw(corpo);
        }

        void GerenciadorGrafico::mostraElementos() {
            window->display();
        }

        void GerenciadorGrafico::fecharJanela() {
            window->close();
        }

        const bool GerenciadorGrafico::verificaJanelaAberta() {
            return window->isOpen();
        }

    }

}