#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "..\header\Gerenciador\GerenciadorGrafico.h"
#include "..\header\Gerenciador\GerenciadorEvento.h"

#include "Fase\FlorestaBranca.h"
#include "Fase\FlorestaVermelha.h"
#include "Estado\MaquinaEstado.h"

namespace Fantasy {

	class Principal {
	private:
		Gerenciador::GerenciadorGrafico* pGrafico;
		Gerenciador::GerenciadorEvento* pEvento;
		Estado::MaquinaEstado maquinaEstado;
		//Fase::Fase* fase;

		//void criarFase();
	public:
		Principal();
		~Principal();
		void executar();
	};
}