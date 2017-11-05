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
public:
	Usuarios(float id);
	~Usuarios();
	Tipo getTipo();
	float getTiempo();
	
};