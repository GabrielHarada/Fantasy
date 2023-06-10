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

Fantasy::Estado::Estado* Fantasy::Construtor::ConstrutorEstado::criarMenuPrincipal() {
            Estado::Estado* estado = static_cast<Estado::Estado*>(new Estado::EstadoMenuPrincipal());
            return estado;
}

Fantasy::Estado::Estado* Fantasy::Construtor::ConstrutorEstado::criarMenuPausar() {
    Estado::Estado* estado = static_cast<Estado::Estado*>(new Estado::EstadoMenuPausa());
    return estado;
}

Fantasy::Estado::Estado* Fantasy::Construtor::ConstrutorEstado::criarMenuOpcaoPrincipal() {
    Estado::Estado* estado = static_cast<Estado::Estado*>(new Estado::EstadoMenuOpcaoPrincipal());
    return estado;
}


Fantasy::Estado::Estado* Fantasy::Construtor::ConstrutorEstado::criarEstado(const IDs::IDs ID) {
    Estado::Estado* estado = nullptr;
    switch (ID)
    {
    case (IDs::IDs::jogar_florestaBranca):
    {
        estado = criarEstadoJogar(ID);
    }
    break;
    case (IDs::IDs::jogar_florestaVermelha):
    {
        estado = criarEstadoJogar(ID);
    }
    break;
    case (IDs::IDs::estado_menu_principal):
    {
        estado = criarMenuPrincipal();
    }
    break;
    case (IDs::IDs::estado_menu_pausa):
    {
        estado = criarMenuPausar();
    }
    break;
    case (IDs::IDs::estado_menu_opcaoPrincipal):
    {
        estado = criarMenuOpcaoPrincipal();
    }
    break;
    }
    return estado;
}
