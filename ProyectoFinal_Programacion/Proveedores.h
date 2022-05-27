#pragma once
#include<iostream>
#include "Persona.h"

using namespace std;

class Proveedores : public Persona{
private: int idproveedores = 0;

public: string nit;

public: 
	//Proveedores() {
	//}
	/*a y g son solo variables que no tienen proposito, solo estan ahi porque la clase persona las necesita instanciadas
	ademas el nombre del proveedor aqui lo estoy considerando como nombre de la clase persona*/
	//Proveedores(int idpro,string nom,string n, string dir, int tel,string a,int g) :Persona(nom,a,dir,g,tel) {
		//idproveedores = idpro;
		//nit = n;
	//}



};

