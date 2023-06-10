#pragma once

#include "Texto.h"

namespace Fantasy {

    namespace Menu {

        namespace Botao {

            class TextoAnimado : public Texto {
            private:
                int transparente;
                bool clareando;

                void atualizar();
            public:
                TextoAnimado(sf::Font fonte, const std::string texto);
                ~TextoAnimado();
                void mudarClareando();
                const bool getClareando() const;
                const int  getTransparente() const;
                void setTransparente(int transparente);
                void resetar();
            };

        }

    }

}