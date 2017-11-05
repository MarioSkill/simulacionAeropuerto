
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

public:
	Zonas(Tipo usuario);
	~Zonas();
	float getTiempo();

};
