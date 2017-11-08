#include <iostream>
#include <string>
#include "Zonas.h"

/*
	Número de pasajeros a simular: 5000;

	1%  Miembros de la tripulacion => 1% de 5000 = 50
	1%  Operarios de las instalaciones 1% de 5000 = 50
	98% Pasajeros; 98% de 5000 = 4900
		* 50% Entrantes;
		* 50% Salientes;
*/



class Usuarios {
private: 
	Tipo tipo;
	float tiempo;
	float zona_recepcion;
	float zona_checkin;
	float zona_control;
	float zona_dutyfree;
	float zona_oficinas;
	float zona_pasarela;
	float zona_cinta;
	float zona_registro;
	float zona_vesturio;
	float zona_comedor;
	float cambiandoZona;
	
public:
	Usuarios(float id);
	~Usuarios();

	Tipo getTipo();

	float getTiempo();
	float getTiempo_zona_recepcion();
	float getTiempo_zona_checkin();
	float getTiempo_zona_control();
	float getTiempo_zona_dutyfree();
	float getTiempo_zona_oficinas();
	float getTiempo_zona_pasarela();
	float getTiempo_zona_cinta();
	float getTiempo_zona_registro();
	float getTiempo_zona_vesturio();
	float getTiempo_zona_comedor();
	float getTiempo_cambiandoZona();
};