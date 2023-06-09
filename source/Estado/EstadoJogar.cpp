#include "..\..\header\Estado\EstadoJogar.h"

namespace Fantasy {

    namespace Estado {

        EstadoJogar::EstadoJogar(Fase::Fase* fase) :
            Estado(fase->getID()), fase(fase)
        {

        }

        EstadoJogar::~EstadoJogar() {

        }

        /*
        void EstadoJogar::desenhar(){
            fase->desenhar();
        }
        */

        void EstadoJogar::executar() {
            fase->executar();
            //desenhar();
        }

    }

}