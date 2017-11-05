#include "Usuarios.h"

Usuarios::Usuarios(float id){

	float l1 =(float)(1.0F/100);
	float l2 = (float)(2.0F/100);
	float l3 = (float)(50.0F/100);

	if (id < l1){
		tipo = Tipo::TRIPULACION;
	}else if ( id < l2 ){
		tipo = Tipo::OPERARIOS;
	}else{
		if (id < (l3) ){
			tipo = Tipo::U_ENTRANTES;
		} else {
			tipo = Tipo::U_SALIENTES;
		}
	}
	Zonas z(tipo);
	tiempo = z.getTiempo();
}
Usuarios::~Usuarios(){}
Tipo Usuarios::getTipo(){
    return tipo;
}
float Usuarios::getTiempo(){
	return tiempo;
}