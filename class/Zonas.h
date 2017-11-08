
#include "Distributios.h"
enum class Tipo { TRIPULACION, OPERARIOS, U_ENTRANTES,U_SALIENTES };

class Zonas {
private:
	Utils u;
	Distributios d;
	int numZonasVisitadas;
	float tiempo;
	
	float proVisitarPrensa;	
	float proVisitarPerfumeria;	
	float proVisitarSouveniers;	
	float proVisitarCafeteria;	
	float proVisitarComedor;

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
	Zonas(Tipo usuario);
	~Zonas();
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