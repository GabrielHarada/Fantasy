#pragma once

#include "Fase.h"

namespace Jogo {

    namespace Fase {

        class FaseFloresta : public Fase {
        private:
        public:
            FaseFloresta();
            ~FaseFloresta();
            void criarEntidades();
        };

    }

}