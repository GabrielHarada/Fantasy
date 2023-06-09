#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "..\header\Gerenciador\GerenciadorGrafico.h"
#include "..\header\Gerenciador\GerenciadorEvento.h"

#include "Fase\FlorestaBranca.h"
#include "Fase\FlorestaVermelha.h"

#include "Gerenciador\GerenciadorEstado.h"

namespace Fantasy {

	class Principal {
	private:
		Gerenciador::GerenciadorGrafico* pGrafico;
		Gerenciador::GerenciadorEvento* pEvento;
		Gerenciador::GerenciadorEstado* pGerenciadorEstado;

		void inicializa();
	public:
		Principal();
		~Principal();
		void executar();
	};
}