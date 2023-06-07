#include "..\..\header\Fase\FlorestaVermelha.h"

Fantasy::Fase::FlorestaVermelha::FlorestaVermelha() :
    Fase(IDs::IDs::fase_florestaVermelha, IDs::IDs::fundo_florestaVermelha)
{

}

Fantasy::Fase::FlorestaVermelha::~FlorestaVermelha() {

}

void Fantasy::Fase::FlorestaVermelha::criarFundo() {
    fundo.addCamada("image/Fase/FLorestaVermelha/camada1.png", 0.0f);
    fundo.addCamada("image/Fase/FLorestaVermelha/camada2.png", 0.1f);
    fundo.addCamada("image/Fase/FLorestaVermelha/camada3.png", 0.3f);
    fundo.addCamada("image/Fase/FLorestaVermelha/camada4.png", 0.5f);
}

void Fantasy::Fase::FlorestaVermelha::criarMapa() {
    std::ifstream arquivo;
    std::string linha;
    arquivo.open("image/Fase/FlorestaVermelha/Mapa_Floresta_Vermelha.txt");
    if (!arquivo.is_open()) {
        std::cout << "Fantasy::Fase::FlorestaVermelha::nao foi possivel abrir o arquivo" << std::endl;
        exit(1);
    }
    int j = 0;
    while (std::getline(arquivo, linha)) {
        for (int i = 0; i < linha.size(); i++) {
            if (linha[i] != ' ') {
                criarEntidade(linha[i], sf::Vector2i(i, j));
            }
        }
        j++;
    }
    arquivo.close();

}