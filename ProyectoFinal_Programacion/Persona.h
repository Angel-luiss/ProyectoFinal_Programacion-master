#pragma once
#include<iostream>
using namespace std;

class Persona{
protected: string nombres, apellidos, direccion, fecha_nacimiento;
		 int telefono = 0;
		 bool genero = true;
		 
public:
	Persona() {
	}
	Persona(string nom, string ape, string dir,string fn, int tel, bool gen) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		genero = gen;
		fecha_nacimiento = fn;
		

	}

};

