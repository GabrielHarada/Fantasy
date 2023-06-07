#include "..\..\header\Parallax\Fundo.h"

Fantasy::Parallax::Fundo::Fundo(const IDs::IDs ID) :
    Ente(ID), posAnteriorCamera(pGrafico->getCamera().getCenter()),
    camadas()
    {
    
    /*
    addCamada("image/Fase/Fase1/camada1.png", 0.0f);
    addCamada("image/Fase/Fase1/camada2.png", 0.0f);
    addCamada("image/Fase/Fase1/camada3.png", 0.1f);
    addCamada("image/Fase/Fase1/camada4.png", 0.2f);
    addCamada("image/Fase/Fase1/camada5.png", 0.3f);
    addCamada("image/Fase/Fase1/camada6.png", 0.5f);
    addCamada("image/Fase/Fase1/camada7.png", 0.75f);
    addCamada("image/Fase/Fase1/camada8.png", 1.5f);
    */

    /*
    addCamada("image/Fase/FLorestaBranca/camada1.png", 0.0f);
    addCamada("image/Fase/FLorestaBranca/camada2.png", 0.1f);
    addCamada("image/Fase/FLorestaBranca/camada3.png", 0.3f);
    addCamada("image/Fase/FLorestaBranca/camada4.png", 0.5f);
    addCamada("image/Fase/FLorestaBranca/camada5.png", 1.0f);
    */
    
    /*
    addCamada("image/Fase/FlorestaNegra/camada1.png", 0.0f);
    addCamada("image/Fase/FlorestaNegra/camada2.png", 0.05f);
    addCamada("image/Fase/FlorestaNegra/camada3.png", 0.1f);
    addCamada("image/Fase/FlorestaNegra/camada4.png", 0.15f);
    addCamada("image/Fase/FlorestaNegra/camada5.png", 0.2f);
    addCamada("image/Fase/FlorestaNegra/camada6.png", 0.4f);
    addCamada("image/Fase/FlorestaNegra/camada7.png", 0.6f);
    */
    
}

Fantasy::Parallax::Fundo::~Fundo() {
    for (int i = 0; i < camadas.size(); i++) {
        Camada* camada = camadas.at(i);
        if (camada) {
            delete(camada);
            camada = nullptr;
        }
    }
    camadas.clear();
}

void Fantasy::Parallax::Fundo::executar() {
    sf::Vector2f posCamera = pGrafico->getCamera().getCenter();
    sf::Vector2f ds = posCamera - posAnteriorCamera;
    posAnteriorCamera = posCamera;
    if (ds.x != 0.0f) {
        ds.x *= 0.5f;
        for (int i = 0; i < camadas.size(); i++) {
            camadas.at(i)->atualizar(ds, posCamera);
        }
    }
    desenhar();
}

void Fantasy::Parallax::Fundo::desenhar() {
    for (int i = 0; i < camadas.size(); i++) {
        Camada* camada = camadas.at(i);
        camada->desenharCamada(pGrafico->getWindow());

    }
}

void Fantasy::Parallax::Fundo::addCamada(const char* caminhoTextura, const float vel) {
    Camada* camada = new Camada((sf::Vector2f)pGrafico->getWindow()->getSize(), pGrafico->carregarTextura(caminhoTextura), vel);
    if (camada == nullptr) {
        std::cout << "ERRO::Fantasy::Parallax::Fundo::nao foi possivel criar uma camada" << std::endl;
        exit(1);
    }
    camadas.push_back(camada);
}