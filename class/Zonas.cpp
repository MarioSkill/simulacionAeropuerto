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
			tiempoDutyFree += d.getTiempoPrensa(u.aleatorio()) + d.getTiempoCambiarZona(); 
		}else if (visitoPerfumeria < proVisitarPerfumeria ){
			tiempoDutyFree += d.getTiempoPerfumeria(u.aleatorio()) + d.getTiempoCambiarZona();  
		}else if (visitoSouvenirs < proVisitarSouveniers ){
			tiempoDutyFree += d.getTiempoSouvenirs(u.aleatorio()) + d.getTiempoCambiarZona(); 
		}else if (visitoCafeteria < proVisitarCafeteria){
			tiempoDutyFree += d.getTiempoCafeteria(u.aleatorio()) + d.getTiempoCambiarZona(); 
		}

	 	tiempo = 
	 		d.getTiempoRegistro() + d.getTiempoCambiarZona() + 
	 		d.getTiempoChecking() + d.getTiempoCambiarZona() + 
	 		d.getTiempoControl() + d.getTiempoCambiarZona() +
	 		d.getTiempoPlanVuelo() + d.getTiempoCambiarZona() + 
	 		tiempoDutyFree+
	 		d.getTiempoEmbarque()+d.getTiempoCambiarZona();
	 break; 
	 case Tipo::OPERARIOS:
		//	o Registro de personal o Vestuario o Comedor
	 	visitoComedor= u.aleatorio();

	 	if (visitoComedor < proVisitarComedor){
	 		tiempoComedor+=d.getTiempoComedor() + d.getTiempoCambiarZona();
	 	}else{
	 		tiempoComedor+=d.getTiempoCafeteria(u.aleatorio()) + d.getTiempoCambiarZona();
	 	}

	 	tiempo = 
	 		d.getTiempoRegistroPersonal(u.aleatorio()) + d.getTiempoCambiarZona()+
	 		d.getTiempoVestuario() + d.getTiempoCambiarZona()+ 
	 		tiempoComedor +d.getTiempoCambiarZona();
	 break; 
	 case Tipo::U_ENTRANTES:
	 //	o Embarque	o Cintas de Equipaje	o DutyFree	o Control
		visitoPrensa = u.aleatorio();
		visitoPerfumeria = u.aleatorio();
		visitoSouvenirs = u.aleatorio();
		visitoCafeteria = u.aleatorio();

		if (visitoPrensa <  proVisitarPrensa ){
			tiempoDutyFree += d.getTiempoPrensa(u.aleatorio()) + d.getTiempoCambiarZona(); 
		}else if (visitoPerfumeria < proVisitarPerfumeria ){
			tiempoDutyFree += d.getTiempoPerfumeria(u.aleatorio()) + d.getTiempoCambiarZona();  
		}else if (visitoSouvenirs < proVisitarSouveniers ){
			tiempoDutyFree += d.getTiempoSouvenirs(u.aleatorio()) + d.getTiempoCambiarZona(); 
		}else if (visitoCafeteria < proVisitarCafeteria){
			tiempoDutyFree += d.getTiempoCafeteria(u.aleatorio()) + d.getTiempoCambiarZona(); 
		}

	 	tiempo = 
	 		d.getTiempoEmbarque()+ d.getTiempoCambiarZona()+
	 		d.getTiempoRecogidaMaletas(d.getMaletas()) + d.getTiempoCambiarZona()+
	 		tiempoDutyFree +
	 		d.getTiempoControl()+d.getTiempoCambiarZona();

	 break; 
	 case Tipo::U_SALIENTES: 
	 	//	o Recepción	o Check-in	o Control	o DutyFree	o Pasarela
		 	visitoPrensa = u.aleatorio();
			visitoPerfumeria = u.aleatorio();
			visitoSouvenirs = u.aleatorio();
			visitoCafeteria = u.aleatorio();

			if (visitoPrensa <  proVisitarPrensa ){
				tiempoDutyFree += d.getTiempoPrensa(u.aleatorio()) + d.getTiempoCambiarZona(); 
			}else if (visitoPerfumeria < proVisitarPerfumeria ){
				tiempoDutyFree += d.getTiempoPerfumeria(u.aleatorio()) + d.getTiempoCambiarZona();  
			}else if (visitoSouvenirs < proVisitarSouveniers ){
				tiempoDutyFree += d.getTiempoSouvenirs(u.aleatorio()) + d.getTiempoCambiarZona(); 
			}else if (visitoCafeteria < proVisitarCafeteria){
				tiempoDutyFree += d.getTiempoCafeteria(u.aleatorio()) + d.getTiempoCambiarZona(); 
			}

		 	tiempo = 
			 	d.getTiempoRegistro() + d.getTiempoCambiarZona() + 
			 	d.getTiempoChecking() + d.getTiempoCambiarZona() +
			 	d.getTiempoControl()+d.getTiempoCambiarZona()+
		 		tiempoDutyFree+
		 		d.getTiempoEmbarque()+d.getTiempoCambiarZona();
	 	 break; 
	}
}


float Zonas::getTiempo(){
	return tiempo;
}