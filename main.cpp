#include <string>
#include "./class/Usuarios.h"
// int vectorToCSV(std::vector<Usuarios> v, std::string file);
int vectorToCSV(std::vector<Usuarios> v, std::string file){
	std::ofstream myfile (file);
	std::string header ="CLASE;TIEMPO\n";
	
	for (std::vector<Usuarios>::iterator i = v.begin(); i != v.end(); ++i) {

		switch (i->getTipo()) {  
	         case Tipo::TRIPULACION: 
	         	header+="TRIPULACION;"+std::to_string( (i->getTiempo()/(60.0F)) )+"\n";
	         break;  
	         case Tipo::OPERARIOS:
	         	header+="OPERARIOS;"+std::to_string( (i->getTiempo()/(60.0F)) )+"\n";

	         break; 
	         case Tipo::U_ENTRANTES:
	         	header+="U_ENTRANTES;"+std::to_string( (i->getTiempo()/(60.0F)) )+"\n";
	         break; 
	         case Tipo::U_SALIENTES: 
	         	header+="U_SALIENTES;"+std::to_string( (i->getTiempo()/(60.0F)) )+"\n";
	         break; 
	    }
	} 
	
	if (myfile.is_open()){
		myfile << header;
		myfile.close();
	}
	return 0;

}

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
	float c_tripulacion=0.0F,c_operarios=0.0F,c_entrantes=0.0F,c_salientes=0.0F;
	float sumTiemp1=0,sumTiemp2=0,sumTiemp3=0,sumTiemp4=0;
	double sd1,sd2,sd3,sd4;

	for (std::vector<Usuarios>::iterator i = usuarios.begin(); i != usuarios.end(); ++i) {

		switch (i->getTipo()) {  
	         case Tipo::TRIPULACION: 
	         	//std::cout<<"tiempo: "<<i->getTiempo()<<std::endl;
		         sumTiemp1+=(i->getTiempo()/(60.0F));
		         c_tripulacion++;
	         break;  
	         case Tipo::OPERARIOS:
		         sumTiemp2+=(i->getTiempo()/(60.0F));
		         c_operarios++;
	         break; 
	         case Tipo::U_ENTRANTES:
		         sumTiemp3+=(i->getTiempo()/(60.0F));
		         c_entrantes++;
	         break; 
	         case Tipo::U_SALIENTES: 
		         sumTiemp4+=(i->getTiempo()/(60.0F));
		         c_salientes++;
	         break; 
	    }
	} 

	sumTiemp1=(float)(sumTiemp1/c_tripulacion);
	sumTiemp2=(float)(sumTiemp2/c_operarios);
	sumTiemp3=(float)(sumTiemp3/c_entrantes);
	sumTiemp4=(float)(sumTiemp4/c_salientes);

	for (std::vector<Usuarios>::iterator i = usuarios.begin(); i != usuarios.end(); ++i) {

		switch (i->getTipo()) {  
	         case Tipo::TRIPULACION: 
	         	sd1 += pow(((i->getTiempo()/(60.0F))-sumTiemp1),2);
	         break;  
	         case Tipo::OPERARIOS:
	         	sd2 += pow(((i->getTiempo()/(60.0F))-sumTiemp2),2);
	         break; 
	         case Tipo::U_ENTRANTES:
	         	sd3 += pow(((i->getTiempo()/(60.0F))-sumTiemp3),2);
	         break; 
	         case Tipo::U_SALIENTES: 
	         	sd4 += pow(((i->getTiempo()/(60.0F))-sumTiemp4),2);
	         break; 
	    }
	} 
 	sd1 = sqrt(sd1/(c_tripulacion-1.0F));
 	sd2 = sqrt(sd2/(c_operarios-1.0F));
 	sd3 = sqrt(sd3/(c_entrantes-1.0F));
 	sd4 = sqrt(sd4/(c_salientes-1.0F));

	std::cout<<"Tiempo Medio Tripulacion: "<<sumTiemp1<<" SD: "<<sd1 <<" Minutos..."<<std::endl;
	std::cout<<"Tiempo Medio Operarios: "<<sumTiemp2<<" SD: "<<sd2 <<" Minutos..."<<std::endl;
	std::cout<<"Tiempo Medio U_ENTRANTES: "<<sumTiemp3<<" SD: "<<sd3 <<" Minutos..."<<std::endl;
	std::cout<<"Tiempo Medio U_SALIENTES: "<<sumTiemp4<<" SD: "<<sd4 <<" Minutos..."<<std::endl;


	std::string file_name ="./Resultados/Aeropuerto.csv";
    std::cout<<"File saved: "<<file_name<<std::endl;
    vectorToCSV(usuarios,file_name);
 } 
 

