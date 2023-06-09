#include "..\..\header\Construtor\ConstrutorEstado.h"

Fantasy::Construtor::ConstrutorEstado::ConstrutorEstado() {

}

Fantasy::Construtor::ConstrutorEstado::~ConstrutorEstado() {

}

Fantasy::Estado::Estado* Fantasy::Construtor::ConstrutorEstado::addEstadoJogar(const IDs::IDs ID) {
    Fase::Fase* fase = nullptr;
    if (ID == IDs::IDs::jogar_florestaBranca) {
        fase = static_cast<Fase::Fase*>(new Fase::FlorestaBranca());
    }
    else {
        fase = static_cast<Fase::Fase*>(new Fase::FlorestaVermelha());
    }
    if (fase == nullptr) {
        std::cout << "Fantasy::Estado::MaquinaEstado::nao foi possivel criar uma fase" << std::endl;
        exit(1);
    }
    fase->criarFundo();
    fase->criarMapa();
    Estado::EstadoJogar* estadoJogar = new Estado::EstadoJogar(fase);
    if (estadoJogar == nullptr) {
        std::cout << "Fantasy::Estado::MaquinaEstado::nao foi possivel criar um Estado Jogar" << std::endl;
        exit(1);
    }
    return static_cast<Estado::Estado*>(estadoJogar);
}