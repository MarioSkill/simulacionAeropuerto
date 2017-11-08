#include "Zonas.h"

/*
>> PASAJERO SALIENTE
	o Recepción
	o Check-in
	o Control
	o DutyFree
	o Pasarela
>> PASAJERO ENTRANTE
	o Embarque
	o Cintas de Equipaje
	o DutyFree
	o Control
>> TRIPULACION
	o Recepción
	o Check-in
	o Control
	o Oficinas
	o DutyFree
	o Pasarela
>> OPERARIO
	o Registro de personal
	o Vestuario
	o Comedor
*/

Zonas::~Zonas(){}
Zonas::Zonas(Tipo usuario){
	
	proVisitarPrensa = 0.3F;	
	proVisitarPerfumeria = 0.1F;	
	proVisitarSouveniers = 0.2F;	
	proVisitarCafeteria = 0.4F;	
	proVisitarComedor=0.5F;

	numZonasVisitadas=0;

	zona_recepcion = 0.0F;
	zona_checkin = 0.0F;
	zona_control = 0.0F;
	zona_dutyfree = 0.0F;
	zona_oficinas = 0.0F;
	zona_pasarela = 0.0F;
	zona_cinta = 0.0F;
	zona_registro = 0.0F;
	zona_vesturio = 0.0F;
	zona_comedor = 0.0F;



	tiempo = 0;
	float visitoPrensa=-1.0F,visitoPerfumeria=-1.0F,visitoSouvenirs=-1.0F,visitoCafeteria=-1.0F,visitoComedor=-1.0F;
	float tiempoDutyFree=0.0F;
	float tiempoComedor=0.0F;

	switch (usuario) {
		case Tipo::TRIPULACION: 

		visitoPrensa = u.aleatorio();
		visitoPerfumeria = u.aleatorio();
		visitoSouvenirs = u.aleatorio();
		visitoCafeteria = u.aleatorio();

		if (visitoPrensa <  proVisitarPrensa ){
			tiempoDutyFree += d.getTiempoPrensa(u.aleatorio()); 
		}else if (visitoPerfumeria < proVisitarPerfumeria ){
			tiempoDutyFree += d.getTiempoPerfumeria(u.aleatorio());  
		}else if (visitoSouvenirs < proVisitarSouveniers ){
			tiempoDutyFree += d.getTiempoSouvenirs(u.aleatorio()); 
		}else if (visitoCafeteria < proVisitarCafeteria){
			tiempoDutyFree += d.getTiempoCafeteria(u.aleatorio()); 
		}

		if (tiempoDutyFree >0 ){
			cambiandoZona =d.getTiempoCambiarZona();
		}else{
			cambiandoZona =0;
		}

		zona_dutyfree=tiempoDutyFree;
		zona_recepcion=d.getTiempoRegistro();
		zona_checkin=d.getTiempoChecking();
		zona_control = d.getTiempoControl();
		zona_oficinas= d.getTiempoPlanVuelo();
		zona_pasarela= d.getTiempoEmbarque();
		cambiandoZona += d.getTiempoCambiarZona()+d.getTiempoCambiarZona() + d.getTiempoCambiarZona() + d.getTiempoCambiarZona()+d.getTiempoCambiarZona();

		tiempo = 
		zona_recepcion +   
		zona_checkin + 
		zona_control + 
		zona_oficinas +
		zona_pasarela+
		tiempoDutyFree+
		cambiandoZona;

		break; 
		case Tipo::OPERARIOS:
		//	o Registro de personal o Vestuario o Comedor
		visitoComedor= u.aleatorio();

		if (visitoComedor < proVisitarComedor){
			tiempoComedor+=d.getTiempoComedor();
		}else{
			tiempoComedor+=d.getTiempoCafeteria(u.aleatorio());
		}

		if (tiempoComedor >0 ){
			cambiandoZona =d.getTiempoCambiarZona();
		}else{
			cambiandoZona =0;
		}


		cambiandoZona = d.getTiempoCambiarZona()+d.getTiempoCambiarZona() + d.getTiempoCambiarZona();
		zona_registro= d.getTiempoRegistroPersonal(u.aleatorio());
		zona_vesturio= d.getTiempoVestuario();
		zona_comedor=tiempoComedor;

		tiempo = 
			cambiandoZona +
			zona_registro + 
			zona_vesturio + 
			zona_comedor;
		break; 
		case Tipo::U_ENTRANTES:
	 //	o Embarque	o Cintas de Equipaje	o DutyFree	o Control
		visitoPrensa = u.aleatorio();
		visitoPerfumeria = u.aleatorio();
		visitoSouvenirs = u.aleatorio();
		visitoCafeteria = u.aleatorio();

	if (visitoPrensa <  proVisitarPrensa ){
			tiempoDutyFree += d.getTiempoPrensa(u.aleatorio()); 
		}else if (visitoPerfumeria < proVisitarPerfumeria ){
			tiempoDutyFree += d.getTiempoPerfumeria(u.aleatorio());  
		}else if (visitoSouvenirs < proVisitarSouveniers ){
			tiempoDutyFree += d.getTiempoSouvenirs(u.aleatorio()); 
		}else if (visitoCafeteria < proVisitarCafeteria){
			tiempoDutyFree += d.getTiempoCafeteria(u.aleatorio()); 
		}

		if (tiempoDutyFree >0 ){
			cambiandoZona =d.getTiempoCambiarZona();
		}else{
			cambiandoZona =0;
		}

		zona_dutyfree=tiempoDutyFree;
		zona_pasarela =d.getTiempoEmbarque();
		zona_cinta=d.getTiempoRecogidaMaletas(d.getMaletas());
		zona_control=d.getTiempoControl();
		cambiandoZona += d.getTiempoCambiarZona()+d.getTiempoCambiarZona() + d.getTiempoCambiarZona();

		tiempo = 
		tiempoDutyFree+
		zona_pasarela+
		zona_cinta+
		zona_control+
		cambiandoZona;

		break; 
		case Tipo::U_SALIENTES: 
	 	//	o Recepción	o Check-in	o Control	o DutyFree	o Pasarela
		visitoPrensa = u.aleatorio();
		visitoPerfumeria = u.aleatorio();
		visitoSouvenirs = u.aleatorio();
		visitoCafeteria = u.aleatorio();

		if (visitoPrensa <  proVisitarPrensa ){
			tiempoDutyFree += d.getTiempoPrensa(u.aleatorio()); 
		}else if (visitoPerfumeria < proVisitarPerfumeria ){
			tiempoDutyFree += d.getTiempoPerfumeria(u.aleatorio());  
		}else if (visitoSouvenirs < proVisitarSouveniers ){
			tiempoDutyFree += d.getTiempoSouvenirs(u.aleatorio()); 
		}else if (visitoCafeteria < proVisitarCafeteria){
			tiempoDutyFree += d.getTiempoCafeteria(u.aleatorio()); 
		}

		if (tiempoDutyFree >0 ){
			cambiandoZona =d.getTiempoCambiarZona();
		}else{
			cambiandoZona =0;
		}


		zona_dutyfree=tiempoDutyFree;
		zona_recepcion=d.getTiempoRegistro();
		zona_checkin=d.getTiempoChecking();
		zona_control = d.getTiempoControl();
		zona_pasarela= d.getTiempoEmbarque();
		cambiandoZona += d.getTiempoCambiarZona()+d.getTiempoCambiarZona() + d.getTiempoCambiarZona() + d.getTiempoCambiarZona()+d.getTiempoCambiarZona();

		tiempo = 
		zona_recepcion +   
		zona_checkin + 
		zona_control + 
		zona_pasarela+
		tiempoDutyFree+
		cambiandoZona;
		break; 
	}
}


float Zonas::getTiempo(){
	return tiempo;
}


float  Zonas::getTiempo_zona_recepcion(){
	return zona_recepcion;
}
float  Zonas::getTiempo_zona_checkin(){
	return zona_checkin;
}
float  Zonas::getTiempo_zona_control(){
	return zona_control;
}
float  Zonas::getTiempo_zona_dutyfree(){
	return zona_dutyfree;
}
float  Zonas::getTiempo_zona_oficinas(){
	return zona_oficinas;
}
float  Zonas::getTiempo_zona_pasarela(){
	return zona_pasarela;
}
float  Zonas::getTiempo_zona_cinta(){
	return zona_cinta;
}
float  Zonas::getTiempo_zona_registro(){
	return zona_registro;
}
float  Zonas::getTiempo_zona_vesturio(){
	return zona_vesturio;
}
float  Zonas::getTiempo_zona_comedor(){
	return zona_comedor;
}
float  Zonas::getTiempo_cambiandoZona(){
	return cambiandoZona;
}
