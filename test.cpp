#include "./class/Distributios.cpp"


///Generador de numeros de numeros pseudoaleatorios
int main(int argc, char const *argv[]){
	Distributios d;
	

	std::cout<<"exponencial " << d.exponencial() << " s"<< std::endl;
 
	std::cout<<"getTiempoRegistro " << d.getTiempoRegistro() << " s"<< std::endl;
	std::cout<<"getMaletas " << d.getMaletas() << " s"<< std::endl;
	std::cout<<"getPeligrosidad " << d.getPeligrosidad() << " s"<< std::endl;

	std::cout<<"getTiempoChecking " << d.getTiempoChecking() << " s"<< std::endl;
	std::cout<<"getTiempoControl " << d.getTiempoControl() << " s"<< std::endl;
	std::cout<<"getTiempoCambiarZona " << d.getTiempoCambiarZona() << " s"<< std::endl;
	
	//funciones que siguen una uniforme x,y
	std::cout<<"getTiempoPrensa " << d.getTiempoPrensa(0.22) << " s"<< std::endl;
	std::cout<<"getTiempoPerfumeria " << d.getTiempoPerfumeria(0.22) << " s"<< std::endl;
	std::cout<<"getTiempoSouvenirs " << d.getTiempoSouvenirs(0.22) << " s"<< std::endl;
	std::cout<<"getTiempoCafeteria " << d.getTiempoCafeteria(0.22) << " s"<< std::endl;
	//funciones que siguen una normal
	std::cout<<"getTiempoPlanVuelo " << d.getTiempoPlanVuelo() << " s"<< std::endl;
	//funciones que siguen una exponencial
	std::cout<<"getTiempoEmbarque " << d.getTiempoEmbarque() << " s"<< std::endl;
	std::cout<<"getTiempoRecogidaMaletas " << d.getTiempoRecogidaMaletas(0.22) << " s"<< std::endl;
	//funciones que siguen una uniforme x,y
	std::cout<<"getTiempoRegistroPersonal " << d.getTiempoRegistroPersonal(0.22) << " s"<< std::endl;
	//funciones que siguen una normal
	std::cout<<"getTiempoVestuario " << d.getTiempoVestuario() << " s"<< std::endl;
	std::cout<<"getTiempoCafeteria " << d.getTiempoCafeteria() << " s"<< std::endl;
	std::cout<<"getTiempoComedor " << d.getTiempoComedor() << " s"<< std::endl;

}