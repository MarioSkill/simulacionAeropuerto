#include "Utils.h"

Utils::Utils(){}
Utils::~Utils(){}

std::vector<float> Utils::generador(int n){
	//,float m,float sd
	std::vector<float> v;
	time_t timer;
	time(&timer);
	std::default_random_engine generator(timer);
	std::uniform_real_distribution<double> distribution(0.0,1.0);

	for (int i = 0; i < n; ++i){

		float aux = distribution(generator);
		v.push_back(aux);
	}
	return v;
}

//Uniforme (x,y); 
float Utils::aleatorio(){

	std::default_random_engine generator(rand()+10000);
	std::uniform_real_distribution<double> distribution(0.0,1.0);
	float aux = distribution(generator);
    return aux;
}

