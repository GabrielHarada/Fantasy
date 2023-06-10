#include "..\..\header\Construtor\ConstrutorFase.h"


Fantasy::Construtor::ConstrutorFase::ConstrutorFase() {

}

Fantasy::Construtor::ConstrutorFase::~ConstrutorFase() {

}

Fantasy::Fase::Fase* Fantasy::Construtor::ConstrutorFase::criarFlorestaBranca() {
    Fase::Fase* fase = static_cast<Fase::Fase*>(new Fase::FlorestaBranca());
    if (fase == nullptr) {
        std::cout << "Fantasy::Construtor::ConstrutorFase::nao foi possivel criar Fase Floresta Branca" << std::endl;
        exit(1);
    }
    return fase;
}

Fantasy::Fase::Fase* Fantasy::Construtor::ConstrutorFase::criarFlorestaVermelha() {
    Fase::Fase* fase = static_cast<Fase::Fase*>(new Fase::FlorestaVermelha());
    if (fase == nullptr) {
        std::cout << "Fantasy::Construtor::ConstrutorFase::nao foi possivel criar Fase Floresta Vermelha" << std::endl;
        exit(1);
    }
    return fase;
}

Fantasy::Fase::Fase* Fantasy::Construtor::ConstrutorFase::criarFase(const IDs::IDs ID) {
    Fase::Fase* fase = nullptr;
    switch (ID)
    {
    case (IDs::IDs::jogar_florestaBranca):
    {
        fase = criarFlorestaBranca();
    }
    break;

    case (IDs::IDs::jogar_florestaVermelha):
    {
        fase = criarFlorestaVermelha();
    }
    break;
    default:
    {
        std::cout << "Fantasy::Construtor::ConstrutorFase::ID da Fase invalido" << std::endl;
        exit(1);
    }
    break;
    }
    fase->criarFundo();
    fase->criarMapa();
    return fase;
}
