#pragma once 

#include <list>

#include "..\Ente.h"
#include "Botao\Botao.h"
#include "Botao\Texto.h"

namespace Fantasy {

    namespace Menu {

        class Menu : public Ente {
        protected:
            std::list<Botao::Botao*> listaBotao;
            std::list<Botao::Botao*>::iterator it;
            const sf::Vector2f tamBotao;    
            const sf::Vector2f tamJanela;
            sf::Vector2f posFundo;
            Botao::Texto nomeMenu;

            void atualizarPosicaoFundo();
        public:
            Menu(const IDs::IDs ID, const sf::Vector2f tamBotao, const std::string nome, const unsigned int tamFonte);
            ~Menu();
            void addBotao(const std::string info, const sf::Vector2f pos, const IDs::IDs ID, const sf::Color corSelecionado);
            void desenhar();
            void selecionaCima();
            void selecionaBaixo();
            const IDs::IDs getIDBotaoSelecionado();
            virtual void executar() = 0;
        };

    }

}