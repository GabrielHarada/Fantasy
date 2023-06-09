#pragma once

#include "..\Gerenciador\GerenciadorGrafico.h"
#include <SFML\Graphics.hpp>
#include "Imagem.h"
#include <map>

namespace Fantasy {

    namespace Animador {

        class Animacao {
        private:
            sf::RectangleShape* corpo;
            std::map<std::string, Imagem*> mapImagem;
            sf::Clock relogio;
            std::string imgAtual;
        public:
            Animacao(sf::RectangleShape* corpo);
            ~Animacao();
            void atualizar(const bool paraEsquerda, std::string imgAtual);
            void addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, const unsigned int qtdImagem, const float tempoTroca, const sf::Vector2f escala);
        };

    }

}