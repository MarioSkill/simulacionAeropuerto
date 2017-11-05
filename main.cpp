
#include "./class/Usuarios.h"


///Generador de numeros de numeros pseudoaleatorios
int main(int argc, char const *argv[]){
    
	Utils u;
	std::vector<Usuarios> usuarios;

	std::vector<float> clases = u.generador(5000);
	//Los usuarios llegan con una distribucion normal de 60,2

	//Transito entre zonas es una exponencia 240.
	//Operarios registrarse en los tornos de persobnal U(120s, 150s)
	//Operarios media en los vestuarios 15 minutos => N(900s, 120s)
	//50 % operarios: 30 minutos para comida.comedor jornada completa. => N(1800, 240s)
	//50% operarios: 10 minutos desayuno. => N(600s, 90s) 
	//numero maletas usuario: N(0.8,0.15)
	//Peligrosidad: U(1,2); 
  
	for (std::vector<float>::iterator i = clases.begin(); i != clases.end(); ++i) {

		Usuarios user(*i);
		usuarios.push_back(user);
	} 
	int c_tripulacion=0,c_operarios=0,c_entrantes=0,c_salientes=0;
	unsigned long long sumTiemp1=0,sumTiemp2=0,sumTiemp3=0,sumTiemp4=0;


	for (std::vector<Usuarios>::iterator i = usuarios.begin(); i != usuarios.end(); ++i) {

		switch (i->getTipo()) {  
	         case Tipo::TRIPULACION: 
	         	//std::cout<<"tiempo: "<<i->getTiempo()<<std::endl;
		         sumTiemp1+=(i->getTiempo()/(60));
		         c_tripulacion++;
	         break;  
	         case Tipo::OPERARIOS:
		         sumTiemp2+=(i->getTiempo()/(60));
		         c_operarios++;
	         break; 
	         case Tipo::U_ENTRANTES:
		         sumTiemp3+=(i->getTiempo()/(60));
		         c_entrantes++;
	         break; 
	         case Tipo::U_SALIENTES: 
		         sumTiemp4+=(i->getTiempo()/(60));
		         c_salientes++;
	         break; 
	    }
	} 
 
	std::cout<<"Tiempo Medio Tripulacion: "<<(sumTiemp1/c_tripulacion)<<" Minutos..."<<std::endl;
	std::cout<<"Tiempo Medio Operarios: "<<(sumTiemp2/c_operarios)<<" Minutos..."<<std::endl;
	std::cout<<"Tiempo Medio U_ENTRANTES: "<<(sumTiemp3/c_entrantes)<<" Minutos..."<<std::endl;
	std::cout<<"Tiempo Medio U_SALIENTES: "<<(sumTiemp4/c_salientes)<<" Minutos..."<<std::endl;
 } 
 