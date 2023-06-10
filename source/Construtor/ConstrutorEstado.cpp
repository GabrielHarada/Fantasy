#include "..\..\header\Construtor\ConstrutorEstado.h"

Fantasy::Construtor::ConstrutorEstado::ConstrutorEstado() {

}

Fantasy::Construtor::ConstrutorEstado::~ConstrutorEstado() {

}

Fantasy::Estado::Estado* Fantasy::Construtor::ConstrutorEstado::criarEstadoJogar(const IDs::IDs ID) {
    Fase::Fase* fase = nullptr;
    Construtor::ConstrutorFase construtorFase;


    fase = construtorFase.criarFase(ID);

    Estado::EstadoJogar* estadoJogar = new Estado::EstadoJogar(ID, fase);
    return static_cast<Estado::Estado*>(estadoJogar);
}

Fantasy::Estado::Estado* Fantasy::Construtor::ConstrutorEstado::criarMenuPrincipal(const IDs::IDs ID) {
    Estado::Estado* estado = static_cast<Estado::Estado*>(new Estado::EstadoMenuPrincipal(ID));
    return estado;
}

Fantasy::Estado::Estado* Fantasy::Construtor::ConstrutorEstado::criarEstado(const IDs::IDs ID) {
    if (IDs::IDs::jogar_florestaBranca == ID || IDs::IDs::jogar_florestaVermelha == ID) {
        return criarEstadoJogar(ID);
    }
    else if(ID == IDs::IDs::estado_menu_principal){
                return criarMenuPrincipal(ID);
    }
    return nullptr;
}
