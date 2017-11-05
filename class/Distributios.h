#include <math.h>       /* sqrt */
#include <algorithm>    // std::min_element, std::max_element
#include <limits>
#include <stdlib.h>     /* abs */
#include "Utils.h"

class Distributios {
private:
	Utils u;
public:
	Distributios();
	~Distributios();
	float normInv(float p, float mu, float sigma);
	float exponencial();
	float uniforme(float x,int min, int max);

	float getTiempoRegistro();
	float getMaletas();
	float getPeligrosidad();

	float getTiempoChecking();
	float getTiempoControl();
	float getTiempoCambiarZona();
	
	//funciones que siguen una uniforme x,y
	float getTiempoPrensa(float x);
	float getTiempoPerfumeria(float x);
	float getTiempoSouvenirs(float x);
	float getTiempoCafeteria(float x);
	//funciones que siguen una normal
	float getTiempoPlanVuelo();
	//funciones que siguen una exponencial
	float getTiempoEmbarque();
	float getTiempoRecogidaMaletas(float x);
	//funciones que siguen una uniforme x,y
	float getTiempoRegistroPersonal(float x);
	//funciones que siguen una normal
	float getTiempoVestuario();
	float getTiempoCafeteria();
	float getTiempoComedor();
	

	
};