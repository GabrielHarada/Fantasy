#pragma once

#include "Fase.h"

namespace Fantasy {

    namespace Fase {

        class FlorestaVermelha : public Fase {
        private:
        public:
            FlorestaVermelha();
            ~FlorestaVermelha();
            void criarFundo();
            void criarMapa();
        };

    }

}