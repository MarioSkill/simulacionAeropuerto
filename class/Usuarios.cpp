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
	zona_recepcion = z.getTiempo_zona_recepcion();
	zona_checkin = z.getTiempo_zona_checkin();
	zona_control = z.getTiempo_zona_control();
	zona_dutyfree = z.getTiempo_zona_dutyfree();
	zona_oficinas = z.getTiempo_zona_oficinas();
	zona_pasarela = z.getTiempo_zona_pasarela();
	zona_cinta = z.getTiempo_zona_cinta();
	zona_registro = z.getTiempo_zona_registro();
	zona_vesturio = z.getTiempo_zona_vesturio();
	zona_comedor = z.getTiempo_zona_comedor();
	cambiandoZona = z.getTiempo_cambiandoZona();


}
Usuarios::~Usuarios(){}
Tipo Usuarios::getTipo(){
    return tipo;
}
float Usuarios::getTiempo(){
	return tiempo;
}


float  Usuarios::getTiempo_zona_recepcion(){
	return zona_recepcion;
}
float  Usuarios::getTiempo_zona_checkin(){
	return zona_checkin;
}
float  Usuarios::getTiempo_zona_control(){
	return zona_control;
}
float  Usuarios::getTiempo_zona_dutyfree(){
	return zona_dutyfree;
}
float  Usuarios::getTiempo_zona_oficinas(){
	return zona_oficinas;
}
float  Usuarios::getTiempo_zona_pasarela(){
	return zona_pasarela;
}
float  Usuarios::getTiempo_zona_cinta(){
	return zona_cinta;
}
float  Usuarios::getTiempo_zona_registro(){
	return zona_registro;
}
float  Usuarios::getTiempo_zona_vesturio(){
	return zona_vesturio;
}
float  Usuarios::getTiempo_zona_comedor(){
	return zona_comedor;
}
float  Usuarios::getTiempo_cambiandoZona(){
	return cambiandoZona;
}
