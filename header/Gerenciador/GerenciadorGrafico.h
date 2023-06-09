#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

#define TELA_X 800.0f
#define TELA_Y 600.0f

namespace Fantasy {

    namespace Gerenciador {

        class GerenciadorGrafico {
        private:
            sf::RenderWindow* window;
            sf::View camera;

            //a construtora privada faz parte do padr�o de projeto singleton
            static GerenciadorGrafico* pGrafico;
            GerenciadorGrafico();
        public:
            ~GerenciadorGrafico();
            static GerenciadorGrafico* getGerenciadorGrafico();
            sf::RenderWindow* getWindow();
            sf::Texture carregarTextura(const char* caminhoTextura);
            sf::Font carregarFonte(const char* caminhoFonte);
            void limpaJanela();
            void desenhaElemento(sf::RectangleShape corpo);
            void desenhaElemento(sf::Text texto);
            void mostraElementos();
            void fecharJanela();
            const bool verificaJanelaAberta();
            void atualizarCamera(const sf::Vector2f pos);
            const sf::View getCamera();
            void resetarJanela();
            const sf::Vector2f getTamJanela() const;
        };

    }

}
