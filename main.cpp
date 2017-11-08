#include <string>
#include "./class/Usuarios.h"
// int vectorToCSV(std::vector<Usuarios> v, std::string file);
std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
	size_t start_pos = 0;
	while((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}
int vectorToCSV(std::vector<Usuarios> v, std::string file){
	std::ofstream myfile (file);
	std::string header ="CLASE;TIEMPO;ZONA_RECEPCION;ZONA_CHECKIN;ZONA_CONTROL;ZONA_DUTYFREE;ZONA_OFICINAS;ZONA_PASARELA;ZONA_CINTA;ZONA_REGISTRO;ZONA_VESTURIO;ZONA_COMEDOR;ANDANDO\n";

	
	for (std::vector<Usuarios>::iterator i = v.begin(); i != v.end(); ++i) {

		switch (i->getTipo()) {  
			case Tipo::TRIPULACION: 
			header+="TRIPULACION;"+std::to_string( (i->getTiempo()/(60.0F)) )+";";
			break;  
			case Tipo::OPERARIOS:
			header+="OPERARIOS;"+std::to_string( (i->getTiempo()/(60.0F)) )+";";

			break; 
			case Tipo::U_ENTRANTES:
			header+="U_ENTRANTES;"+std::to_string( (i->getTiempo()/(60.0F)) )+";";
			break; 
			case Tipo::U_SALIENTES: 
			header+="U_SALIENTES;"+std::to_string( (i->getTiempo()/(60.0F)) )+";";
			break; 
		}

		header+=std::to_string(i-> getTiempo_zona_recepcion()/(60.F) ) +";";
		header+=std::to_string(i-> getTiempo_zona_checkin()/(60.F) ) +";";
		header+=std::to_string(i-> getTiempo_zona_control()/(60.F) ) +";";
		header+=std::to_string(i-> getTiempo_zona_dutyfree()/(60.F) ) +";";
		header+=std::to_string(i-> getTiempo_zona_oficinas()/(60.F) ) +";";
		header+=std::to_string(i-> getTiempo_zona_pasarela()/(60.F) ) +";";
		header+=std::to_string(i-> getTiempo_zona_cinta()/(60.F) ) +";";
		header+=std::to_string(i-> getTiempo_zona_registro()/(60.F) ) +";";
		header+=std::to_string(i-> getTiempo_zona_vesturio()/(60.F) ) +";";
		header+=std::to_string(i-> getTiempo_zona_comedor()/(60.F) ) +";";
		header+=std::to_string(i-> getTiempo_cambiandoZona()/(60.F) ) +"\n";



	} 
	header = ReplaceAll(header, std::string("."), std::string(","));
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

	float zona_recepcion = 0.0F;
	int zona_recepcion_c=0;
	float zona_checkin = 0.0F;
	int zona_checkin_c=0;
	float zona_control = 0.0F;
	int zona_control_c=0;
	float zona_dutyfree = 0.0F;
	int zona_dutyfree_c=0;
	float zona_oficinas = 0.0F;
	int zona_oficinas_c=0;
	float zona_pasarela = 0.0F;
	int zona_pasarela_c=0;
	float zona_cinta = 0.0F;
	int zona_cinta_c=0;
	float zona_registro = 0.0F;
	int zona_registro_c=0;
	float zona_vesturio = 0.0F;
	int zona_vesturio_c=0;
	float zona_comedor = 0.0F;
	int zona_comedor_c=0;
	float cambiandoZona = 0.0F;
	int cambiandoZona_c=0;

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

		if (i-> getTiempo_zona_recepcion()> 0) zona_recepcion_c++;
		if (i->getTiempo_zona_checkin() > 0)  zona_checkin_c++;
		if (i->getTiempo_zona_control() > 0)  zona_control_c++;
		if (i->getTiempo_zona_dutyfree() > 0)  zona_dutyfree_c++;
		if (i->getTiempo_zona_oficinas() > 0)  zona_oficinas_c++;
		if (i->getTiempo_zona_pasarela() > 0)  zona_pasarela_c++;
		if (i->getTiempo_zona_cinta() > 0)  zona_cinta_c++;
		if (i->getTiempo_zona_registro() > 0)  zona_registro_c++;
		if (i->getTiempo_zona_vesturio() > 0)  zona_vesturio_c++;
		if (i->getTiempo_zona_comedor() > 0)  zona_comedor_c++;
		if (i->getTiempo_cambiandoZona() > 0) cambiandoZona_c++;

		zona_recepcion +=i-> getTiempo_zona_recepcion();
		zona_checkin +=i-> getTiempo_zona_checkin();
		zona_control +=i-> getTiempo_zona_control();
		zona_dutyfree +=i-> getTiempo_zona_dutyfree();
		zona_oficinas +=i-> getTiempo_zona_oficinas();
		zona_pasarela +=i-> getTiempo_zona_pasarela();
		zona_cinta +=i-> getTiempo_zona_cinta();
		zona_registro +=i-> getTiempo_zona_registro();
		zona_vesturio +=i-> getTiempo_zona_vesturio();
		zona_comedor +=i-> getTiempo_zona_comedor();
		cambiandoZona +=i-> getTiempo_cambiandoZona();



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

	std::cout<<"-------------------------------- Mas informacion ------------------------"<<std::endl;

	std::cout<<"Tiempo Medio zona_recepcion: " << (zona_recepcion/zona_recepcion_c)/(60.0F) <<  " Minutos"<<std::endl;
	std::cout<<"Tiempo Medio zona_checkin: " << (zona_checkin/zona_checkin_c)/(60.0F) <<  " Minutos"<<std::endl;
	std::cout<<"Tiempo Medio zona_control: " << (zona_control/zona_control_c)/(60.0F) <<  " Minutos"<<std::endl;
	std::cout<<"Tiempo Medio zona_dutyfree: " << (zona_dutyfree/zona_dutyfree_c)/(60.0F) <<  " Minutos"<<std::endl;
	std::cout<<"Tiempo Medio zona_oficinas: " << (zona_oficinas/zona_oficinas_c)/(60.0F) <<  " Minutos"<<std::endl;
	std::cout<<"Tiempo Medio zona_pasarela: " << (zona_pasarela/zona_pasarela_c)/(60.0F) <<  " Minutos"<<std::endl;
	std::cout<<"Tiempo Medio zona_cinta: " << (zona_cinta/zona_cinta_c)/(60.0F) <<  " Minutos"<<std::endl;
	std::cout<<"Tiempo Medio zona_registro: " << (zona_registro/zona_registro_c)/(60.0F) <<  " Minutos"<<std::endl;
	std::cout<<"Tiempo Medio zona_vesturio: " << (zona_vesturio/zona_vesturio_c)/(60.0F) <<  " Minutos"<<std::endl;
	std::cout<<"Tiempo Medio zona_comedor: " << (zona_comedor/zona_comedor_c)/(60.0F) <<  " Minutos"<<std::endl;
	std::cout<<"Tiempo Medio cambiando Zona: " << (cambiandoZona/cambiandoZona_c)/(60.0F) <<  " Minutos"<<std::endl;


	std::string file_name ="./Resultados/Aeropuerto.csv";
	std::cout<<"File saved: "<<file_name<<std::endl;
	vectorToCSV(usuarios,file_name);

	file_name ="./Resultados/MediayDesviacion.csv";
	std::cout<<"File saved: "<<file_name<<std::endl;
	std::ofstream myfile (file_name);
	std::string header ="CLASE;MEDIA;SD\n";
	header+="TRIPULACION;"+std::to_string(sumTiemp1)+";"+std::to_string(sd1)+"\n";
	header+="OPERARIOS;"+std::to_string(sumTiemp2)+";"+std::to_string(sd2)+"\n";
	header+="U_ENTRANTES;"+std::to_string(sumTiemp3)+";"+std::to_string(sd3)+"\n";
	header+="U_SALIENTES;"+std::to_string(sumTiemp4)+";"+std::to_string(sd4)+"\n";

	header = ReplaceAll(header, std::string("."), std::string(","));
	if (myfile.is_open()){
		myfile << header;
		myfile.close();
	}
} 


