#pragma once

#include "..\Ente.h"

namespace Fantasy {

    namespace Estado {

        class Estado : public Ente {
        private:
            bool remover;
        public:
            Estado(const IDs::IDs ID);
            ~Estado();
            virtual void executar() = 0;
            virtual void desenhar();
            void setRemover(const bool remover = true);
            const bool getRemover() const;
        };

    }

}
